#include "weidt.h"
int weidt::opennum=0;
void weidt::setOFTLE(int index)
{
    file=&Disk::Page[index];
}

void weidt::init()
{
    if(opennum<ALLOWOPENNUM){
        open=true;
        opennum++;
        FileM::filem->open(*file);
        qDebug()<<file->exist;
        qDebug()<<" name:"<<file->name;
        file->flag=FLAG_RW;
        rw=FileM::filem->RandW(*file);
        if(rw){
            this->setPlainText(QString::fromStdString(*rw));
            qDebug()<<"change char in file";
        }
    }
    else{
        QMessageBox::information(this, "警告","文件打开数目达到最大！");
        open=false;
    }
}

weidt::weidt()
{

}

void weidt::closeEvent(QCloseEvent *event)
{
    if(open){
        string p=this->toPlainText().toStdString();
        rw->swap(p);
        FileM::filem->close(*file);
        int thispos=FPage::fpage->ChangeFTLEtoP(*file);
        wigdetdisk::wdisk->update();
        opennum--;
        qDebug()<<"close:"<<thispos<<"length:"<<file->length;
    }
}
