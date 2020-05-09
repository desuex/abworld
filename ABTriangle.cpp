//
// Created by desuex on 09.05.2020.
//

#include "ABTriangle.h"
#include "TTriangleAB.h"

void ABTriangle::Triangle_LoadWorld(TBufEC &buf, WorldUnit &worldUnit, ABKey &abKey, ABPoint &abPoint) {
    int cnt = buf.GetUINT32();
    TTriangleAB *el;
    std::cout<<"Triangle count: "<<cnt<<std::endl;
    for (int i =0; i<cnt;i++) {
        int no = buf.GetUINT32();
        TKeyGroupList gl = abKey.KeyGroupList_ByNom(no);
        el = Triangle_Add(gl);
        el->LoadWorld(buf, worldUnit, abPoint);
    }
}

TTriangleAB *ABTriangle::Triangle_Add(TKeyGroupList &gl) {
    TTriangleAB *el;
    el = new TTriangleAB();
    if (Triangle_Last){
        Triangle_Last = el;
    }
    el->FPrev = Triangle_Last;
    if (!Triangle_First){
        Triangle_First = el;
    }
    Triangle_Last = el;
    return el;
}
