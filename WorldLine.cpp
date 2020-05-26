//
// Created by desuex on 14.05.2020.
//


#include "WorldLine.h"

TabWorldLine *WorldLine::WorldLine_Add() {
    auto *el = new TabWorldLine();
    if (WorldLine_Last) {
        WorldLine_Last->FNext = el;
    }
    el->FPrev = WorldLine_Last;
    WorldLine_Last = el;
    if (!WorldLine_First) {
        WorldLine_First = el;
    }
    return el;

//    return TabWorldLine();
}

void WorldLine::SWLBuild(float ab_WorldRadius) const {
    int GWLCount = 32;
    TDxyz v1, v2;
    xyzV di;
    xyzV dtstep = (M_PI * 2) / GWLCount;
    xyzV distep = M_PI / GWLCount;
    xyzV dt = 0;
    while (dt < (M_PI * 2 - 0.001)) {
        di = distep * 2;
        while (di < (M_PI - distep * 2 - 0.001)) {
            v1 = Utils::ab_CalcPos(dt, di, ab_WorldRadius);
            v2 = Utils::ab_CalcPos(dt, di + distep, ab_WorldRadius);
            auto *worldLine = new WorldLine();
            TabWorldLine *wl = worldLine->WorldLine_Add();
            wl->FStart = &v1;
            wl->FEnd = &v2;
            wl->FFrontColor = 0xc0ffffff;
            wl->FBackColor = 0x00ffffff;
            FSWL->push_front(*wl);
            di += distep;

        }
        dt += dtstep;
    }
    distep *= 2;
    di = distep;
    while (di < (M_PI - distep * 2 + 0.001)) {
        dt = 0;
        while (dt < (2 * M_PI - 0.001)) {
            v1 = Utils::ab_CalcPos(dt, di, ab_WorldRadius);
            v2 = Utils::ab_CalcPos(dt + dtstep, di, ab_WorldRadius);
            auto *worldLine = new WorldLine();
            TabWorldLine *wl = worldLine->WorldLine_Add();
            wl->FStart = &v1;
            wl->FEnd = &v2;
            wl->FFrontColor = 0xc0ffffff;
            wl->FBackColor = 0x00ffffff;
            FSWL->push_front(*wl);
            dt += dtstep;
        }
        di += distep;
    }
}
