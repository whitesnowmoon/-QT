#ifndef WIGDETPAGE_H
#define WIGDETPAGE_H

#include <QObject>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <vector>
#include "Disk.h"
#include "pbutton.h"
#include "FPage.h"
#include "pmenu.h"
#include "dmenu.h"
class pbutton;
class pmenu;
class dmenu;
class wigdetpage : public QScrollArea
{
    Q_OBJECT
public:
    static wigdetpage* page;
    pmenu* createmenu;
    dmenu* delmenu;
    vector<pbutton*> Button;
    QLabel background;
    wigdetpage(QWidget* parent=nullptr);
    void addButton(int index);
    void showpage(int parentindex);

public slots:
    void createpDialog();
    void createdDialog();
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // WIGDETPAGE_H
