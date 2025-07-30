# Autoclicker

A lightweight, efficient autoclicker for Windows written in C.

## Features

- **Smart activation**: Only clicks when you hold down the mouse button
- **Configurable**: Enable/disable left and right click independently
- **Randomized timing**: Variable click delays (20-40ms) for natural behavior
- **Hotkey controls**: Easy start/stop and exit controls
- **Command-line options**: Customize behavior via arguments

## Controls

- **F7**: Start/Stop autoclicker
- **Ctrl + End**: Exit program
- **Hold mouse button**: Activate clicking (while autoclicker is running)

## Usage

### Basic Usage
```bash
autoclicker.exe
```
Runs with both left and right click enabled.

### Command Line Options
```bash
autoclicker.exe [left_enable] [right_enable]
```

- `left_enable`: 1 to enable left click, 0 to disable
- `right_enable`: 1 to enable right click, 0 to disable

### Examples
```bash
# Only left click enabled
autoclicker.exe 1 0

# Only right click enabled  
autoclicker.exe 0 1

# Both disabled (manual control only)
autoclicker.exe 0 0
```

## How It Works

1. Press **F7** to start the autoclicker
2. Hold down the mouse button (left or right, depending on settings)
3. The program will automatically click at randomized intervals while the button is held
4. Release the mouse button to stop clicking
5. Press **F7** again to stop the autoclicker
6. Press **Ctrl + End** to exit

## Building

### Requirements
- Windows OS
- C compiler (tested with Clang)
- PowerShell (for intro script)

### Compilation
```bash
clang main.c -o autoclicker.exe -lUser32
```

Or use the provided compile script:
```bash
compile.cmd
```

## Project Structure

```
autoclicker/
├── main.c              # Main program logic
├── headers/
│   └── ENABLES.h       # Structure definitions
├── intro.ps1           # PowerShell intro script
├── compile.cmd         # Build script
└── README.md           # This file
```

## Technical Details

- **Language**: C
- **Platform**: Windows (uses Windows API)
- **Dependencies**: User32.lib
- **Click timing**: 20-40ms randomized intervals
- **Memory management**: Dynamic allocation with proper cleanup

## Key Codes Used

- `0x76`: F7 (start/stop)
- `0x11`: Ctrl key
- `0x23`: End key
- `0x01`: Left mouse button
- `0x02`: Right mouse button

## Safety Features

- Memory allocation error checking
- Proper resource cleanup
- Non-destructive operation (only works when mouse is held)
- Easy exit mechanism

## License

This project is for educational purposes. Use responsibly and in accordance with the terms of service of any software or games you use it with.

## Contributing

Feel free to submit issues and enhancement requests!

---