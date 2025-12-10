# Basic Calculator

A simple yet powerful calculator application with both command-line and GUI interfaces, built with C and GTK3.

## 🚀 Features

- **Basic Operations**: Addition (+), Subtraction (-), Multiplication (*), Division (/)
- **Power Operation**: Calculate exponents (^)
- **User-friendly GUI**: Built with GTK3 for an intuitive interface
- **Error Handling**: Validates inputs and prevents division by zero
- **Cross-platform**: Works on Windows, Linux, and macOS

## 🛠️ Prerequisites

- GCC (GNU Compiler Collection)
- GTK3 development libraries
- pkg-config
- make (optional, for using Makefile)

## 📦 Installation

### Windows
1. Install MSYS2 from [msys2.org](https://www.msys2.org/)
2. Open MSYS2 MinGW 64-bit terminal
3. Install dependencies:
   ```bash
   pacman -S mingw-w64-x86_64-gtk3 mingw-w64-x86_64-gcc mingw-w64-x86_64-pkg-config make
   ```

### Linux (Debian/Ubuntu)
```bash
sudo apt-get update
sudo apt-get install build-essential libgtk-3-dev pkg-config
```

### macOS (using Homebrew)
```bash
brew install gcc pkg-config gtk+3
```

## 🏗️ Building the Project

### Using Makefile (Recommended)
```bash
make          # Build the project
make run      # Build and run the application
make clean    # Clean build files
```

### Manual Build
```bash
# For GUI version
gcc Basic_Calc_gui.c -o Basic_Calc_gui `pkg-config --cflags --libs gtk+-3.0`

# For CLI version
gcc Basic_Calc.c -o Basic_Calc
```

### Windows (using build.bat)
Double-click `build.bat` or run it from Command Prompt.

## 🚀 Usage

### GUI Version
```bash
./Basic_Calc_gui
```
1. Enter the first number
2. Select an operator from the dropdown
3. Enter the second number
4. Click "Calculate" to see the result
5. Use "Clear" to reset the inputs

### Command-Line Version
```bash
./Basic_Calc
```
Follow the on-screen prompts to perform calculations.

## 📁 Project Structure

- `Basic_Calc.c` - Command-line calculator implementation
- `Basic_Calc_gui.c` - GTK3-based GUI calculator
- `Makefile` - Build automation
- `build.bat` - Windows build script
- `README.md` - This documentation file

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- [GTK+ Project](https://www.gtk.org/)
- [GCC Compiler](https://gcc.gnu.org/)
- [MSYS2](https://www.msys2.org/) for Windows support
