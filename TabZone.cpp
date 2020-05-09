//
// Created by desuex on 09.05.2020.
//

#include <cmath>
#include "TabZone.h"
#include "Utils.h"

void TabZone::LoadWorld(TBufEC &buf, xyzV ab_WorldRadius) {
    FOrb = buf.GetFloat();
    std::cout<<"FOrb: "<<FOrb<<std::endl;
    FOrbAngle = buf.GetFloat();
    std::cout<<"FOrbAngle: "<<FOrbAngle<<std::endl;
    FRadiusAngle = buf.GetFloat();
    std::cout<<"FRadiusAngle: "<<FRadiusAngle<<std::endl;
    FType = buf.GetUINT32();
    std::cout<<"FType: "<<FType<<std::endl;
    FGraph = buf.GetWideStr();
    std::cout<<"FGraph: "<<FGraph<<std::endl;
    FHitpoints = buf.GetUINT32();
    std::cout<<"FHitpoints: "<<FHitpoints<<std::endl;
    FMass = buf.GetUINT32();
    std::cout<<"FMass: "<<FMass<<std::endl;
    FDamage = buf.GetUINT32();
    std::cout<<"FDamage: "<<FDamage<<std::endl;
    //if GLoadVersion>=2
    FItem = buf.GetUINT32();
    std::cout<<"FItem: "<<FItem<<std::endl;
    FItemFreq = buf.GetUINT32();
    std::cout<<"FItemFreq: "<<FItemFreq<<std::endl;
    //endif
    CalcPos(ab_WorldRadius);



}

void TabZone::CalcPos(xyzV ab_WorldRadius) {
    // l=((pi*r)/180)*n
    // n=l/((pi*r)/180)
    FRadius = (M_PI * ab_WorldRadius * FRadiusAngle)/180;
    FPos = Utils::ab_CalcPos(Utils::Angle360ToRad(FOrb), Utils::Angle360ToRad(FOrbAngle), ab_WorldRadius);
}
