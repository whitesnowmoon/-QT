#ifndef FILEMANAGE_H
#define FILEMANAGE_H
//char a[313];
#include <QObject>
#include "Disk.h"

class FileManage:public Disk
{
    Q_OBJECT
public:
    FileManage* Manage;
    char a[313];
    static string contain[ALLOWOPENNUM];
    FileManage();
    ~FileManage();
    int createfile();//设置FAT[index]=-1,返回index
    int openfile(int index,int len);//将index内存送进contain【e】，返回e/-1不存在index=unused，len=-1读取至-1取整，其他截取
    int closefile(int index,int e,int plen);//返回新nlen，原plen
    int deletefile(int index);
private:
    int Getempty();
};
#endif // FILEMANAGE_H
