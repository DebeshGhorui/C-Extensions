#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void print(char printStatement[], char color[], bool mode) {
    enum color {
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37,
        Gray = 90
    };

    int colorCode = White; // Default color code

    // Handle NULL or empty color input
    if (color != NULL && strlen(color) > 0) {
        // Convert color to lowercase for case-insensitive comparison
        char lowerColor[20];
        for (int i = 0; color[i] && i < sizeof(lowerColor) - 1; i++) {
            lowerColor[i] = tolower(color[i]);
            lowerColor[i + 1] = '\0';
        }

        if (strcmp(lowerColor, "red") == 0) colorCode = Red;
        else if (strcmp(lowerColor, "green") == 0) colorCode = Green;
        else if (strcmp(lowerColor, "yellow") == 0) colorCode = Yellow;
        else if (strcmp(lowerColor, "blue") == 0) colorCode = Blue;
        else if (strcmp(lowerColor, "magenta") == 0) colorCode = Magenta;
        else if (strcmp(lowerColor, "cyan") == 0) colorCode = Cyan;
        else if (strcmp(lowerColor, "gray") == 0) colorCode = Gray;
    }

    // Print the statement with the specified or default color and mode
    if (mode) {
        printf("\033[1;%dm%s\033[0m\n", colorCode, printStatement); // Bold mode
    } else {
        printf("\033[0;%dm%s\033[0m\n", colorCode, printStatement); // Normal mode
    }
}

int main() {
    print("Hello World!", NULL, false);         // Default usage (White, Normal mode)
    print("This is green text.", "Green", false); // Custom usage (Green, Normal mode)
    print("Yellow in bold!", "Yellow", true);     // Custom usage (Yellow, Bold mode)

    return 0;
}