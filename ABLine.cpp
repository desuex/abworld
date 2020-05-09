//
// Created by desuex on 09.05.2020.
//

#include "ABLine.h"


void ABLine::Line_LoadWorld(TBufEC &buf, ABKey &abKey, ABPoint &abPoint, WorldUnit &worldUnit) {
    TLineAB *el;
    int cnt = buf.GetUINT32();
    std::cout << "Line count: " << cnt << std::endl;
    for (int i = 0; i < cnt; i++) {
        int no = buf.GetUINT32();
        TKeyGroupList gl = abKey.KeyGroupList_ByNom(no);
        el = Line_Add(gl);
        el->LoadWorld(buf, worldUnit, abPoint);
    }

}

TLineAB *ABLine::Line_Add(TKeyGroupList &gl) {
    TLineAB *el;
    el = new TLineAB();
    if (Line_Last) {
        Line_Last->FNext = el;
    }
    el->FPrev = Line_Last;
    if (Line_First) {
        Line_First = el;
    }
    return el;
}
