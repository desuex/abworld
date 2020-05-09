//
// Created by desuex on 09.05.2020.
//

#include "TKeyGroupList.h"

void TKeyGroupList::LoadWorld(TBufEC &buf ) {
//    FCur = TabWorldUnit()
    int cnt = buf.GetUINT32();
    std::cout<<"CNT: "<<cnt<<std::endl;
    for (int i=0; i<cnt;i++){
        TKeyGroup group = {buf.GetWideStr()};
        FList.push_front(group);
    }

}


