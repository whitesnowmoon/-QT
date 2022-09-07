#ifndef PBUTTON_H
#define PBUTTON_H

#include <QObject>
#include <QPushButton>
#include "FPage.h"
#include "wigdetpage.h"
#include "weidt.h"

class pbutton:public QPushButton
{
    Q_OBJECT
public:
    weidt* eidt;
    int index;
    pbutton(QWidget* parent=nullptr);
    void setindex(int index);
public slots:
    void turninto();
    void showedit();
};

#endif // PBUTTON_H
