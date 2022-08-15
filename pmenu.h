#ifndef PMENU_H
#define PMENU_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QRadioButton>
#include <QButtonGroup>
#include <QPushButton>
#include "wigdetpage.h"
#include "FileM.h"
class wigdetpage;
class pmenu:public QDialog
{
    Q_OBJECT
public:
    wigdetpage* page;
    QLineEdit*name;
    QRadioButton* attr;
    QButtonGroup* group;
    QPushButton* y;
    QPushButton* n;
    QRadioButton *pButton1;
    QRadioButton *pButton2;
    pmenu(QWidget*parent=nullptr);
    void setpage(wigdetpage* page);
public slots:
    void choose();
};

#endif // PMENU_H
