# Run me with 'make'

# Compiler
# CXX = clang++
CXX = g++  # Use this if you're using MinGW or Cygwin

# Compiler flags
CXXFLAGS = -Wall -std=c++23

# List of source files
SRCS = ./games/computer_game_2/Main.cpp ./games/computer_game_2/Game.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Name of the output executable
TARGET = my_program.exe

# Default target: build the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files -> 'make clean'
clean:
	rm -f $(OBJS) $(TARGET)
