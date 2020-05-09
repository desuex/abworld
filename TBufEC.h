//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_TBUFEC_H
#define ABWORLD_TBUFEC_H

#include "ZLIB/ZLIB/zlib.h"
#include "windows.h"
#include <sys/_types.h>
#include <string>
#include<iostream>
#include<fstream>

class TBufEC {
private:
    int len{};
    std::ifstream file;
public:
    TBufEC();
    /**
     * 32 bit
     * @return
     */
    DWORD GetDWORD();
    WORD GetWORD();
    bool GetBoolean();
    uint16_t GetUINT16();
    uint16_t GetInteger();
    uint32_t GetUINT32();
    std::string GetWideStr();
    WCHAR GetWideChar();

    float GetFloat();
    float GetSingle();
    void LoadFromFile(const std::string &filename);
    void MoveCursor(int val);

    void Close();
};


#endif //ABWORLD_TBUFEC_H
