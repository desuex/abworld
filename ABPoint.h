//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_ABPOINT_H
#define ABWORLD_ABPOINT_H


#include "TBufEC.h"
#include "TPointAB.h"


class ABPoint {
public:
    TPointAB *Point_First;
    TPointAB *Point_Last;
    TPointAB **Point_List;
    void Point_LoadWorld(TBufEC &buf, WorldUnit &worldUnit);
    TPointAB* Point_Add();
    void Point_ListBuild();
    int Point_Cnt();
    TPointAB* Point_ByNo(int no);

};


#endif //ABWORLD_ABPOINT_H
