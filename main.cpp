#include <QApplication>
#include "mainwindow.h"
//#include "FilePage.h"
//#include "FileM.h"
//#include "FPage.h"
#include "File.h"
using namespace My;
int main(int argc, char *argv[])
{
    File f;
    QApplication m(argc,argv);
    MainWindow a;
    /*OFTLE r1=f.create_file("first",ATTR_WRITE|ATTR_READ);
    f.open_file(r1,FLAG_RW);
    f.write_file(r1,s1.data(),s1.size(),0);
    f.typefile(r1);
    f.close_file(r1);
    printf("index:%d\n",r1.index);*/
    a.show();
    int r=m.exec();
    f.fpage->CheckPage();
    f.filem->Manage->checkFAT();
    return r;
    /*File f;
    string s1="asdfhkl;7&";
    string s2="nxghnxdx?";

    f.md("asdfg&");
    f.md("asd");
    f.md("openh");
    f.md("hmbhm");

    f.dir();
    OFTLE*r=f.getF("openh");
    printf("attr: %d|parent: %d|this: %d\n",r->attribute,r->parentpos,r->thispos);
    f.change(r);
    f.md("second_bfgfnx");
    f.md("second_aggggfn?");
    f.md("cxv");
    OFTLE*r2=f.getF("second_aggggfn?");
    printf("attr: %d|parent: %d|this: %d\n",r->attribute,r->parentpos,r->thispos);
    f.change(r2);
    f.md("trith_bfgfnx");
    f.md("trith_aggggfn?");
    f.md("tcxv");
        f.fpage->CheckPage();
    f.rd(*r);
    f.fpage->CheckPage();*/
    /*f.dir();
    OFTLE*r=f.getF("openh");
    printf("attr: %d|parent: %d|this: %d\n",r->attribute,r->parentpos,r->thispos);
    f.change(r);
    r=f.getF("second_aggggfn?");
    printf("attr: %d|parent: %d|this: %d\n",r->attribute,r->parentpos,r->thispos);
    f.change(r);
    //f.rd(*f.getF("second_bfgfnx"));
      //  printf("------------------------\n");
    //f.dir();
    //f.fpage->CheckPage();
    f.md("second_bfgfnx");
    f.md("second_aggggfn?");
    f.md("cxv");
    f.fpage->CheckPage();*/
    /*OFTLE r1=f.create_file("first",ATTR_WRITE|ATTR_READ);
    f.open_file(r1,FLAG_RW);
    f.write_file(r1,s1.data(),s1.size(),0);
    f.typefile(r1);
    f.close_file(r1);
    OFTLE r2=f.create_file("second",ATTR_WRITE|ATTR_READ);
    f.open_file(r2,FLAG_RW);
    f.write_file(r2,s2.data(),s2.size(),0);
    f.typefile(r2);
    f.close_file(r2);
    r2=f.create_file("third",ATTR_WRITE|ATTR_READ);
    f.open_file(r2,FLAG_RW);
    f.write_file(r2,s2.data(),s2.size(),0);
    f.typefile(r2);
    f.close_file(r2);
    f.dir();
    f.md("file");
    OFTLE* c=f.getF("file");
    printf("%d %d\n",c->parentpos,c->thispos);
    f.change(c);
    f.md("next");
    printf("------------------------\n");
    f.fpage->CheckPage();*/

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

}
