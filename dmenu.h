#ifndef DMENU_H
#define DMENU_H

#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include "FPage.h"
#include "wigdetpage.h"
#include "FileM.h"
#include "wigdetdisk.h"
class wigdetpage;
class dmenu :public QDialog
{
    Q_OBJECT
public:
    wigdetpage* page;
    QLineEdit*name;
    QRadioButton* attr;
    QButtonGroup* group;
    QPushButton* y;
    QPushButton* n;
    dmenu(QWidget* parent=nullptr);
    void setpage(wigdetpage *page);
public slots:
    void  choose();
};

#endif // DMENU_H
