#ifndef FPAGE_H
#define FPAGE_H
#include "Disk.h"
#include "Profiles.h"

class FPage :Disk
{
public:
    static int currentpos;
    static FPage* fpage;
    FPage();
    int MakeOFTLE(OFTLE& tomake);
    int DeleteOFTLE(OFTLE& toDelete);
    int ShowSonOFTLE(OFTLE& toShow);
    int TurnInto(OFTLE& into);
    int TurnBack();
    int ChangeFTLEtoP(OFTLE& change);
    OFTLE* MakePage(string name);
    void CheckPage();

    OFTLE* SelectOFTLE(string name);
    int Shownowall();

private:
    void del(int thispos);
    int findempty();

};

#endif // FPAGE_H
