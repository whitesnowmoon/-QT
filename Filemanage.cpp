#include "Filemanage.h"
#include <QDebug>
string FileManage::contain[ALLOWOPENNUM];
FileManage::FileManage()
{
    Manage=this;
}

FileManage::~FileManage()
{

}


int FileManage::createfile()
{
    return DiskOpen();//index
}
int FileManage::openfile(int index,int len)
{
    int e=Getempty();
    int t=DiskRead(index,contain[e]);
    if(t==-1){
        contain[e].clear();
        return -1;
    }
    else{
        if(len!=-1)
            contain[e].resize(len);
        return e;
    }//e
}
int FileManage::closefile(int index,int e,int plen)
{
    int len= contain[e].size();
    //printf("size:%d c:%s\n",len,contain[e].data());
    //if(plen>len)
    if(len>plen)
    {
        DiskDelete(index);
        FAT[index]=FILE_END;
        DiskWrite(index,contain[e]);
    }
    else{
        DiskWrite(index,contain[e]);
    }
    contain[e].clear();
    return len;

}
int FileManage::deletefile(int index)
{
    return DiskDelete(index);
}
int FileManage::Getempty()
{
    for(int i=0;i<ALLOWOPENNUM;i++)
    {
        if(contain[i].size()==0)
            return i;
    }
    return -1;
}
