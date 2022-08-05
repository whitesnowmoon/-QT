#ifndef FILEPAGE_H
#define FILEPAGE_H

#include <QObject>
#include <Profiles.h>
#include <vector>
#include "Filemanage.h"
using namespace std;
class FilePage:public FileManage
{
    Q_OBJECT
public:
    int now_e;
    vector<OFTLE> page;
    int dir();
    bool md();
    bool rd();

    void create_file(OFTLE& Src,OFTLE File);
    string* open_file(OFTLE File,int flag);
    void read_file();
    void write_file();
    void close_file();
    void delete_file();
    void typefile();
    void change();

    FilePage();
private:
    void showallf();
};

#endif // FILEPAGE_H
