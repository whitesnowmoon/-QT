#include "File.h"

My::File::File()
{
    FileManage* filepage=new  FileManage();
    FileM* filem=new  FileM(filepage);
    FPage* fpage=new FPage();
}
