//
// Created by desuex on 09.05.2020.
//

#include "TPointAB.h"
#include "Utils.h"

void TPointAB::LoadWorld(TBufEC &buf, WorldUnit &worldUnit) {
    FId = buf.GetWideStr();

    FOrbit = buf.GetSingle();

    FOrbitAngle = buf.GetSingle();

    FRadius = buf.GetSingle();

    FParent = new TPointAB();

    FParentNum = buf.GetUINT32();

    FPortId = buf.GetWideStr();

    FPortType = buf.GetWideStr();

    FPortLink = buf.GetWideStr();

    FCopyPortId = buf.GetWideStr();

    FCopyPortType = buf.GetWideStr();

    FCopyPortLink = buf.GetWideStr();


    int cnt = buf.GetUINT32();

    FOwnerCount = cnt;
    for (int i = 0; i < cnt; i++) {
        int ownerNo = buf.GetUINT32();

        TabWorldUnit *unit = worldUnit.WorldUnit_ByNo(ownerNo);
        FOwner.push_front(unit);
    }

    auto vect = Utils::ab_CalcPos(Utils::Angle360ToRad(FOrbit), Utils::Angle360ToRad(FOrbitAngle), FRadius);
    FPos = vect;
}


