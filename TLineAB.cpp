//
// Created by desuex on 09.05.2020.
//

#include "TLineAB.h"

void TLineAB::LoadWorld(TBufEC &buf, WorldUnit &worldUnit, ABPoint &abPoint) {
    int verStartNo = buf.GetUINT32();
    std::cout << "verStartNo " << verStartNo << std::endl;
    FVerStart = abPoint.Point_ByNo(verStartNo);
    int verEndNo = buf.GetUINT32();
    std::cout << "verEndNo " << verEndNo << std::endl;
    FVerEnd = abPoint.Point_ByNo(verEndNo);
    std::string colorStart = buf.GetWideStr();
    std::cout << "colorStart " << colorStart << std::endl;
    FColorStart->Load(colorStart);
    std::string colorEnd = buf.GetWideStr();
    std::cout << "colorEnd " << colorEnd << std::endl;
    FColorEnd->Load(colorEnd);
    bool show = buf.GetBoolean();
    std::cout << "show " << show << std::endl;
    FShow = show;
    bool stopLine = buf.GetBoolean();
    std::cout << "stopLine " << stopLine << std::endl;
    FStopLine = stopLine;
    int worldUnitNo = buf.GetUINT32();
    std::cout << "worldUnitNo " << worldUnitNo << std::endl;
    FOwner = worldUnit.WorldUnit_ByNo(worldUnitNo);

}
