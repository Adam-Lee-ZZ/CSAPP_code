#include <stdio.h>

typedef unsigned char *BYTE;

void x_and_y(BYTE x, BYTE y) {
    BYTE start;
    BYTE end;
    int one = 1;

    if (!((*((char *)& one) == 1))) {
        start = x;
        end = y;
    }else {
        start = y;
        end = x;
    }

    size_t i;

    for (i = sizeof(int)-1; i >0; i--) {
        printf("%.2x ", start[i]);
    }
    printf("%.2x\n", end[i]);
}

void main() {
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x76543210;

    x_and_y((BYTE)&x, (BYTE)&y);
}