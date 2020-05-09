//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_TABWORLDUNIT_H
#define ABWORLD_TABWORLDUNIT_H


#include <string>
#include "TabObj3D.h"
#include "TBufEC.h"

class TabWorldUnit {
public:
    TabWorldUnit* FPrev;
    TabWorldUnit* FNext;
    std::string FFileName;
    bool FSel;

    TabObj3D FGraphSel;
    TabObj3D FGraphSelBB;

    uint FNo;

    uint FType;
    uint FTimeOffset;
    uint FTimeLength;
    uint FKeyGroup;

    D3DVECTOR FCenter;
    bool FDraw;

    int FBBState; // 0=-1 0=rebuild 1=yes
    TabWorldUnitBB FBB[3];
    void LoadWorld(TBufEC &buf);
    TDxyz CalcCenter();

};


#endif //ABWORLD_TABWORLDUNIT_H
