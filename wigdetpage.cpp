#include "wigdetpage.h"
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QLayout>
#include <QVBoxLayout>
#define buttonhight 30
wigdetpage* wigdetpage::page;
wigdetpage::wigdetpage(QWidget* parent):QScrollArea(parent)
{
    page=this;
    this->setWidgetResizable(true);
    background.setFixedSize(300,0);
    background.setParent(this);
    background.setLayout(new QVBoxLayout);
    background.show();
    this->setWidget(&background);
    this->setBackgroundRole(QPalette::Dark);
    showpage(0);
}

void wigdetpage::addButton(int index)
{
    pbutton *p=new pbutton();
    p->setindex(index);
    p->setText(Disk::Page[index].name);
    if(Disk::Page[index].attribute==ATTR_PAGE)
        p->setStyleSheet(pagecolor);
    if(Disk::Page[index].attribute==ATTR_READ||Disk::Page[index].attribute==ATTR_WRITE)
        p->setStyleSheet(rwcolor);
    p->setParent(&background);
    int i=Button.size();
     background.layout()->addWidget(p);
    background.setFixedSize(300,background.height()+buttonhight);//注意出错
    Button.push_back(p);

}

void wigdetpage::showpage(int parentindex)
{
    QList<QPushButton*> btns = background.findChildren<QPushButton*>();
    foreach (QPushButton* btn, btns) {   delete btn;  }
    /*for(int i=1;i<Button.size();i++)
    {
        delete Button[i];
    }*/
    Button.clear();
    background.setFixedSize(300,buttonhight);
    pbutton *p=new pbutton();
    p->setText("back");
    p->setindex(Disk::Page[FPage::currentpos].parentpos);
    p->setStyleSheet(backcolor);
    p->setParent(&background);
    background.layout()->addWidget(p);
    Button.push_back(p);
    for(int i=0;i<FILEPAGENUM;i++){
        if(Disk::Page[i].parentpos==parentindex){
            addButton(i);
        }
    }
    background.update();
}

void wigdetpage::createpDialog()
{
    createmenu=new pmenu();
    createmenu->setpage(this);
    createmenu->show();
}

void wigdetpage::createdDialog()
{
    delmenu=new dmenu();
    delmenu->setpage(this);
    delmenu->show();
}

void wigdetpage::mousePressEvent(QMouseEvent *event)
{

    QMenu* m_contextMenu = new QMenu;
    QAction* m_addAction = new QAction("新增",this);
    QAction* m_delAction = new QAction("删除",this);
    m_contextMenu->addAction(m_addAction);
    m_contextMenu->addAction(m_delAction);
    connect(m_addAction,&QAction::triggered,this,&wigdetpage::createpDialog);
    connect(m_delAction,&QAction::triggered,this,&wigdetpage::createdDialog);
    if (event->button() == Qt::RightButton)
    {
           m_contextMenu->exec(event->globalPos());
    }
    event->accept();
}




