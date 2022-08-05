#ifndef PROFILES_H
#define PROFILES_H


#define DiskPieceSize 3
#define DiskPieceNum 128   //0~250
#define SyStemSize 50


#define FILEPAGENUM  100
#define FILEPAGESIZE FILEPAGENUM*sizeof(OFTLE)
#define PAGE_UNUSD -1
#define PAGE_START -2

#define FILE_END 255
#define FILE_UNUSD 254
#define FILE_WRONG 253
#define FIlE_FULL 255

#define ATTR_USER_HIDE 0
#define ATTR_READ 1
#define ATTR_WRITE 2
#define ATTR_PAGE 3

#define FLAG_R 0
#define FLAG_W 1
#define FLAG_RW 2

#define ALLOWOPENNUM 5 //实验中系统允许打开文件的最大数量
typedef struct
{
    int dnum; //磁盘盘块号
    int bnum; //磁盘盘块内第几个字节
}pointer; //已打开文件表中读、写指针的结构

typedef struct
{
    char name[20]; //文件绝对路径名
    char attribute; //文件的属性，用 1 个字节表示，所以此用 char 类型
    int index; //文件起始盘块号
    int length; //文件长度，文件占用的字节数
    pointer read; //读文件的位置，文件打开时 dnum 为文件起始盘块号，bnum 为“0”
    pointer write; //写文件的位置，文件刚建立时 dnum 为文件起始盘块号，bnum 为“0 ，打开文件时 dnum 和 bnum 为文件的末尾位置22
    int flag; //操作类型，用“0”表示以读操作方式打开文件，用“1”表示以写操作方式打开文件,2读写

    char exist; //缓存位置
    int thispos; //该目录位置
    int parentpos; //父目录位置
}OFTLE; //已打开文件表项类型定义

typedef struct
{
    OFTLE file[ALLOWOPENNUM]; //已打开文件登记表
    int NUM; //已打开文件登记表中登记的文件数量
}OpenFile; //已打开文件登记表定义

#endif // PROFILES_H
