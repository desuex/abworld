//
// Created by desuex on 09.05.2020.
//

#include "TKeyGroupList.h"

void TKeyGroupList::LoadWorld(TBufEC &buf) {
    FCur = static_cast<TabWorldUnit *>(this->FOwner)->FKeyGroup;
    int cnt = buf.GetUINT32();

    for (int i = 0; i < cnt; i++) {
        TKeyGroup group = {buf.GetWideStr()};
        FList.push_front(group);
    }

}


