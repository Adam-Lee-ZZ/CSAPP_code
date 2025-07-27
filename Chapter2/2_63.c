#include <stdio.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    unsigned mask = ~0U >> k;
    return xsra & mask;
}

int sra(int x, int k) {
    unsigned xsrl = (unsigned) x >> k;
    unsigned sign = (1 << 31) & x;
    int mask = (int) sign >> k;
    return (int) xsrl | mask;
}


int main() {
    int test_vals[] = {
        0x00000000,
        0x00000001,
        0x80000000,
        0xFFFFFFFF,
        0x12345678,
        0xFEDCBA98
    };

    int shifts[] = {0, 1, 4, 8, 16, 31};

    for (int i = 0; i < sizeof(test_vals)/sizeof(test_vals[0]); i++) {
        for (int j = 0; j < sizeof(shifts)/sizeof(shifts[0]); j++) {
            int x = test_vals[i];
            int k = shifts[j];
            int ref = x >> k;
            int mine = sra(x, k);
            printf("x=0x%08X, k=%2d | x>>k=0x%08X, sra=0x%08X | %s\n",
                   x, k, ref, mine, (ref == mine ? "OK" : "WRONG"));
        }
    }
    return 0;
}