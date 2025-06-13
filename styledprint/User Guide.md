# StyledPrint User Guide

## Overview

**StyledPrint** is a header-only C library for printing styled and colored text to the terminal using ANSI escape codes.

## Features

- Print text with custom foreground and background colors.
- Apply text styles: bold, dim, italic, underline, blink, reverse, hidden.
- Predefined helpers for success, warning, and error messages.
- Header-only: just include and use.


## Usage

### 1. Basic Styled Print

```c
printStyled("Hello, %s!", "cyan", "black", "bold", "World");
```
- **Arguments:**
  - `text`: Format string (like `printf`)
  - `textColor`: "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white", "gray"
  - `bgColor`: Same as above, or `NULL` for no background
  - `style`: "bold", "dim", "italic", "underline", "blink", "reverse", "hidden", or `NULL`
  - Additional arguments: as required by the format string

### 2. Predefined Helpers

```c
printSuccess("Operation completed successfully: %d items.", 42);
printWarning("Warning: Disk space low!");
printError("Error: File not found: %s", filename);
```


## Examples

```c
printStyled("Bold Red on Yellow", "red", "yellow", "bold");
printStyled("Dim Blue", "blue", NULL, "dim");
printStyled("Italic Green", "green", NULL, "italic");
printStyled("Gray text", "gray", NULL, NULL);
```


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


## Notes

- If you pass `NULL` or an empty string as the text, an error message will be printed.
- If you pass an unknown color or style, defaults are used (white color, reset style).
- Works on most Unix-like terminals and Windows 10+ terminals that support ANSI codes.
- Colors are case-insensitive ("RED" = "red" = "Red")
- Windows users may need to enable ANSI support with `system("color")`


## Compilation
```bash
gcc your_file.c -o program.exe
```

## Error Handling
- Empty text will display an error message
- Invalid colors/styles will fallback to defaults
- NULL parameters are handled gracefully