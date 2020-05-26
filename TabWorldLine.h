//
// Created by desuex on 14.05.2020.
//

#ifndef ABWORLD_TABWORLDLINE_H
#define ABWORLD_TABWORLDLINE_H


#include "windows.h"

class TabWorldLine {
public:
    TabWorldLine *FPrev;
    TabWorldLine *FNext;
    TDxyz *FStart;
    TDxyz *FEnd;
    DWORD FFrontColor;
    DWORD FBackColor;
    int FPointStart;
    int FPointEnd;



};


#endif //ABWORLD_TABWORLDLINE_H
