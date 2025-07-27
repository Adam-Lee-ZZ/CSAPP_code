#include <stdio.h>

int any_1(int x) {
    return x != 0;
}

int any_0(int x) {
    return x != -1;
}

int any_1_least(int x) {
    return ((x & 0xFF) != 0x00);
}

int any_0_most(int x) {
    return ((x >> (((sizeof(int)-1) << 3)) & 0xFF) != 0xFF);
}

int main() {
    printf("%d\n", any_0(0x12345678));
}