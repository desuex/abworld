//
// Created by desuex on 09.05.2020.
//

#include "TTriangleAB.h"


void TTriangleAB::LoadWorld(TBufEC &buf, WorldUnit &worldUnit, ABPoint &abPoint) {
    FTexture = buf.GetWideStr();
    std::cout<<"FTexture: "<<FTexture<<std::endl;
    FBackFace = buf.GetBoolean();
    std::cout<<"FBackFace: "<<FBackFace<<std::endl;
    int no = buf.GetUINT32();
    std::cout<<"no: "<<no<<std::endl;
    FOwner = worldUnit.WorldUnit_ByNo(no);
    FV = new TTriangleUnitAB[2];

    for (int i=0; i<3;i++){
        int pointNo = buf.GetUINT32();
        std::cout<<"pointNo: "<<pointNo<<std::endl;
        FV[i].FVer = abPoint.Point_ByNo(pointNo);
        FV[i].FU = buf.GetSingle();
        FV[i].FV = buf.GetSingle();
        std::string fcolor = buf.GetWideStr();
        std::cout<<"FColor: "<<fcolor<<std::endl;
        //TODO: LOAD
        FV[i].FColor.Load(fcolor);
    }
}
