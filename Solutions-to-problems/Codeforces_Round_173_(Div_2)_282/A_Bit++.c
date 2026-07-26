#include <stdio.h>
#include <string.h> // Required for strstr

int main() {
    int n; // Number of statements
    scanf("%d", &n);

    int x = 0; // Initial value of x

    for (int i = 0; i < n; i++) {
        char statement[4]; // To store the statement (e.g., "++X", "X--")
        scanf("%s", statement);

        // Check for "++" in the statement
        if (strstr(statement, "++") != NULL) {
            x++;
        } 
        // Otherwise, it must be "--"
        else {
            x--;
        }
    }

    printf("%d\n", x); // Print the final value of x

    return 0;
}