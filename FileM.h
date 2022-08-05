#ifndef FILEM_H
#define FILEM_H

#include  "Filemanage.h"
#include "Profiles.h"
#include <vector>
using namespace std;
class FileM
{
public:
    static vector<OFTLE> existF;
    FileManage *Manage;
    FileM(FileManage* Manage);
    int DeleteF(OFTLE& file);
    int open(OFTLE& file);
    string *RandW(OFTLE& file);
    int close(OFTLE& file);
    ~FileM();
};

#endif // FILEM_H
