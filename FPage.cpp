#include "FPage.h"
#include "FileM.h"
int FPage::currentpos=0;
FPage* FPage::fpage;
FPage::FPage()
{
    fpage=this;
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
    Page[toDelete.thispos].length=0;
    Page[toDelete.thispos].index=FILE_UNUSD;
    Page[toDelete.thispos].thispos=toDelete.thispos;
    Page[toDelete.thispos].parentpos=PAGE_UNUSD;
    if(toDelete.thispos==0){
        toDelete.parentpos=PAGE_START;
        Page[toDelete.thispos].parentpos=PAGE_START;
    }
    if(toDelete.attribute==ATTR_PAGE)
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
        return 1;
    }
    return 0;
}

int FPage::TurnBack()
{
    currentpos=Page[currentpos].parentpos;
    return 1;
}

int FPage::ChangeFTLEtoP(OFTLE &change)
{
     memcpy(&Page[change.thispos],&change,sizeof (OFTLE));
     return change.thispos;
}

OFTLE* FPage::MakePage(string name)
{
    int thispos;
    name.resize(NAMESIZE);
    thispos=findempty();
    if(thispos==-1)
         return NULL;
    Page[thispos].parentpos=currentpos;
    Page[thispos].thispos=thispos;
    Page[thispos].attribute=ATTR_PAGE;
    memcpy(Page[thispos].name,name.data(),NAMESIZE);
    return &Page[thispos];
}

void FPage::CheckPage()
{
    for(int i=0;i<FILEPAGENUM;i++){
        printf("%d page: %d : %d  %s\n",i,Page[i].thispos,Page[i].parentpos,Page[i].name);
    }
}

OFTLE* FPage::SelectOFTLE(string name)
{
    bool equal=1;int i=0;
    name.resize(NAMESIZE);
    for(i=0;i<FILEPAGENUM;i++){
        if(Page[i].parentpos==currentpos){
            equal=1;
            for(int j=0;j<NAMESIZE;j++){
                if(Page[i].name[j]!=name.data()[j]){
                    equal=0;
                    break;
                }
            }
            if(equal)
                break;
        }
    }
    if(equal)
        return &Page[i];
    return NULL;
}

int FPage::Shownowall()
{
    int sum=0;
    for(int i=0;i<FILEPAGENUM;i++){
        if(Page[i].parentpos==currentpos){
            sum++;
            printf("%d page: %d : %d  %s\n",i,Page[i].thispos,Page[i].parentpos,Page[i].name);
        }
    }
    return sum;
}

void FPage::del(int thispos)
{
    int i=0;
    for(i=0;i<FILEPAGENUM;i++){
        if(Page[i].parentpos==thispos){
            del(i);
            if(Page[i].attribute==ATTR_READ||Page[i].attribute==ATTR_WRITE){
                FileM::filem->DeleteF(Page[i]);
            }
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
