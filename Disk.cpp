#include "Disk.h"
#include <stdio.h>
unsigned char Disk::FAT[DiskPieceNum];
OFTLE Disk::Page[FILEPAGENUM];
QFile Disk::disk;
Disk::Disk()
{
     disk.setFileName("Disk");
     if(disk.exists()){
         disk.open(QIODeviceBase::ReadWrite);
         disk.seek(SyStemSize);
         disk.read((char*)Disk::FAT,DiskPieceNum);
         disk.seek(SyStemSize+DiskPieceNum+DiskPieceNum*DiskPieceSize);
         disk.read((char*)Disk::Page,FILEPAGESIZE);
         disk.close();
     }
     else{
         disk.open(QIODeviceBase::ReadWrite);
         memset(Disk::FAT,FILE_UNUSD,DiskPieceNum);
         for(int i=0;i<FILEPAGENUM;i++){
             Page[i].thispos=i;
             Page[i].parentpos=PAGE_UNUSD;
         }
         Page[0].attribute=ATTR_PAGE;
         Page[0].parentpos=PAGE_START;
         disk.seek(SyStemSize);
         disk.write((char*)Disk::FAT,DiskPieceNum);
         disk.seek(SyStemSize+DiskPieceNum+DiskPieceNum*DiskPieceSize);
         disk.write((char*)Disk::Page,FILEPAGESIZE);
         disk.resize(SyStemSize+DiskPieceNum+DiskPieceNum*DiskPieceSize+FILEPAGESIZE);
         disk.close();
     }

}

Disk::~Disk()
{
    disk.open(QIODeviceBase::ReadWrite);
    disk.seek(SyStemSize);
    disk.write((char*)Disk::FAT,DiskPieceNum);
    disk.seek(SyStemSize+DiskPieceNum+DiskPieceNum*DiskPieceSize);
    disk.write((char*)Disk::Page,FILEPAGESIZE);
    disk.close();
}

int Disk::DiskRead(unsigned char index, string &piece)
{
    disk.open(QIODeviceBase::ReadOnly);
    int pos=index,sum=0;
    do{
        if(diskread(pos,piece));
           sum++;
        pos=FAT[pos];
    }while (pos!=FILE_UNUSD&&pos!=FILE_END);
    if(pos==FILE_UNUSD){
        disk.close();
        return -1;
    }
    disk.close();
    return sum;


}

int Disk::DiskWrite(unsigned char index, string &piece)
{
    disk.open(QIODeviceBase::ReadWrite);
    int pos=index,sum=0,times=0,length=0,pro=index;
    length=piece.size();
    if(length%DiskPieceSize)
        piece.resize(length+DiskPieceSize-length%DiskPieceSize);
    times=(length+DiskPieceSize-1)/DiskPieceSize;
    for(int i=0;i<times;i++)
    {
        if(diskwrite(pos,piece.data()+i*DiskPieceSize)){
            sum+=DiskPieceSize;
            pro=pos;
            pos=FAT[pos];
            if(pos==FILE_END)
            {
                if(i==(times-1)){
                    break;
                }
                pos=diskopen();
                if(pos==FIlE_FULL)
                {
                    disk.close();
                    return -1;
                }
                FAT[pro]=pos;
            }
        }

    }
    disk.close();
    return sum;

}

unsigned char Disk::DiskOpen()
{
   return diskopen();
}



int Disk::DiskDelete(unsigned char index)
{
    int pos=index,num=0,p=index;
    if(index==FILE_WRONG||index==FILE_UNUSD)
        return -1;
    while (p!=FILE_END) {
        pos=p;
        p=FAT[pos];
        FAT[pos]=FILE_UNUSD;
        num++;
        if(num>DiskPieceNum)
            return -1;
    }
      FAT[pos]=FILE_UNUSD;
      return pos;
}


void Disk::checkFAT()
{
    printf("FAT:\n");
    for(int i=0;i<DiskPieceNum;i++)
    {
       printf("%d:%d  ",i,FAT[i]);
    }
    printf("\n");
}

void Disk::print(string &piece)
{
    int len=piece.size();
    printf("size:%d\n",len);
    char* mem=piece.data();
    for(int i=0;i<len;i++)
    {
        printf("%d ",mem[i]);
    }
    printf("\n");

}

bool Disk::diskwrite(unsigned char index,char* mem)
{
    int num=0;
    char m[DiskPieceSize+1]={0,0,0,'\0'};
    memcpy(m,mem,DiskPieceSize);
    disk.seek(SyStemSize+DiskPieceNum+(index)*DiskPieceSize);
    num=disk.write(m,DiskPieceSize);
    if(num==DiskPieceSize)
        return true;
    else return false;
}

bool Disk::diskread(unsigned char index,string& piece)
{
    int num=0;
    char mem[DiskPieceSize+1]={0,0,0,'\0'};
    disk.seek(SyStemSize+DiskPieceNum+(index)*DiskPieceSize);
    num=disk.read(mem,DiskPieceSize);
    piece.append(mem,DiskPieceSize);
    if(num==DiskPieceSize)
        return true;
    else return false;
}

unsigned char Disk::diskopen()
{
    for(int i=0;i<DiskPieceNum;i++)
    {
        if(FAT[i]==FILE_UNUSD)
        {
            FAT[i]=FILE_END;
            return i;
        }
    }
    return FIlE_FULL;
}
