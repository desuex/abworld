//
// Created by desuex on 09.05.2020.
//

#include "ABKey.h"
#include "TKeyGroupList.h"

void ABKey::KeyGroupList_LoadWorld(TBufEC &buf, WorldUnit &worldUnit) {
    TKeyGroupList el;
    int cnt = buf.GetUINT32();
    for (int i = 0; i < cnt; i++) {
        uint32_t no = buf.GetUINT32();
        std::cout << "NO: "<<no<<std::endl;
        TabWorldUnit *next = worldUnit.WorldUnit_ByNo(no);

        el = KeyGroupList_Add(next);
        el.FNo = i+1;
        el.LoadWorld(buf);
    }
}

TKeyGroupList ABKey::KeyGroupList_Add(TabWorldUnit *ow) {
    TKeyGroupList gl = TKeyGroupList();
    gl.FOwner = ow;
    KeyGroupList_List.push_front(gl);
    return gl;
}

TKeyGroupList ABKey::KeyGroupList_ByNom(int no) {
    for (int i = 0; i<KeyGroupList_List.size();i++){
        //TODO: NOT IMPLEMENTED
//        if (KeyGroupList_List)
    }
    return TKeyGroupList();
}
