# 🎨 StyledPrint Library User Guide

> **Transform your boring terminal output into colorful, styled masterpieces!**

Welcome to `styledprint.h` - the easiest way to add colors, backgrounds, and styles to your C console applications. No complex setup, no external dependencies - just include and go!

---

## 🚀 Quick Start

### Installation
Simply download `styledprint.h` and include it in your project:

```c
#include "styledprint.h"

int main() {
    printSuccess("🎉 StyledPrint is ready to use!");
    return 0;
}
```

**That's it!** No linking, no makefiles, no configuration needed.

---

## 🎯 Core Functions

### 1. `printStyled()` - The Swiss Army Knife
**The most powerful function** - customize everything!

```c
printStyled(text, textColor, backgroundColor, style, ...);
```

**Example:**
```c
printStyled("Hello %s! You scored %d points!", "green", "black", "bold", "Alice", 150);
```

### 2. `printSuccess()` - For Good News 🟢
Pre-styled in **green** for success messages.

```c
printSuccess("File saved successfully!");
printSuccess("User %s logged in at %s", username, timestamp);
```

### 3. `printWarning()` - For Cautions 🟡
Pre-styled in **yellow** for warnings.

```c
printWarning("Low disk space: %d%% remaining", diskSpace);
printWarning("Connection unstable - retrying...");
```

### 4. `printError()` - For Problems 🔴
Pre-styled in **red** for errors.

```c
printError("Failed to open file: %s", filename);
printError("Invalid input: expected number, got '%s'", userInput);
```

---

## 🎨 Available Colors

### Text Colors
| Color | Usage |
|-------|-------|
| `"black"` | Dark text |
| `"red"` | Error messages, alerts |
| `"green"` | Success, positive feedback |
| `"yellow"` | Warnings, cautions |
| `"blue"` | Information, links |
| `"magenta"` | Highlights, special text |
| `"cyan"` | Headers, cool accents |
| `"white"` | Normal text, high contrast |
| `"gray"` | Subdued text, comments |

### Background Colors
Same colors available for backgrounds! Use `NULL` for no background.

```c
printStyled("White text on blue background", "white", "blue", "bold");
printStyled("No background", "red", NULL, "underline");
```

---

## ✨ Available Styles

| Style | Effect | Perfect For |
|-------|--------|-------------|
| `"bold"` | **Bold text** | Headings, important info |
| `"dim"` | Dimmed text | Less important info |
| `"italic"` | *Italic text* | Emphasis, quotes |
| `"underline"` | <u>Underlined text</u> | Links, key terms |
| `"blink"` | Blinking text | Urgent alerts |
| `"reverse"` | Inverted colors | Highlights |
| `"hidden"` | Hidden text | Passwords, secrets |
| `NULL` or `"reset"` | Normal text | Default styling |

---

## 💡 Real-World Examples

### Application Startup
```c
#include "styledprint.h"

int main() {
    printStyled("🚀 MyApp v2.1.0", "cyan", NULL, "bold");
    printSuccess("✅ Configuration loaded");
    printSuccess("✅ Database connected");
    printWarning("⚠️  Running in debug mode");
    
    printf("\n"); // Add spacing
    printStyled("Ready to serve requests!", "green", NULL, "underline");
    return 0;
}
```

### User Authentication System
```c
void authenticateUser(const char* username, const char* password) {
    printStyled("🔐 Authenticating user: %s", "blue", NULL, "italic", username);
    
    if (isValidUser(username, password)) {
        printSuccess("✅ Welcome back, %s!", username);
        printStyled("Last login: %s", "gray", NULL, NULL, getLastLogin(username));
    } else {
        printError("❌ Invalid credentials for user: %s", username);
        printWarning("⚠️  %d failed attempts remaining", getRemainingAttempts(username));
    }
}
```

### File Operations
```c
void processFiles(char** filenames, int count) {
    printStyled("📁 Processing %d files...", "cyan", NULL, "bold", count);
    
    for (int i = 0; i < count; i++) {
        printf("  "); // Indent
        
        if (processFile(filenames[i])) {
            printSuccess("✅ %s", filenames[i]);
        } else {
            printError("❌ Failed: %s", filenames[i]);
        }
    }
    
    printStyled("📊 Completed: %d/%d files", "magenta", NULL, "underline", 
                getSuccessCount(), count);
}
```

### Progress Indicators
```c
void showProgress(int current, int total) {
    float percentage = (float)current / total * 100;
    
    if (percentage < 50) {
        printStyled("Progress: [%d/%d] %.1f%%", "yellow", NULL, "bold", 
                   current, total, percentage);
    } else if (percentage < 90) {
        printStyled("Progress: [%d/%d] %.1f%%", "cyan", NULL, "bold", 
                   current, total, percentage);
    } else {
        printStyled("Progress: [%d/%d] %.1f%%", "green", NULL, "bold", 
                   current, total, percentage);
    }
}
```

---

## 🎨 Creative Combinations

