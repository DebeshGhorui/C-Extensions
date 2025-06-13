#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

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

// Function declarations (made static inline for header-only usage)
static int getTextColorCode(const char* color);
static int getBackgroundColorCode(const char* color);
static int getTextStyleCode(const char* style);
static void printStyled(const char* text, const char* textColor, const char* bgColor, const char* style, ...);
static void printSuccess(const char* text, ...);
static void printWarning(const char* text, ...);
static void printError(const char* text, ...);

// Function implementations

static int getTextColorCode(const char* color) {
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
    if (strcmp(lowerColor, "white") == 0) return TC_WHITE;  // Added explicit white case
    if (strcmp(lowerColor, "gray") == 0) return TC_GRAY;
    return TC_WHITE;
}

static int getBackgroundColorCode(const char* color) {
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

static int getTextStyleCode(const char* style) {
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

static void printStyled(const char* text, const char* textColor, const char* bgColor, const char* style, ...) {
    if (!text || strlen(text) == 0) {
        printf("\033[0;31m[Error: No text provided]\033[0m\n");
        return;
    }

    int colorCode = getTextColorCode(textColor);
    int bgColorCode = getBackgroundColorCode(bgColor);
    int styleCode = getTextStyleCode(style);

    // Set up formatting
    if (bgColorCode != -1) {
        printf("\033[%d;%d;%dm", styleCode, colorCode, bgColorCode);
    } else {
        printf("\033[%d;%dm", styleCode, colorCode);
    }
    
    // Handle variable arguments like printf
    va_list args;
    va_start(args, style);
    vprintf(text, args);
    va_end(args);
    
    // Reset formatting and add newline
    printf("\033[0m\n");
}

static void printSuccess(const char* text, ...) {
    if (!text || strlen(text) == 0) {
        printf("\033[0;31m[Error: No text provided]\033[0m\n");
        return;
    }

    printf("\033[32m");  // Green color
    
    va_list args;
    va_start(args, text);
    vprintf(text, args);
    va_end(args);
    
    printf("\033[0m\n");
}

static void printWarning(const char* text, ...) {
    if (!text || strlen(text) == 0) {
        printf("\033[0;31m[Error: No text provided]\033[0m\n");
        return;
    }

    printf("\033[33m");  // Yellow color
    
    va_list args;
    va_start(args, text);
    vprintf(text, args);
    va_end(args);
    
    printf("\033[0m\n");
}

static void printError(const char* text, ...) {
    if (!text || strlen(text) == 0) {
        printf("\033[0;31m[Error: No text provided]\033[0m\n");
        return;
    }

    printf("\033[31m");  // Red color
    
    va_list args;
    va_start(args, text);
    vprintf(text, args);
    va_end(args);
    
    printf("\033[0m\n");
}

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