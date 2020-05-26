//
// Created by desuex on 08.05.2020.
//

#include "TabWorldUnit.h"
#include "TPointAB.h"
#include "Utils.h"

void TabWorldUnit::LoadWorld(TBufEC &buf) {
    FFileName = buf.GetWideStr();

    FType = buf.GetUINT32();

    FTimeOffset = buf.GetUINT32();

    FKeyGroup = buf.GetUINT32();

//    if GLoadVersion>=3 then
    FTimeLength = buf.GetUINT32();


}

TDxyz TabWorldUnit::CalcCenter() {
    TPointAB apo;
    TDxyz center = Utils::Dxyz(0, 0, 0);
    //TODO: something
    return TDxyz();
}
