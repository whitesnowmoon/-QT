#include "FileM.h"
#include <string>

vector<OFTLE> FileM::existF;
FileM::FileM(FileManage *Manage):Manage(Manage)
{

}

int FileM::DeleteF(OFTLE &file)
{
    int r=Manage->deletefile(file.index);
    if(r==-1)
        return -1;
    memset(&file,0,sizeof (OFTLE));
    return r;
}

int FileM::open(OFTLE& file)
{
    int num_existF=existF.size(),index=FILE_UNUSD,r=-1,e=-1,i=0;
    for(i=0;i<num_existF;i++){
        if(file.index==existF[i].index){
            return existF[i].exist;
        }
    }
    file.exist=Manage->openfile(file.index,file.length);
    if(file.exist==-1){
        index=Manage->createfile();
        if(index!=FIlE_FULL){
            file.exist=Manage->openfile(index,0);
            file.length=0;
            file.index=index;
            if(file.exist==-1){
                printf("file full open!\n");
                return -1;
            }
            existF.push_back(file);
            return existF.size()-1;
        }
        else {
                return -1;
        }
    }
    else {
        existF.push_back(file);
        return existF.size()-1;
    }

}

string* FileM::RandW(OFTLE& file)
{
    int num_existF=existF.size(),i=0;
    for(i=0;i<num_existF;i++){
        if(file.index==existF[i].index){
           break;
        }
    }
    if(i==num_existF||file.flag==FLAG_R)
        return NULL;
    if(file.flag==FLAG_RW||file.flag==FLAG_W){
        if(existF[i].exist>=0&&existF[i].exist<=ALLOWOPENNUM){
             printf("open address:%d\n",Manage->contain[(unsigned char)existF[i].exist].data());
             return &Manage->contain[(unsigned char)existF[i].exist];
        }

    }
    return NULL;
}

int FileM::close(OFTLE& file)
{
    int num_existF=existF.size(),i=0;
    for(i=0;i<num_existF;i++){
        if(file.index==existF[i].index){
            break;
        }
    }
    if(i==num_existF)return -1;
    printf("close:%s address:%d contain:%s size:%d\n\n",Manage->contain[(unsigned char)existF[i].exist].data(),
    Manage->contain[(unsigned char)existF[i].exist].data(),FileManage::contain[(unsigned char)existF[i].exist].data(),
    FileManage::contain[(unsigned char)existF[i].exist].size());
    int len=Manage->closefile(file.index,existF[i].exist,file.length);
    existF.erase(existF.begin()+i);
    file.length=len;
    return i;
}

FileM::~FileM()
{

}



