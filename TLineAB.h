//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TLINEAB_H
#define ABWORLD_TLINEAB_H


#include "TBufEC.h"
#include "TPointAB.h"
#include "TKeyAB.h"
#include "ABPoint.h"

class TLineAB {
public:
    TLineAB * FNext;
    TLineAB * FPrev;
    bool FShow;
    bool FStopLine;
    TPointAB *FVerStart;
    TPointAB *FVerEnd;
    TKeyAB *FColorStart;
    TKeyAB *FColorEnd;
    TabObj3D *FGraph;
    bool *FSel;
    TabWorldUnit *FOwner;
    void LoadWorld(TBufEC &buf, WorldUnit &worldUnit, ABPoint &abPoint);
};


#endif //ABWORLD_TLINEAB_H
