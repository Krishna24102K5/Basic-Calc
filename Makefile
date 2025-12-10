# Compiler and flags
CC = gcc
CFLAGS = -Wall `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
TARGET = Basic_Calc_gui
SRC = Basic_Calc_gui.c

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Clean build files
clean:
	rm -f $(TARGET).exe

# Run the program
run: $(TARGET)
	./$(TARGET).exe

# Help message
help:
	@echo "Available targets:"
	@echo "  make       - Build the program"
	@echo "  make clean - Remove built files"
	@echo "  make run   - Build and run the program"
	@echo "  make help  - Show this help message"

.PHONY: all clean run help
