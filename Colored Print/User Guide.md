# Text Print Library User Guide

## Overview
The `textprint.h` library provides functionality to print colored and styled text in the terminal. It supports various text colors, background colors, and text styles.

## Functions

### printuf()
```c
void printuf(const char* text, const char* textColor, const char* bgColor, const char* style)
```

#### Parameters:
- `text`: The text to print
- `textColor`: Text color (can be NULL for default white)
- `bgColor`: Background color (can be NULL for no background)
- `style`: Text style (can be NULL for default style)

## Available Colors

### Text Colors
- `"black"`
- `"red"`
- `"green"`
- `"yellow"`
- `"blue"`
- `"magenta"`
- `"cyan"`
- `"white"`
- `"gray"`

### Background Colors
- `"black"`
- `"red"`
- `"green"`
- `"yellow"`
- `"blue"`
- `"magenta"`
- `"cyan"`
- `"white"`

### Text Styles
- `"bold"`
- `"dim"`
- `"italic"`
- `"underline"`
- `"blink"`
- `"reverse"`
- `"hidden"`

## Usage Examples

```c
// Basic colored text
printuf("Hello World!", "red", NULL, NULL);

// Colored text with style
printuf("Bold Blue Text", "blue", NULL, "bold");

// Text with background
printuf("White on Black", "white", "black", NULL);

// Styled text with background
printuf("Complete Format", "yellow", "blue", "bold");

// Default text
printuf("Default Text", NULL, NULL, NULL);
```

## Notes
- If invalid color or style names are provided, defaults will be used
- Colors are case-insensitive ("RED" = "red" = "Red")
- Windows users may need to enable ANSI support with `system("color")`
- Always include `textprint.h` in your source file

## Compilation
```bash
gcc your_file.c -o program.exe
```

## Error Handling
- Empty text will display an error message
- Invalid colors/styles will fallback to defaults
- NULL parameters are handled gracefully