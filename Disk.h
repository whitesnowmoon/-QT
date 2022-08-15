#ifndef DISK_H
#define DISK_H
#include"Profiles.h"
#include <QObject>
#include<QFile>
#include <string>
using namespace std;
class FPage;
class Disk:public QObject
{
    Q_OBJECT
    friend class FPage;
public:
    static unsigned char FAT[DiskPieceNum];
    static OFTLE Page[FILEPAGENUM];
    Disk();
    ~Disk();
    int DiskRead(unsigned char index,string& piece);
    int DiskWrite(unsigned char index,string& piece);
    unsigned char DiskOpen();
    int DiskDelete(unsigned char index);
    void checkFAT();
    void print(string& piece);
private:
    static QFile disk;
    bool diskwrite(unsigned char index,char* mem);
    bool diskread(unsigned char index,string& piece);
    unsigned char diskopen();
};

#endif // DISK_H
