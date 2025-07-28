#include <stdio.h>

int int_size_is_32() {
    unsigned int x = ~0;
    x >>= 31;
    return x == 1;
}

int main(){
    printf("%d\n", int_size_is_32());
}