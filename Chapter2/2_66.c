#include <stdio.h>

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    unsigned mask = ((~x) >> 1) & x;
    return (int) (mask & x);
}

int main() {
    printf("%d\n", leftmost_one(1030));
}