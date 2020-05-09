//
// Created by desuex on 09.05.2020.
//

#include "TPointAB.h"
#include "Utils.h"

void TPointAB::LoadWorld(TBufEC &buf, WorldUnit &worldUnit) {
    FId = buf.GetWideStr();
    std::cout<<"FId: "<<FId<<std::endl;
    FOrbit = buf.GetSingle();
    std::cout<<"FOrbit: "<<FOrbit<<std::endl;
    FOrbitAngle = buf.GetSingle();
    std::cout<<"FOrbitAngle: "<<FOrbitAngle<<std::endl;
    FRadius = buf.GetSingle();
    std::cout<<"FRadius: "<<FRadius<<std::endl;
    FParent = new TPointAB();
    int FParentNum = buf.GetUINT32();
    std::cout<<"FParentNum: "<<FParentNum<<std::endl;
    FPortId = buf.GetWideStr();
    std::cout<<"FPortId: "<<FPortId<<std::endl;
    FPortType = buf.GetWideStr();
    std::cout<<"FPortType: "<<FPortType<<std::endl;
    FPortLink = buf.GetWideStr();
    std::cout<<"FPortLink: "<<FPortLink<<std::endl;
    FCopyPortId = buf.GetWideStr();
    std::cout<<"FCopyPortId: "<<FCopyPortId<<std::endl;
    FCopyPortType = buf.GetWideStr();
    std::cout<<"FCopyPortType: "<<FCopyPortType<<std::endl;
    FCopyPortLink = buf.GetWideStr();
    std::cout<<"FCopyPortLink: "<<FCopyPortLink<<std::endl;

    int cnt = buf.GetUINT32();

    std::cout<<"cnt: "<<cnt<<std::endl;
    for (int i = 0; i<cnt; i++) {
        int ownerNo = buf.GetUINT32();
        std::cout<<"ownerNo: "<<ownerNo<<std::endl;
        TabWorldUnit * unit = worldUnit.WorldUnit_ByNo(ownerNo);
        FOwner.push_front(unit);
    }
    CalcPos();
}

void TPointAB::CalcPos() {
    FPos = Utils::ab_CalcPos(Utils::Angle360ToRad(FOrbit), Utils::Angle360ToRad(FOrbitAngle), FRadius);
    std::cout<<"FPos: x: "<< FPos->x<<" y: "<<FPos->y<<" z: "<<FPos->z<<std::endl;
}

