//
// Created by desuex on 08.05.2020.
//

#include "WorldUnit.h"

void WorldUnit::LoadWorld(TBufEC &buf) {
    int cnt = buf.GetUINT32();
    for (int i = 0; i < cnt; i++) {
        WorldUnit_Add(buf, i);
    }
}

TabWorldUnit* WorldUnit::WorldUnit_Add(TBufEC &buf, int i) {
    TabWorldUnit* el = new TabWorldUnit();
    el->FNo = i;
    el->LoadWorld(buf);
    if (WorldUnit_Last_initialized) {
        WorldUnit_Last->FNext = el;
        el->FPrev = WorldUnit_Last;
    }
    WorldUnit_Last = el;
    WorldUnit_Last_initialized = true;
    if (!WorldUnit_First_initialized) {
        this->WorldUnit_First = el;
        this->WorldUnit_First_initialized = true;
    }

    return el;
}

TabWorldUnit *WorldUnit::WorldUnit_ByNo(int no) const {
    TabWorldUnit *el = this->WorldUnit_First;
    while (el) {
        if (el->FNo == no) {
            return el;
        }
        el = el->FNext;
    }

    return nullptr;
}

void WorldUnit::WorldUnit_CalcCenter() const {
    TabWorldUnit *el;
    el = WorldUnit_First;
    while (el) {
        el->CalcCenter();
        el = el->FNext;
    }
}
