//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_ABKEY_H
#define ABWORLD_ABKEY_H


#include "TBufEC.h"
#include "WorldUnit.h"
#include "TKeyGroupList.h"

class ABKey {
public:
    std::list<TKeyGroupList *> KeyGroupList_List;

    void KeyGroupList_LoadWorld(TBufEC &buf, WorldUnit &worldUnit);

    TKeyGroupList *KeyGroupList_Add(TabWorldUnit *ow, int no);

    TKeyGroupList *KeyGroupList_ByNom(int no);
};


#endif //ABWORLD_ABKEY_H
