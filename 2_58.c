#include <stdio.h>

typedef unsigned char *BYTE;

int is_little_endian() {
    int x = 1;
    return *((char *)&x) == 1;
}

void main(){
    printf("%d", is_little_endian());
}