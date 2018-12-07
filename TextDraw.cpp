#include "TextDraw.hpp"
#include <cassert>
#include <QtGui/qfontmetrics.h>
#include <QtGui/qpainter.h>
#include <algorithm>
#include <QtCore/qtextstream.h>

TextDraw::TextDraw(std::shared_ptr<const TextDrawPack> arg,
    QObject * parent) : QObject(parent),
    mmmDrawPack(arg) {
    this->layoutThis();
}

TextDraw::TextDraw(QObject * p) :
    QObject(p) {

}

void TextDraw::layoutThis() {
    auto varLayoutPack = std::make_shared<TextLayoutPack>();
    this->layoutTitle(varLayoutPack);
    this->layoutBody(varLayoutPack);
}

/*title must be in one page or there will be a error ... */
void TextDraw::layoutTitle(std::shared_ptr<TextLayoutPack> argPack) {

    auto & mmmCurrentHeight = argPack->mmmCurrentHeight;
    auto varCurrentPage = std::make_shared<Page>();
    mmmPages.push_back(varCurrentPage);
    mmmPages.rbegin()->get()->startX = 0;

    const auto varLineWidth =
        mmmDrawPack->pageWidth -
        mmmDrawPack->leftMargin -
        mmmDrawPack->rightMargin;

    mmmTitleLayout.setText(mmmDrawPack->titleRawString);
    if (false == mmmDrawPack->titleRawString.isEmpty()) {
        varCurrentPage->startLine = 1;
    }
    mmmTitleLayout.setFont(mmmDrawPack->titleFont);

    QFontMetricsF varFontMetrics{ mmmDrawPack->titleFont };
    const auto varLeading = varFontMetrics.leading();

    mmmCurrentHeight = mmmDrawPack->topMargin;
    mmmTitleLayout.beginLayout();

    for (;; ) {
        auto varLine = mmmTitleLayout.createLine();
        if (!varLine.isValid()) {
            break;
        }
        ++(argPack->mmmCurrentBodyLine);
        varLine.setLineWidth(varLineWidth);
        mmmCurrentHeight += varLeading;
        varLine.setPosition({ mmmDrawPack->leftMargin  , mmmCurrentHeight });
        mmmCurrentHeight += varLine.height();
        mmmPages.rbegin()->get()->lines.push_back(varLine);
    }

    mmmCurrentHeight += mmmDrawPack->titleBodySpace;
    mmmTitleLayout.endLayout();
    ++mmmPageCount;

}

