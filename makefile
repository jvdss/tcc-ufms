# Compiler and flags
CXX := g++
CXXFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++20 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

# Files
TARGET := main
SRCS := main.cpp graphBuilder.cpp functions.h
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
