#include <stdio.h>

int fits_bits(int x, int n) {
    int shift = 32 - n;
    return (x << shift >> shift) == x;
}

int main() {
    printf("%d\n", fits_bits(-1, 3));
}