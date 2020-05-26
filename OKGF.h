//
// Created by desuex on 08.05.2020.
//

#ifndef ABWORLD_OKGF_H
#define ABWORLD_OKGF_H

#include "zlib.h"
#include "windows.h"
#include <sys/_types.h>
//#define NULL  __DARWIN_NULL
class OKGF {
    static int OKGF_ZLib_Compress(BYTE *desbuf, BYTE *soubuf, int len_sou_and_des_buf, int fSpeed);

public:
    static int OKGF_ZLib_UnCompress(BYTE * desbuf,int lendesbuf,BYTE * soubuf,int lensoubuf);
};


#endif //ABWORLD_OKGF_H
