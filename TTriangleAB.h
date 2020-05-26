//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TTRIANGLEAB_H
#define ABWORLD_TTRIANGLEAB_H
#include "TBufEC.h"
#include "TabObj3D.h"
#include "ABKey.h"
#include "TPointAB.h"
#include "TKeyAB.h"
#include "ABPoint.h"

typedef struct TTriangleUnitAB{
    TPointAB *FVer;
    float FU;
    float FV;
    TKeyAB FColor;
    std::string WColor;
    TabObj3D FSel;
} TTriangleUnitAB;
class TTriangleAB {
public:
    TTriangleAB *FPrev;
    TTriangleAB *FNext;
    TTriangleUnitAB* FV[3]={}; //TODO
    TabObj3D FGraph;
    std::string FTexture;
    std::string color;
    bool FBackFace;
    bool FSel;
    int FSelPoint;
    float FPickT;
    int FNo;
    TabWorldUnit *FOwner;
    void LoadWorld(TBufEC &buf, WorldUnit &worldUnit, ABPoint &abPoint);
};


#endif //ABWORLD_TTRIANGLEAB_H
