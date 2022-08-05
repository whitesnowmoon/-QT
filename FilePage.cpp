#include "FilePage.h"

FilePage::FilePage()
{

    int e=openfile(0,-1);
    now_e=e;
    int len;
    char*mem;
    OFTLE p;
    if(e!=-1){
        len=contain[e].size();
        mem=contain[e].data();
        for(int i=0;i<len;i+=sizeof(OFTLE))
        {
            memcpy(&p,mem+i,sizeof(OFTLE));
            page.push_back(p);
        }
    }
    else {
        p.length=sizeof(OFTLE);
        p.attribute=1;
        p.index=0;
        memcpy(p.name,"D",1);
      int index=createfile();
       e=openfile(index,0);
      mem=contain[e].data();
      now_e=e;
       memcpy(mem,&p,sizeof(OFTLE));
       closefile(index,e,0);
       showallf();

    }
}

void FilePage::showallf()
{
    int num=page.size();
    for(int i=0;i<num;i++){
        printf("name:%s,attribute:%d,index:%d,length:%d,flag:%d\n",
        page[i].name,page[i].attribute,page[i].index,page[i].flag);
    }
}
