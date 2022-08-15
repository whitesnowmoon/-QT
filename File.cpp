#include "File.h"

My::File::File()
{
    filepage=new  FileManage();
    filem=new  FileM(filepage);
    fpage=new FPage();
    if(filepage)
        printf("filepage open %d!\n",filepage);
    if(filem)
        printf("filem open %d!\n",filem);
    if(fpage)
        printf("fpage open %d!\n",fpage);
}

My::File::~File()
{
    if(filepage)
        delete filepage;
    if(filem)
        delete filem;
    if(fpage)
        delete fpage;
    printf("all close!\n");
}

OFTLE My::File::create_file(string name, char attribute)
{
    OFTLE newmake;
    memset(&newmake,0,sizeof (OFTLE));
    newmake.attribute=attribute;
    newmake.exist=0;
    newmake.flag=FLAG_R;
    newmake.length=0;
    memcpy(newmake.name,name.data(),NAMESIZE);
    newmake.index=filepage->createfile();
    fpage->MakeOFTLE(newmake);
    return newmake;
}

bool My::File::open_file(OFTLE& File, int flag)
{
    File.exist=filem->open(File);
    File.flag=flag;
    if(File.exist!=-1)
        return false;
    return true;
}

int My::File::read_file(OFTLE& File,char *mem, int size,int pos)
{
    int s=size;
    if(File.flag!=FLAG_RW||File.flag!=FLAG_R)
        return -1;
    if(File.exist<0||File.exist>=ALLOWOPENNUM)
        return -1;
    if((pos+size)>FileManage::contain[File.exist].size())
        return -1;
    memcpy(mem, FileManage::contain[File.exist].data()+pos,s);
    return size;
}

int My::File::write_file(OFTLE& File,char *mem, int size,int pos)
{
    string insert;
    int p=pos;
    insert.append(mem,size);
    if(File.exist<0||File.exist>=ALLOWOPENNUM)
        return -1;
    if(File.flag==FLAG_RW){
    if(p>FileManage::contain[File.exist].size())
        FileManage::contain[File.exist].insert(File.length,insert,0,size);
    else
       FileManage::contain[File.exist].insert(pos,insert,0,size);
    }
    else if(File.flag==FLAG_W){
        FileManage::contain[File.exist].clear();
        FileManage::contain[File.exist].append(insert);
    }
    else{
        return -1;
    }
    return size;
}

bool My::File::close_file(OFTLE& file)
{
    fpage->ChangeFTLEtoP(file);
    filem->close(file);
    return true;
}

bool My::File::delete_file(OFTLE& file)
{
    fpage->DeleteOFTLE(file);
    filem->DeleteF(file);
    return true;
}

bool My::File::typefile(OFTLE file)
{
    if(file.exist<0||file.exist>=ALLOWOPENNUM)
        return -1;
    char* p=FileManage::contain[file.exist].data();
    printf("file size:%d  contain size: %d\n",file.length,FileManage::contain[file.exist].size());
    for(int i=0;i<FileManage::contain[file.exist].size();i++)
    {
        printf("%c",*(p++));
    }
    printf("\n");
    return true;
}

int My::File::dir()
{
    return fpage->Shownowall();
}

bool My::File::change(OFTLE* file)
{
    return fpage->TurnInto(*file);
}

OFTLE* My::File::md(string name)
{
    OFTLE* r=fpage->MakePage(name);
    if(r!=NULL)
        return r;
    return NULL;
}

bool My::File::rd(OFTLE &file)
{
    fpage->DeleteOFTLE(file);
    return true;
}

bool My::File::bd()
{
    fpage->TurnBack();
    return 1;
}

OFTLE *My::File::getF(string name)
{
    return fpage->SelectOFTLE(name);
}

