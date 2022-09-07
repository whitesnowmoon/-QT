#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->resize(800,600);
    disk.setParent(this);
    disk.setGeometry(0,height()/24.0,width(),height()/24.0*11.0);
    disk.update();
    disk.show();

    page.setParent(this);
    page.setGeometry(0,height()/24.0*13,width(),height()/24.0*11.0);
    page.show();

    textlable1 =new QLabel();
    textlable1->setParent(this);
    textlable1->setGeometry(0,height()/2,width(),height()/24);
    textlable1->setText("文件目录:");
    textlable1->setMargin(6);
    textlable1->setFrameStyle(6);
    textlable1->show();


    textlable2 =new QLabel("磁盘内存使用情况:");
    textlable2->setGeometry(0,0,width(),height()/24.0);
    textlable2->setParent(this);
    textlable2->setMargin(6);
    textlable2->setFrameStyle(6);
    textlable2->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    disk.setGeometry(0,height()/24.0,width(),height()/24.0*11.0);
    page.setGeometry(0,height()/24.0*13.0,width(),height()/24.0*11.0);
    textlable1->setGeometry(0,height()/2.0,width(),height()/24.0);
    textlable2->setGeometry(0,0,width(),height()/24.0);
}



