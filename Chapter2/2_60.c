#include <stdio.h>

typedef unsigned char *BYTE;

int is_little_endian() {
    int x = 1;
    return *((char *)&x) == 1;
}

unsigned replaceByte(unsigned x, int i, unsigned char b) {
    BYTE pin = (BYTE) &x;
    if (is_little_endian()) {
        pin[i] = b;
    }else {
        pin[sizeof(unsigned)-1-i] = b;
    }
    return x;
}

unsigned replaceByte_portable(unsigned x, int i, unsigned char b) {
    unsigned mask = 0xFF << (i * 8);
    unsigned insert = ((unsigned)b) << (i * 8);
    return (x & ~mask) | insert;
}


void main() {
    unsigned out = replaceByte_portable(0x12345678, 2, 0xAB);
    printf("%x\n", out);
}