#include "pbutton.h"
#include <QDebug>
pbutton::pbutton(QWidget* parent):QPushButton(parent)
{

}

void pbutton::setindex(int index)
{
    this->index=index;
    if(Disk::Page[index].attribute==ATTR_PAGE||index==0){
        connect(this,&QPushButton::clicked,this,&pbutton::turninto);
    }
    if(Disk::Page[index].attribute==ATTR_READ||Disk::Page[index].attribute==ATTR_WRITE){
        connect(this,&QPushButton::clicked,this,&pbutton::showedit);
    }
}

void pbutton::turninto()
{
    qDebug()<<"in"<<index;
    FPage::fpage->TurnInto(Disk::Page[index]);
    wigdetpage::page->showpage(index);
}

void pbutton::showedit()
{
    eidt=new weidt();
    eidt->setOFTLE(index);
    eidt->init();
    eidt->show();
    if(!eidt->open)
        eidt->close();
}
