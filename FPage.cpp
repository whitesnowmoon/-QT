#include "FPage.h"

FPage::FPage()
{

}

int FPage::MakeOFTLE(OFTLE& tomake)
{
   int thispos;
   thispos=findempty();
   if(thispos==-1)
        return -1;
   tomake.parentpos=currentpos;
   tomake.thispos=thispos;
   memcpy(&Page[thispos],&tomake,sizeof (OFTLE));
   return thispos;
}

int FPage::DeleteOFTLE(OFTLE &toDelete)
{
    toDelete.parentpos=PAGE_UNUSD;
    memset(&Page[toDelete.thispos],0,sizeof (OFTLE));
    Page[toDelete.thispos].thispos=toDelete.thispos;
    Page[toDelete.thispos].parentpos=PAGE_UNUSD;
    if(toDelete.thispos==0){
        toDelete.parentpos=PAGE_START;
        Page[toDelete.thispos].parentpos=PAGE_START;
    }
    del(toDelete.thispos);
    return toDelete.thispos;

}

int FPage::ShowSonOFTLE(OFTLE &toShow)
{
    int i=0,sum=0;
    for(i=0;i<FILEPAGENUM;i++){
       if(Page[i].parentpos==toShow.thispos){
           printf("page file:%d\n",i);
           sum++;
       }
    }
    return sum;
}

int FPage::TurnInto(OFTLE &into)
{
    if(into.attribute==ATTR_PAGE){
        currentpos=into.thispos;
           printf("thispos:%d\n",currentpos);
    }
    return 0;
}

int FPage::ChangeFTLEtoP(OFTLE &change)
{
     memcpy(&Page[change.thispos],&change,sizeof (OFTLE));
     return change.thispos;
}

void FPage::CheckPage()
{
    for(int i=0;i<FILEPAGENUM;i++){
        printf("%d page: %d : %d\n",i,Page[i].thispos,Page[i].parentpos);
    }
}

void FPage::del(int thispos)
{
    int i=0;
    for(i=0;i<FILEPAGENUM;i++){
        if(Page[i].parentpos==thispos){
            del(i);
            memset(&Page[i],0,sizeof (OFTLE));
            Page[i].thispos=i;
            Page[i].parentpos=PAGE_UNUSD;
        }
    }
}

int FPage::findempty()
{
    int i=0;
    for(i=0;i<FILEPAGENUM;i++){
        if(Page[i].parentpos==PAGE_UNUSD)
            return i;
    }
    return -1;
}
