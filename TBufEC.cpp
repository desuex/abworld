//
// Created by desuex on 08.05.2020.
//

#include "TBufEC.h"

TBufEC::TBufEC() = default;

void TBufEC::LoadFromFile(const std::string &filename) {
    file.open(filename, std::ios::in | std::ios::binary);

}
/**
 * 32 bit
 */
uint32_t TBufEC::GetUINT32() {
    uint32_t x;
    file.read((char* )&x, sizeof(x));
    return x;
}

DWORD TBufEC::GetDWORD() {
    DWORD x;
    file.read((char* )&x, sizeof(x));
    return x;
}
/**
 * 16 bit
 * @return
 */
uint16_t TBufEC::GetUINT16() {
    uint16_t x;
    file.read((char* )&x, sizeof(x));
    return x;
}
void TBufEC::MoveCursor(int val) {
    file.seekg (val, std::ios::cur);
}

WORD TBufEC::GetWORD() {
    WORD x;
    file.read((char* )&x, sizeof(x));
    return x;
}

float TBufEC::GetFloat() {
    float x;
    file.read((char* )&x, sizeof(x));
    return x;
}

float TBufEC::GetSingle() {
    return GetFloat();
}
uint16_t TBufEC::GetInteger() {
    return GetUINT16();
}
WCHAR TBufEC::GetWideChar() {
    WCHAR x;
    file.read((char* )&x, sizeof(x));
    return x;
}
std::string TBufEC::GetWideStr() {
    std::string result;
    wchar_t c;

    do{
        c = GetUINT16();
        result+=c;
//        if (result.length()>1){
            if (c == 0) {
                break;
            }
//        }

    } while (true);

    return result;
}

bool TBufEC::GetBoolean() {
    BYTE x;
    file.read((char* )&x, sizeof(x));
    return x;
}

void TBufEC::Close() {
    file.close();
}


