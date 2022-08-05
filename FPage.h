#ifndef FPAGE_H
#define FPAGE_H
#include "Disk.h"
#include "Profiles.h"

class FPage :Disk
{
public:
    int currentpos=0;
    FPage();
    int MakeOFTLE(OFTLE& tomake);
    int DeleteOFTLE(OFTLE& toDelete);
    int ShowSonOFTLE(OFTLE& toShow);
    int TurnInto(OFTLE& into);
    int ChangeFTLEtoP(OFTLE& change);
    void CheckPage();
private:
    void del(int thispos);
    int findempty();

};

#endif // FPAGE_H
