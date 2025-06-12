#ifndef TEXTPRINT_H
#define TEXTPRINT_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define text color codes
enum TextColor {
    TC_BLACK = 30,
    TC_RED = 31,
    TC_GREEN = 32,
    TC_YELLOW = 33,
    TC_BLUE = 34,
    TC_MAGENTA = 35,
    TC_CYAN = 36,
    TC_WHITE = 37,
    TC_GRAY = 90
};

// Define background color codes
enum BackgroundColor {
    BG_BLACK = 40,
    BG_RED = 41,
    BG_GREEN = 42,
    BG_YELLOW = 43,
    BG_BLUE = 44,
    BG_MAGENTA = 45,
    BG_CYAN = 46,
    BG_WHITE = 47
};

// Define text style codes
enum TextStyle {
    TS_RESET = 0,
    TS_BOLD = 1,
    TS_DIM = 2,
    TS_ITALIC = 3,
    TS_UNDERLINE = 4,
    TS_BLINK = 5,
    TS_REVERSE = 7,
    TS_HIDDEN = 8
};

int getTextColorCode(const char* color) {
    if (!color) return TC_WHITE;
    
    char lowerColor[20] = {0};
    strncpy(lowerColor, color, sizeof(lowerColor) - 1);
    for (int i = 0; lowerColor[i]; i++) {
        lowerColor[i] = tolower(lowerColor[i]);
    }

    if (strcmp(lowerColor, "black") == 0) return TC_BLACK;
    if (strcmp(lowerColor, "red") == 0) return TC_RED;
    if (strcmp(lowerColor, "green") == 0) return TC_GREEN;
    if (strcmp(lowerColor, "yellow") == 0) return TC_YELLOW;
    if (strcmp(lowerColor, "blue") == 0) return TC_BLUE;
    if (strcmp(lowerColor, "magenta") == 0) return TC_MAGENTA;
    if (strcmp(lowerColor, "cyan") == 0) return TC_CYAN;
    if (strcmp(lowerColor, "gray") == 0) return TC_GRAY;
    return TC_WHITE;
}

int getBackgroundColorCode(const char* color) {
    if (!color) return -1;  // No background color
    
    char lowerColor[20] = {0};
    strncpy(lowerColor, color, sizeof(lowerColor) - 1);
    for (int i = 0; lowerColor[i]; i++) {
        lowerColor[i] = tolower(lowerColor[i]);
    }

    if (strcmp(lowerColor, "black") == 0) return BG_BLACK;
    if (strcmp(lowerColor, "red") == 0) return BG_RED;
    if (strcmp(lowerColor, "green") == 0) return BG_GREEN;
    if (strcmp(lowerColor, "yellow") == 0) return BG_YELLOW;
    if (strcmp(lowerColor, "blue") == 0) return BG_BLUE;
    if (strcmp(lowerColor, "magenta") == 0) return BG_MAGENTA;
    if (strcmp(lowerColor, "cyan") == 0) return BG_CYAN;
    if (strcmp(lowerColor, "white") == 0) return BG_WHITE;
    return -1;
}

int getTextStyleCode(const char* style) {
    if (!style) return TS_RESET;
    
    char lowerStyle[20] = {0};
    strncpy(lowerStyle, style, sizeof(lowerStyle) - 1);
    for (int i = 0; lowerStyle[i]; i++) {
        lowerStyle[i] = tolower(lowerStyle[i]);
    }

    if (strcmp(lowerStyle, "bold") == 0) return TS_BOLD;
    if (strcmp(lowerStyle, "dim") == 0) return TS_DIM;
    if (strcmp(lowerStyle, "italic") == 0) return TS_ITALIC;
    if (strcmp(lowerStyle, "underline") == 0) return TS_UNDERLINE;
    if (strcmp(lowerStyle, "blink") == 0) return TS_BLINK;
    if (strcmp(lowerStyle, "reverse") == 0) return TS_REVERSE;
    if (strcmp(lowerStyle, "hidden") == 0) return TS_HIDDEN;
    return TS_RESET;
}

void printuf(const char* text, const char* textColor, const char* bgColor, const char* style) {
    if (!text || strlen(text) == 0) {
        printf("\033[0;31m[Error: No text provided]\033[0m\n");
        return;
    }

    int colorCode = getTextColorCode(textColor);
    int bgColorCode = getBackgroundColorCode(bgColor);
    int styleCode = getTextStyleCode(style);

    if (bgColorCode != -1) {
        printf("\033[%d;%d;%dm%s\033[0m\n", styleCode, colorCode, bgColorCode, text);
    } else {
        printf("\033[%d;%dm%s\033[0m\n", styleCode, colorCode, text);
    }
}

#endif // TEXTPRINT_H