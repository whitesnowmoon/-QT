#include "mainwindow.h"
#include "FilePage.h"
#include "FileM.h"
#include "FPage.h"
int main(int argc, char *argv[])
{
    /*FileManage m;
    FileM f(m.Manage);
    FPage p;
    OFTLE a;
    a.index=7;
    a.length=4;
    a.flag=FLAG_RW;
    a.attribute=ATTR_PAGE;
    a.thispos=0;
    p.DeleteOFTLE(a);

    p.CheckPage();*/

    /*f.open(a);
    string* mem=f.RandW(a);
    if(mem==NULL){printf("NULL\n");return 0;}
    mem->append("aaaaaa\0asdefff",14);
    f.close(a);
    printf("len:%d\n",a.length);
    f.open(a);
    mem=f.RandW(a);
    if(mem==NULL){printf("NULL\n");return 0;}
         f.Manage->print(*mem);
     f.close(a);
     a.index=0;
     f.DeleteF(a);
     f.Manage->checkFAT();*/
    /*a.index=6;
    a.flag=FLAG_RW;
    int e=f.open(a);
    printf("e:%d\n",e);
    string* mem=f.RandW(a);
    if(mem==NULL)
        return 0;
    mem->append("sghhfgnjhgj");
    f.close(a);
    f.open(a);
    char rmem[19];
    memset(rmem,'\0',10);
    mem=f.RandW(a);
    memcpy(rmem,mem->data(),10);
    f.close(a);
    printf("rmem:%s\n",rmem);
    f.Manage->checkFAT();*/

    /*m.deletefile(0);
    m.checkFAT();
    int index=m.createfile();
    int e=m.openfile(index,0);
    m.contain[e]+="abcdefg";
    int len=m.closefile(index,e,0);
     m.checkFAT();
    e=m.openfile(index,len);
    m.print(m.contain[e]);
    m.contain[e]+="hijklmn";
    len=m.closefile(index,e,len);
     m.checkFAT();
    e=m.openfile(index,len);
    m.print(m.contain[e]);
    m.contain[e]="uvmm";
    len=m.closefile(index,e,len);
     m.checkFAT();
    e=m.openfile(index,len);
    m.print(m.contain[e]);
    e=m.openfile(index,len);
    m.print(m.contain[e]);
    string out;
    m.DiskRead(index,out);
    m.print(out);
    index=m.createfile();
    e=m.openfile(index,0);
    m.contain[e]+="abcdefgabcdefgabcdefg";
    m.print(m.contain[e]);
    len=m.closefile(index,e,0);
    m.checkFAT();
    e=m.openfile(index,len);
    m.contain[e]="fijklmn";
    m.print(m.contain[e]);
    len=m.closefile(index,e,len);
    m.checkFAT();
    m.deletefile(0);
    m.checkFAT();*/
    //m.contain[0]="hsthbthbstgffffgggggggggggggggggggggggggggggggggggggggggggggggg";

    //FilePage m;



    return 0;
}
