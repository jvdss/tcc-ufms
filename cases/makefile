# Compiler and flags
CXX = g++
CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++20 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

# Target executable
TARGET = gen

# Source files
SRC = gen.cpp

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean rule
clean:
	rm -f $(TARGET)
