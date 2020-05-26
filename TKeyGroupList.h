//
// Created by desuex on 09.05.2020.
//

#ifndef ABWORLD_TKEYGROUPLIST_H
#define ABWORLD_TKEYGROUPLIST_H


#include <list>
#include <string>
#include "TabWorldUnit.h"

typedef struct TKeyGroup {
    std::string FName;
} TKeyGroup;

class TKeyGroupList {
public:
    int FNo{};
    std::list<TKeyGroup> FList;
    int FCur;
    void *FOwner;

    void LoadWorld(TBufEC &buf);
//    TKeyGroup Insert(int no);
};


#endif //ABWORLD_TKEYGROUPLIST_H
