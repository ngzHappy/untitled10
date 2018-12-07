#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QtGui/qpainter.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);

    QPainter varPainter{this};
    varPainter.drawImage(QPoint{0,0},mmmImage);

}

void MainWindow::setImage(const QImage & arg){
    mmmImage = arg;
    this->update();
}


