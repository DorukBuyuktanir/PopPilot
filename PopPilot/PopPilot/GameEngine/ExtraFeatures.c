#include "Imports.h"

bool functionEmpty(void (*func)()) {
    unsigned char* ptr = (unsigned char*)func;
    size_t length = 0;

    unsigned char empty_body[] = { 0xc3 };//ret talimatý


    for (size_t i = 0; i < sizeof(empty_body); ++i)
        if (ptr[i] != empty_body[i])
            return false;
    return true;
}
