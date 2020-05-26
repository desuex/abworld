//
// Created by desuex on 09.05.2020.
//

#include <cmath>
#include "TabZone.h"
#include "Utils.h"

void TabZone::LoadWorld(TBufEC &buf, xyzV ab_WorldRadius) {
    FOrb = buf.GetFloat();

    FOrbAngle = buf.GetFloat();

    FRadiusAngle = buf.GetFloat();

    FType = buf.GetUINT32();

    FGraph = buf.GetWideStr();

    FHitpoints = buf.GetUINT32();

    FMass = buf.GetUINT32();

    FDamage = buf.GetUINT32();

    //if GLoadVersion>=2
    FItem = buf.GetUINT32();

    FItemFreq = buf.GetUINT32();

    //endif
    CalcPos(ab_WorldRadius);



}

void TabZone::CalcPos(xyzV ab_WorldRadius) {
    // l=((pi*r)/180)*n
    // n=l/((pi*r)/180)
    FRadius = M_PI * ab_WorldRadius * FRadiusAngle / 180;
    FPos = Utils::ab_CalcPos(Utils::Angle360ToRad(FOrb), Utils::Angle360ToRad(FOrbAngle), ab_WorldRadius);
}
