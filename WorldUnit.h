//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_WORLDUNIT_H
#define ABWORLD_WORLDUNIT_H


#include "TBufEC.h"
#include "TabWorldUnit.h"

class WorldUnit {
public:
    TabWorldUnit *WorldUnit_First{};
    bool WorldUnit_First_initialized = false;
    TabWorldUnit *WorldUnit_Last{};
    bool WorldUnit_Last_initialized = false;

    void LoadWorld(TBufEC &buf);

    TabWorldUnit *WorldUnit_ByNo(int no) const;

    TabWorldUnit *WorldUnit_Add(TBufEC &buf, int i);

    void WorldUnit_CalcCenter() const;
};


#endif //ABWORLD_WORLDUNIT_H
