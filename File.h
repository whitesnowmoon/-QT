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
    bool open_file(OFTLE &File,int flag);
    int read_file(OFTLE& File,char* mem,int size,int pos);
    int write_file(OFTLE& File,char* mem,int size,int pos);
    bool close_file(OFTLE &file);
    bool delete_file(OFTLE &file);
    bool typefile(OFTLE file);

    int dir();
    bool change(OFTLE* file);
    OFTLE* md(string name);
    bool rd(OFTLE &file);
    bool bd();
    OFTLE* getF(string name);

    ~File();
};
}
#endif // FILE_H
