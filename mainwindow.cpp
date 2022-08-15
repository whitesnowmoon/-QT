/*作者.李国亮*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    disk.setParent(this);
    disk.setGeometry(0,0,width(),300);
    disk.update();
    disk.show();

    page.setGeometry(0,300,width(),300);
    page.show();
    this->update();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}


