#ifndef FILE_H
#define FILE_H

#include <QObject>
#include "Filemanage.h"
#include "FileM.h"
#include "FPage.h"

namespace My{
class File:public QObject
{
    Q_OBJECT
public:
    FileManage* filepage;
    FileM* filem;
    FPage* fpage;
    File();
    OFTLE create_file(string name,char attribute);
    string* open_file(OFTLE File,int flag);
    void read_file();
    void write_file();
    void close_file();
    void delete_file();
    void typefile();
    void change();

    int dir();
    bool md();
    bool rd();
};
}
#endif // FILE_H
