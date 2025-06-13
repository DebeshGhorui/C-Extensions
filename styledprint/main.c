#include "include/styledprint.h"

int main() {
    // Test all main functions
    printStyled("Hello %s! Score: %d", "blue", "white", "bold", "Alice", 95);
    printSuccess("Operation completed in %.2f seconds", 1.23);
    printWarning("Memory usage: %d%%", 85);
    printError("Connection timeout after %d attempts", 3);
    
    // Test different combinations
    printStyled("Rainbow text!", "magenta", "yellow", "underline");
    return 0;
}