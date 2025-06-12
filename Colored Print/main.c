#include <stdio.h>
#include <stdlib.h>
#include "include/textprint.h"

int main() {
    // Test different colors and styles
    printuf("Hello, World!", "red", NULL, "bold");
    printuf("Hello, World!", "green", NULL, NULL);
    printuf("Hello, World!", "blue", "white", "bold");
    printuf("Hello, World!", "magenta", NULL, "italic");
    printuf("Hello, World!", "cyan", "black", "underline");
    printuf("Hello, World!", "white", NULL, NULL);
    printuf("Hello, World!", "gray", NULL, "bold");
    printuf("Hello, World!", NULL, NULL, NULL);  // Default color

    return 0;
}