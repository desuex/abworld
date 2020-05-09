//
// Created by desuex on 09.05.2020.
//

#include <cmath>
#include "Utils.h"

TDxyz *Utils::ab_CalcPos(float orb, float orban, xyzV radius) {
    TDxyz tv;
    tv.x = sin(orban)*radius;
    tv.y = -cos(orban)*radius;
    tv.z = 0;
    tv ={tv.x*sin(orb), tv.y, -cos(orb)*tv.x};
    return &tv ;
}

float Utils::Angle360ToRad(float angle) {

    return ( angle * M_PI) / 180;
}

double Utils::Angle360ToRad(double angle) {
    return ( angle * M_PI) / 180;
}

TDxyz Utils::Dxyz(xyzV x, xyzV y, xyzV z) {
    return TDxyz{x,y,z};
}
