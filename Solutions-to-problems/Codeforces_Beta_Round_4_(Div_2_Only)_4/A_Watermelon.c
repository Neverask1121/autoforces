#include <stdio.h>

int main() {
    int w;
    scanf("%d", &w);

    // The watermelon must be divisible into two parts with positive even weight.
    // This means the total weight 'w' must be an even number and greater than 2.
    if (w % 2 == 0 && w > 2) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}