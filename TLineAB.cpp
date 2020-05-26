//
// Created by desuex on 09.05.2020.
//

#include "TLineAB.h"

void TLineAB::LoadWorld(TBufEC &buf, WorldUnit &worldUnit, ABPoint &abPoint) {
    int verStartNo = buf.GetUINT32();

    FVerStart = abPoint.Point_ByNo(verStartNo);
    int verEndNo = buf.GetUINT32();

    FVerEnd = abPoint.Point_ByNo(verEndNo);
    std::string colorStart = buf.GetWideStr();
    WColorStart = colorStart;

    FColorStart->Load(colorStart);
    std::string colorEnd = buf.GetWideStr();
    WColorEnd = colorEnd;

    FColorEnd->Load(colorEnd);
    bool show = buf.GetBoolean();

    FShow = show;
    bool stopLine = buf.GetBoolean();

    FStopLine = stopLine;
    int worldUnitNo = buf.GetUINT32();

    FOwner = worldUnit.WorldUnit_ByNo(worldUnitNo);

}
