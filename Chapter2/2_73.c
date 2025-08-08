#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y) {
    int sum = x + y;

    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int sign_sum = sum >> 31;

    // overflow occurs if x and y have the same sign, but sum has a different sign
    int overflow = ~(sign_x ^ sign_y) & (sign_x ^ sign_sum);

    int pos_overflow = INT_MAX;
    int neg_overflow = INT_MIN;

    int sat_value = (sign_x & neg_overflow) | (~sign_x & pos_overflow);

    return (overflow & sat_value) | (~overflow & sum);
}

int main() {
    int test_cases[][2] = {
        {100, 200},
        {INT_MAX, 1},
        {INT_MIN, -1},
        {-50000, -100000},
        {INT_MAX, -1},
        {INT_MIN, 1}
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        int x = test_cases[i][0];
        int y = test_cases[i][1];

        int result = saturating_add(x, y);

        printf("x = %d, y = %d\n", x, y);
        printf("saturating_add(x, y) = %d\n", result);
        printf("----------\n");
    }

    return 0;
}
