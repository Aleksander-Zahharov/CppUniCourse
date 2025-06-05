# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17

# Target executable
TARGET = program

# Source files
SRCS = allTasks.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Add a run target to build and execute the program
run: $(TARGET)
	make $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)