#ifndef TEXTDRAW_HPP
#define TEXTDRAW_HPP

#include <type_traits>
#include <memory>
#include <QtGui/qtextlayout.h>
#include <QtCore/qobject.h>
#include <QtGui/qimage.h>
#include <forward_list>
#include <list>
#include <vector>

class TextDrawTypeTraits {
public:

    using Float = double;
    using Integer = std::int32_t;

};

class TextDrawPack : public TextDrawTypeTraits {
public:
    QString titleRawString;
    QFont titleFont;
    Float titleBodySpace{ 0 };
    QString bodyRawString;
    QFont bodyFont;
    Float pageWidth{ 0 };
    Float pageHeight{ 0 };
    Float leftMargin{ 0 };
    Float rightMargin{ 0 };
    Float topMargin{ 0 };
    Float bottomMargin{ 0 };
};

class TextLayoutPack : public TextDrawTypeTraits {
public:
    Float mmmCurrentHeight{ 0 };
    Float mmmCurrentWidth{ 0 };
    Integer mmmCurrentBodyLine{ 0 };
};

class TextDraw :
    public QObject,
    public TextDrawTypeTraits {
    Q_OBJECT
public:
    TextDraw(QObject * = nullptr);
    TextDraw(std::shared_ptr<const TextDrawPack>, QObject * = nullptr);
    void layout(std::shared_ptr<const TextDrawPack>);
    QImage draw(Float x);
protected:
    void layoutThis();
    void layoutTitle(std::shared_ptr<TextLayoutPack>);
    void layoutBody(std::shared_ptr<TextLayoutPack>);
    void resetLayout();
protected:
    std::shared_ptr<const TextDrawPack> mmmDrawPack;
    QTextLayout mmmTitleLayout;
    std::forward_list< std::shared_ptr< QTextLayout > > mmmBodyLayouts;
    Integer mmmPageCount{ 0 };
    class Page {
    public:
        std::vector< QTextLine > lines;
        Float startX{ 0 };
        Integer pageNumber{ 1 };
        Integer startLine{ 0 };
    };
    std::vector< std::shared_ptr<Page> > mmmPages;
};

#endif // TEXTDRAW_HPP







