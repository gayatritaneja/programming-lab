#include <stdio.h>

// Declare a global variable
int global_counter = 10;

int main() {
    printf("Initial global_counter value: %d\n", global_counter);

    // Loop to reduce the global_counter
    for (int i = 0; i < 5; i++) {
        global_counter--; // Decrement the global variable
        printf("Inside loop, global_counter value: %d\n", global_counter);
    }

    printf("Final global_counter value: %d\n", global_counter);

    return 0;
}
