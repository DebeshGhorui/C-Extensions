#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print(char printStatement[], char color[], bool mode)
{
    enum color
    {
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37,
        Gray = 90
    };

    int colorCode = White; // default color code

    // Check if color is provided; if not, use default color (White)
    if (strcmp(color, "red") == 0 || strcmp(color, "Red") == 0 || strcmp(color, "RED") == 0) colorCode = Red;
    else if (strcmp(color, "green") == 0 || strcmp(color, "Green") == 0 || strcmp(color, "GREEN") == 0) colorCode = Green;
    else if (strcmp(color, "yellow") == 0 || strcmp(color, "Yellow") == 0 || strcmp(color, "YELLOW") == 0) colorCode = Yellow;
    else if (strcmp(color, "blue") == 0 || strcmp(color, "Blue") == 0 || strcmp(color, "BLUE") == 0) colorCode = Blue;
    else if (strcmp(color, "magenta") == 0 || strcmp(color, "Magenta") == 0 || strcmp(color, "MAGENTA") == 0) colorCode = Magenta;
    else if (strcmp(color, "cyan") == 0 || strcmp(color, "Cyan") == 0 || strcmp(color, "CYAN") == 0) colorCode = Cyan;
    else if (strcmp(color, "gray") == 0 || strcmp(color, "Gray") == 0 || strcmp(color, "GRAY") == 0) colorCode = Gray;

    // Print the statement with the specified or default color and mode
    if (mode) {
        printf("\033[1;%dm%s\033[0m\n", colorCode, printStatement); // Bold mode
    } else {
        printf("\033[0;%dm%s\033[0m\n", colorCode, printStatement); // Normal mode
    }
    
}

int main()
{

    print("Hello World!", "red", true);

    return 0;
}