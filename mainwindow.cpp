#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->resize(800,600);
    disk.setParent(this);
    disk.setGeometry(0,0,width(),height()/2);
    disk.update();
    disk.show();

    page.setParent(this);
    page.setGeometry(0,height()/2,width(),height()/2);
    page.show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    disk.setGeometry(0,0,width(),height()/2);
     page.setGeometry(0,height()/2,width(),height()/2);
}



