#include <stdio.h>

int int_shifts_are_arithmetic() {
    int test = -1;
    return test == (test >> 1);
}

int main() {
    printf("%d\n", int_shifts_are_arithmetic());
}
