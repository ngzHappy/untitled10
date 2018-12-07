#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtGui>
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setImage(const QImage &);

protected:
    QImage mmmImage;
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP










