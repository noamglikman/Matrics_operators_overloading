# Makefile for compiling and testing a C++ program
#noamglikman1@gmail.com
C = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

# Targets
TARGET = main
TEST_TARGET = tests

# Files
OBJS = main.o SquareMat.o 
TEST_OBJS = tests.o SquareMat.o 

# Default rule
all: $(TARGET) $(TEST_TARGET)

# Linking
$(TARGET): $(OBJS)
	$(C) $(CFLAGS) -o $(TARGET) $(OBJS)
$(TEST_TARGET): $(TEST_OBJS)
	$(C) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Compile each .cpp to .o
main.o: main.cpp SquareMat.hpp
	$(C) $(CFLAGS) -c main.cpp
tests.o: tests.cpp SquareMat.hpp
	$(C) $(CFLAGS) -c tests.cpp
SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(C) $(CFLAGS) -c SquareMat.cpp

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)
