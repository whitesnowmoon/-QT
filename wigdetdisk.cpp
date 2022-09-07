#include "wigdetdisk.h"
#include <Disk.h>
#include <QRandomGenerator>
wigdetdisk*wigdetdisk::wdisk;
wigdetdisk::wigdetdisk(QWidget *parent):QLabel(parent)
{
    setStyleSheet("QLabel{border:2px solid rgb(200, 200, 200);}");
    wdisk=this;
    for (int i=0;i<DiskPieceNum;i++) {
       fillcolors[i]=QColor(0,0,0,255);
    }
}

void wigdetdisk::paintEvent(QPaintEvent *event)
{

    float interval=(float)width()/(DiskPieceNum);
    int i=0,index=-1;
    for (int i=0;i<DiskPieceNum;i++) {
        index=isindex(i);
        if(index==-1){
            fillPiece[i]=0;
        }
        else fillPiece[i]=1;
    }
    painter.begin(this);
    for (int i=0;i<DiskPieceNum;i++) {
         if(fillPiece[i]==1)
               fillfile(i);
    }
    for (;i<DiskPieceNum;i++) {
       painter.drawLine(interval*i,0,interval*i,height());
    }
    for (;i<FILEPAGENUM;i++) {
       painter.drawLine(interval*i,0,interval*i,height()/2);
    }
    painter.end();


}

int wigdetdisk::isindex(int i)
{
    int index=i;
    if(Disk::FAT[i]!=FILE_UNUSD&&Disk::FAT[i]!=FILE_WRONG)
    {
        for (int i=0;i<DiskPieceNum;i++) {
               if(Disk::FAT[i]==index){
                   index=-1;
               }
        }
        return index;
    }
    else {
        return -1;
    }
}

void wigdetdisk::fillfile(int index)
{
    int i=index;
    QBrush brush;//(Qt::darkYellow);
    if(fillcolors[index]==QColor(0,0,0,255)){
        bool repeat=true; QColor c;
        while (repeat) {
            repeat=false;
            c= QColor::fromRgb(QRandomGenerator::global()->generate());
            for (int i=0;i<DiskPieceNum;i++) {
               if(fillcolors[i]==c)
                   repeat=true;
            }
        }
        fillcolors[index]=c;
        brush.setColor(fillcolors[index]);
    }
    else {
        brush.setColor(fillcolors[index]);
    }
    brush.setStyle(Qt :: SolidPattern);//构造一个默认的黑色画笔与风格的Qt :: NoBrush（即，该刷不填充形状）。在你的第二个例子，你必须的setStyle（）设置QBrush对象的样式
    float interval=(float)width()/(DiskPieceNum);
    while (i!=FILE_END) {
        painter.fillRect(QRect(i*interval, 0, interval, height()), brush);
        i=Disk::FAT[i];
    }
}


