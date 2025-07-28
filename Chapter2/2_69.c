#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    return (x << n) | (x >> (32 - n));
}

int main() {
    printf("%x\n", rotate_left(0x12345678, 4));
}