//
// Created by desuex on 09.05.2020.
//

#include "TTriangleAB.h"


void TTriangleAB::LoadWorld(TBufEC &buf, WorldUnit &worldUnit, ABPoint &abPoint) {
    FTexture = buf.GetWideStr();

    FBackFace = buf.GetBoolean();

    int no = buf.GetUINT32();

    FOwner = worldUnit.WorldUnit_ByNo(no);

    for (auto &i : FV) { //dabious magic High(FV)
        i = new TTriangleUnitAB();
        int pointNo = buf.GetUINT32();

        i->FVer = abPoint.Point_ByNo(pointNo);
        i->FU = buf.GetSingle();
        i->FV = buf.GetSingle();
        std::string fcolor = buf.GetWideStr();

        //TODO: LOAD
        i->FColor.Load(fcolor);
        i->WColor = fcolor;
    }
}
