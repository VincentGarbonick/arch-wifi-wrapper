# Makefile generated by AI (ChatGPT)
# This Makefile was automatically created based on the provided g++ compilation instructions.
# Review and modify as needed to fit your project's requirements.

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Libraries
LIBS = -lfltk

# Source files
SRC = main.cpp \
      ./functionality/scan.cpp \
      ./functionality/run.cpp \
      ./functionality/parse.cpp \
      ./functionality/exit.cpp \
      ./functionality/toggle.cpp \
      ./functionality/draw.cpp \
      ./functionality/connect.cpp \
      ./functionality/label.cpp

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Output binary
TARGET = a.out

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
