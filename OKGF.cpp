//
// Created by desuex on 08.05.2020.
//

#include "OKGF.h"

int OKGF::OKGF_ZLib_Compress(BYTE *desbuf, BYTE *soubuf, int len_sou_and_des_buf, int fSpeed) {
    DWORD deslen = len_sou_and_des_buf - 8;
    if (len_sou_and_des_buf < 16) return 0;
    if (compress2(desbuf + 8, &deslen, soubuf, len_sou_and_des_buf, fSpeed ? Z_BEST_SPEED : Z_BEST_COMPRESSION) !=
        Z_OK)
        return 0;
    *(desbuf + 0) = 'Z';
    *(desbuf + 1) = 'L';
    *(desbuf + 2) = '0';
    *(desbuf + 3) = '1';
    *((DWORD * )(desbuf + 4)) = len_sou_and_des_buf;
    return deslen + 8;
}

int OKGF::OKGF_ZLib_UnCompress(BYTE *desbuf, int lendesbuf, BYTE *soubuf, int lensoubuf) {
    DWORD deslen=lendesbuf;

    if(lensoubuf<8) return 0;
    if(*(soubuf+0)!='Z' || *(soubuf+1)!='L' || *(soubuf+2)!='0' || *(soubuf+3)!='2') return 0;
    if(desbuf==nullptr) return *((DWORD *)(soubuf+4));
    if(*((DWORD *)(soubuf+4))>DWORD(lendesbuf)) return 0;

    if(uncompress(desbuf,&deslen,soubuf+8,lensoubuf-8)!=Z_OK) return 0;
    if(deslen!=*((DWORD *)(soubuf+4))) return 0;
    return deslen;
}
