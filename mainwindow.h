#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wigdetdisk.h"
#include "wigdetpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    wigdetdisk disk;
    wigdetpage page;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // QPaintDevice interface
protected:
    void paintEvent(QPaintEvent *event) ;

};
#endif // MAINWINDOW_H