### Rainbow Headers
```c
void printRainbowHeader(const char* title) {
    printStyled("═══════════════════════════════", "magenta", NULL, "bold");
    printStyled("    %s", "cyan", "blue", "bold", title);
    printStyled("═══════════════════════════════", "magenta", NULL, "bold");
}
```

### Status Dashboard
```c
void printSystemStatus() {
    printStyled("📊 SYSTEM STATUS DASHBOARD", "white", "blue", "bold");
    printf("\n");
    
    printStyled("CPU Usage:", "cyan", NULL, "bold");
    printSuccess("  ▓▓▓▓▓░░░░░ 45%%");
    
    printStyled("Memory:", "cyan", NULL, "bold");
    printWarning("  ▓▓▓▓▓▓▓░░░ 78%%");
    
    printStyled("Disk Space:", "cyan", NULL, "bold");
    printSuccess("  ▓▓░░░░░░░░ 23%%");
    
    printStyled("Network:", "cyan", NULL, "bold");
    printError("  ░░░░░░░░░░ OFFLINE");
}
```

---

## 🛠️ Pro Tips

### 1. **Consistent Color Scheme**
Choose a color palette and stick to it:
- **Green**: Success, positive actions
- **Yellow**: Warnings, non-critical issues  
- **Red**: Errors, critical problems
- **Blue**: Information, neutral content
- **Cyan**: Headers, section dividers

### 2. **Use Backgrounds Sparingly**
Backgrounds can be overwhelming. Use them for:
- Critical alerts
- Section headers
- Highlighting important data

### 3. **Combine with Emojis**
Modern terminals support emojis - use them for visual impact:
```c
printSuccess("✅ Task completed!");
printWarning("⚠️  Check your input");
printError("❌ Connection failed");
printStyled("🚀 App launched successfully!", "green", NULL, "bold");
```

### 4. **Format Numbers Nicely**
```c
printStyled("📈 Revenue: $%,.2f (+%.1f%%)", "green", NULL, "bold", 
           revenue, growthPercent);
printStyled("👥 Users online: %,d", "cyan", NULL, NULL, userCount);
```

---

## 🔧 Advanced Usage

### Custom Logging System
```c
typedef enum {
    LOG_DEBUG,
    LOG_INFO, 
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

void logMessage(LogLevel level, const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    
    switch(level) {
        case LOG_DEBUG:
            printStyled("[DEBUG] %s", "gray", NULL, "dim", buffer);
            break;
        case LOG_INFO:
            printStyled("[INFO]  %s", "blue", NULL, NULL, buffer);
            break;
        case LOG_WARNING:
            printWarning("[WARN]  %s", buffer);
            break;
        case LOG_ERROR:
            printError("[ERROR] %s", buffer);
            break;
    }
}
```

### Interactive Menus
```c
void showMenu() {
    printStyled("╔══════════════════════════╗", "cyan", NULL, "bold");
    printStyled("║       MAIN MENU          ║", "cyan", NULL, "bold");
    printStyled("╠══════════════════════════╣", "cyan", NULL, "bold");
    printStyled("║ 1. Start new game        ║", "white", NULL, NULL);
    printStyled("║ 2. Load saved game       ║", "white", NULL, NULL);
    printStyled("║ 3. View high scores      ║", "white", NULL, NULL);
    printStyled("║ 4. Settings              ║", "white", NULL, NULL);
    printStyled("║ 5. Exit                  ║", "red", NULL, NULL);
    printStyled("╚══════════════════════════╝", "cyan", NULL, "bold");
    
    printStyled("Enter your choice (1-5): ", "yellow", NULL, "bold");
}
```

---

## 🐛 Troubleshooting

### Colors Not Showing?
- **Windows**: Use Windows Terminal or enable ANSI support
- **Old terminals**: May not support all features
- **SSH sessions**: Colors should work in most modern SSH clients

### Function Not Found?
- Make sure you included `#include "styledprint.h"`
- Check that `styledprint.h` is in your include path

### Compilation Errors?
- Ensure you're using C99 or later (`-std=c99`)
- Check for typos in color/style names (case-insensitive)

---

## 📚 Complete Reference

### Function Signatures
```c
// Main styling function
void printStyled(const char* text, const char* textColor, 
                const char* bgColor, const char* style, ...);

// Convenience functions  
void printSuccess(const char* text, ...);
void printWarning(const char* text, ...);
void printError(const char* text, ...);
```

### All Available Options
- **Colors**: black, red, green, yellow, blue, magenta, cyan, white, gray
- **Backgrounds**: black, red, green, yellow, blue, magenta, cyan, white
- **Styles**: bold, dim, italic, underline, blink, reverse, hidden, reset

---

## 🌟 Happy Styling!

Now go forth and make your terminal applications beautiful! Remember:
- **Start simple** - use `printSuccess()`, `printWarning()`, `printError()`
- **Be consistent** - establish a color scheme  
- **Don't overdo it** - sometimes less is more
- **Test your output** - make sure it looks good in different terminals

**Questions? Issues? Suggestions?** 
The `styledprint.h` library is designed to be simple and reliable. Experiment, have fun, and create amazing terminal experiences!

---

*Made with ❤️ for developers who care about user experience, even in the terminal.*
