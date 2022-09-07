#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
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
    QLabel* textlable1;
    QLabel* textlable2;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
