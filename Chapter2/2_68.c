#include <stdio.h>

int lower_one_mask(int n) {
    unsigned int mask = ~0;
    mask >>= sizeof(int) * 8 - n;
    return mask;
}

int main() {
    printf("%x\n", lower_one_mask(17));
}