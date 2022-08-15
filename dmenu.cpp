#include "dmenu.h"

dmenu::dmenu(QWidget* parent):QDialog(parent)
{
    this->resize(300,400);
    name=new QLineEdit();
    name->setParent(this);
    name->setPlaceholderText("输入名字：");
    name->setGeometry(0,0,width(),height()/8);
    name->setFrame(true);
    name->show();

    y=new QPushButton("确定",this);
    n=new QPushButton("取消",this);
    y->setGeometry(0,height()/4,width()/2,height()/8);
    n->setGeometry(width()/2,height()/4,width()/2,height()/8);
    y->show();
    n->show();
    connect(y,&QPushButton::clicked,this,&dmenu::choose);
    connect(n,&QPushButton::clicked,this,&dmenu::close);
}

void dmenu::setpage(wigdetpage *page)
{
    this->page=page;
}

void dmenu::choose()
{
    string n=name->text().toStdString();
    n.resize(NAMESIZE);
    for(int i=0;i<FILEPAGENUM;i++){
        if(Disk::Page[i].parentpos==FPage::currentpos){
            if(memcmp(Disk::Page[i].name,n.data(),NAMESIZE)==0){
                if(Disk::Page[i].attribute==ATTR_PAGE){
                    FPage::fpage->DeleteOFTLE(Disk::Page[i]);
                    page->showpage(FPage::currentpos);
                    wigdetdisk::wdisk->update();
                    this->close();
                }
                if(Disk::Page[i].attribute==ATTR_READ||Disk::Page[i].attribute==ATTR_WRITE){
                    FileM::filem->DeleteF(Disk::Page[i]);
                    wigdetdisk::wdisk->update();
                    FPage::fpage->DeleteOFTLE(Disk::Page[i]);
                    page->showpage(FPage::currentpos);
                    this->close();
                }
            }
        }
    }
}

void dmenu::resizeEvent(QResizeEvent *event)
{
        name->setGeometry(0,0,width(),height()/8);
        y->setGeometry(0,height()/4,width()/2,height()/8);
        n->setGeometry(width()/2,height()/4,width()/2,height()/8);
}
