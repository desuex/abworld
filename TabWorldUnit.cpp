//
// Created by desuex on 08.05.2020.
//

#include "TabWorldUnit.h"
#include "TPointAB.h"
#include "Utils.h"

void TabWorldUnit::LoadWorld(TBufEC &buf) {
    FFileName = buf.GetWideStr();
    std::cout<<"FFileName: "<<FFileName<<std::endl;
    FType = buf.GetUINT32();
    std::cout<<"FType: "<<FType<<std::endl;
    FTimeOffset = buf.GetUINT32();
    std::cout<<"FTimeOffset: "<<FTimeOffset<<std::endl;
    FKeyGroup = buf.GetUINT32();
    std::cout<<"FKeyGroup: "<<FKeyGroup<<std::endl;
//    if GLoadVersion>=3 then
    FTimeLength = buf.GetUINT32();
    std::cout<<"FTimeLength: "<<FTimeLength<<std::endl;
    std::cout<<"FNo: "<<FNo<<std::endl;

}

TDxyz TabWorldUnit::CalcCenter() {
    TPointAB apo;
    TDxyz center = Utils::Dxyz(0,0,0);

    return TDxyz();
}