void TextDraw::layoutBody(std::shared_ptr<TextLayoutPack> argPack) {

    auto & mmmCurrentHeight = argPack->mmmCurrentHeight;
    auto & mmmCurrentWidth = argPack->mmmCurrentWidth;

    mmmCurrentWidth = mmmDrawPack->leftMargin;

    const auto varLineWidth =
        mmmDrawPack->pageWidth -
        mmmDrawPack->leftMargin -
        mmmDrawPack->rightMargin;

    const auto varPageHeightMax =
        (1.0 / 64) +
        mmmDrawPack->pageHeight -
        mmmDrawPack->bottomMargin;
    assert(mmmCurrentHeight <= varPageHeightMax);

    std::list<QString> varParagraphs;
    {
        auto varBodyRawString = mmmDrawPack->bodyRawString;
        QTextStream varStream{ &varBodyRawString , QIODevice::ReadOnly };
        while (varStream.atEnd() == false) {
            auto var = varStream.readLine().trimmed();
            if (var.isEmpty()) {
                continue;
            }
            varParagraphs.push_back(std::move(var));
        }
    }

    for (const auto & varRawTextLine : varParagraphs) {

        auto varCurrentBodyLayout = std::make_shared< QTextLayout >();
        varCurrentBodyLayout->setText(varRawTextLine);
        varCurrentBodyLayout->setFont(mmmDrawPack->bodyFont);
        mmmBodyLayouts.push_front(varCurrentBodyLayout);

        QFontMetricsF varFontMetrics{ mmmDrawPack->bodyFont };
        const auto varLeading = varFontMetrics.leading();
        const auto varHeight = varFontMetrics.height();
        const auto varBeginPageHeightBeginFirstLine = mmmDrawPack->topMargin + varLeading;
        const auto varBeginPageHeightEndFirstLine = varHeight + varBeginPageHeightBeginFirstLine;

        varCurrentBodyLayout->beginLayout();
        for (; ; ) {
            auto varLine = varCurrentBodyLayout->createLine();
            if (!varLine.isValid()) {
                break;
            }
            ++(argPack->mmmCurrentBodyLine);

            varLine.setLineWidth(varLineWidth);
            auto varBeginLineHeight = mmmCurrentHeight + varLeading;
            auto varEndLineHeight = varHeight + varBeginLineHeight;

            if (varEndLineHeight > varPageHeightMax) {
                varBeginLineHeight = varBeginPageHeightBeginFirstLine;
                varEndLineHeight = varBeginPageHeightEndFirstLine;
                mmmCurrentWidth += mmmDrawPack->pageWidth;
                ++mmmPageCount;
                mmmPages.push_back(std::make_shared<Page>());
                mmmPages.rbegin()->get()->startX = mmmCurrentWidth;
                mmmPages.rbegin()->get()->pageNumber = mmmPageCount;
                mmmPages.rbegin()->get()->startLine = argPack->mmmCurrentBodyLine;
            }

            varLine.setPosition({ mmmCurrentWidth , varBeginLineHeight });
            mmmCurrentHeight = varEndLineHeight;
            mmmPages.rbegin()->get()->lines.push_back(varLine);

        }
        varCurrentBodyLayout->endLayout();

    }

}

void TextDraw::resetLayout() {

    mmmPageCount = 0;
    mmmBodyLayouts.clear();
    mmmTitleLayout.clearLayout();
    mmmDrawPack.reset();
    mmmPages.clear();

}

void TextDraw::layout(std::shared_ptr<const TextDrawPack> arg) {
    this->resetLayout();
    mmmDrawPack = arg;
    layoutThis();
}

QImage TextDraw::draw(Float argX) {

    if (argX < 0) {
        argX = 0;
    } else if (mmmPages.empty() == false) {
        if (argX > mmmPages.crbegin()->get()->startX) {
            argX = mmmPages.crbegin()->get()->startX;
        }
    }

    class FindObject {
    public:
        const Float & startX;
        FindObject(const Float & v) :startX(v) {
        }
    } varFindObject{ argX };

    auto varRange = std::equal_range(
        mmmPages.cbegin(),
        mmmPages.cend(),
        &varFindObject,
        [](const auto & l, const auto & r) -> bool {
        return (l->startX) < (r->startX);
    });

    std::vector< std::shared_ptr<Page> > varDrawPages;

    if (mmmPages.size()) {
        if (varRange.first == varRange.second) {
            if (varRange.first == mmmPages.cend()) {
                varDrawPages.push_back(*(varRange.first - 1));
            } else {
                varDrawPages.push_back(*varRange.first);
                if (varRange.first != mmmPages.cbegin()) {
                    varDrawPages.push_back(*(varRange.first - 1));
                }
            }
        } else {
            varDrawPages.push_back(*varRange.first);
        }
    }

    const auto varPageHeight = static_cast<int>(mmmDrawPack->pageHeight + 0.5);
    const auto varPageWidth = static_cast<int>(mmmDrawPack->pageWidth + 0.5);
    QImage varImage{
        varPageWidth, varPageHeight, QImage::Format_RGBA64
    };
    QPainter varPainter{ &varImage };

    varImage.fill({ 0,0,0,0 });
    const auto varDrawPos = QPointF(-argX, 0);

    for (const auto & varPage : varDrawPages) {
        for (const auto & varLine : varPage->lines) {
            varLine.draw(&varPainter, varDrawPos);
        }
    }

    return std::move(varImage);

}

