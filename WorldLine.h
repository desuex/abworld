//
// Created by desuex on 14.05.2020.
//

#ifndef ABWORLD_WORLDLINE_H
#define ABWORLD_WORLDLINE_H


#include "TabWorldLine.h"
#include "TabObj3D.h"
#include "TabWorldLine.h"
#include "windows.h"
#include "Utils.h"
#include "WorldLine.h"
#include <math.h>
#include <list>

class WorldLine {
public:
    std::list<TabWorldLine> *FSWL;
    TabWorldLine *WorldLine_First;
    TabWorldLine *WorldLine_Last;
    TabObj3D *WorldLine_Grap;
    bool WorldLine_Rebuild{};

    TabWorldLine *WorldLine_Add();

    void SWLBuild(float ab_WorldRadius) const;
};


#endif //ABWORLD_WORLDLINE_H
