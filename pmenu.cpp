#include "pmenu.h"
#include <QVBoxLayout>
#include "FPage.h"
#include "wigdetdisk.h"
pmenu::pmenu(QWidget*parent):QDialog(parent)
{
    this->resize(300,400);
    name=new QLineEdit();
    name->setParent(this);
    name->setPlaceholderText("输入名字：");
    name->setGeometry(0,0,width(),height()/8);
    name->setFrame(true);
    name->show();
    group = new QButtonGroup(this);
    // 设置互斥
   group->setExclusive(true);
   pButton1 = new QRadioButton(this);
   pButton1->setGeometry(0,height()/8,width(),height()/8);
   pButton1->setText("文件");
   group->addButton(pButton1);
   pButton2 = new QRadioButton(this);
   pButton2->setGeometry(width()/2,height()/8,width(),height()/8);
   pButton2->setText("文件夹");
   group->addButton(pButton2);
   y=new QPushButton("确定",this);
   n=new QPushButton("取消",this);
   y->setGeometry(0,height()/4,width()/2,height()/8);
   n->setGeometry(width()/2,height()/4,width()/2,height()/8);
   y->show();
   n->show();
   connect(y,&QPushButton::clicked,this,&pmenu::choose);
   connect(n,&QPushButton::clicked,this,&pmenu::close);
}

void pmenu::setpage(wigdetpage *page)
{
    this->page=page;
}

void pmenu::choose()
{
    string n;
    n.resize(NAMESIZE);
    n=name->text().toStdString();
    if(pButton2->isChecked())
    {
        FPage::fpage->MakePage(n);
        page->showpage(FPage::currentpos);
        this->close();
    }
    if(pButton1->isChecked())
    {
        OFTLE f;
        f.index=FILE_UNUSD;
        f.length=0;
        f.exist=-1;
        qDebug()<<"init  index:"<<f.index;
        FileM::filem->open(f);
        memcpy(f.name,n.data(),NAMESIZE);
        f.attribute=ATTR_WRITE;
        FileM::filem->close(f);
        wigdetdisk::wdisk->update();
        qDebug()<<"index:"<<f.index;
        if(f.index>=0&&f.index<DiskPieceNum){
        FPage::fpage->MakeOFTLE(f);
        page->showpage(FPage::currentpos);
        }
        this->close();
    }

}
