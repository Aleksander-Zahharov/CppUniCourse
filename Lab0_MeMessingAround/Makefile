# Step 1: Choose a compiler. By default, use clang++

# If you use clang++, make sure the following line does not start with a comment (#)
#CXX=clang++
# If you use g++, uncomment the following line
CXX=g++

# Set default compiler parameters
# -Wall 	shows all warnings when compiling, always use this!
# -std=c++11 	enables the C++11 standard mode
CXXFLAGS = -Wall -std=c++11

# Step 2: If you use clang++ under Mac OS X, remove these comments
#CXXFLAGS += -stdlib=libc++
#LFLAGS += -stdlib=libc++

# Step 3: Run 'make' in the same directory as this file

# Declare the name of our program (in Windows, the compiler adds .exe)
PROGRAM = HelloWorld0

# The name of the testing app
TEST = testprogram	#??? Это нужно для чего-то? У меня вроде нет тут файла с таким названием

# ! The needed object files (we make these from the source code)
OBJ = HelloWorld0.o
TESTOBJ = test.o functions.o

# !!! This is the FIRST target
# It will be built when you run 'make' or 'make build'
build: $(PROGRAM)	#1 Компилиреут  HelloWorld0.cpp и создает файл HelloWorld0.exe

# Rule for linking IMPORTANT!!!! The space in front of $(CXX) is a TABULATOR!!!!!!
$(PROGRAM): $(OBJ)
	$(CXX) $(OBJ) $(LFLAGS) -o $(PROGRAM)

$(TEST): $(TESTOBJ)
	$(CXX) $(TESTOBJ) $(LFLAGS) -o $(TEST)

# Rules for compiling
# Если мы не используем список SRC с .cpp файлами и OBJ=$(SRC:.cpp=.o),
# то нам нужно прописывать каждый файл отдельно, как на след строках
# И тогда можно просто добавлять еще один .о файл в список OBJ
# Если мы используем список SRC и OBJ=$(SRC:.cpp=.o), то следующие строки не нужны
HelloWorld0.o: HelloWorld0.cpp
	$(CXX) -c HelloWorld0.cpp -o HelloWorld0.o $(CXXFLAGS)

#2 Компилирует(#1 build) и запускает программу HelloWorld0.exe
run: build
	./$(PROGRAM)	

# Generate documentation using Doxygen
doc:
	@if [ ! -d "docs" ]; then mkdir docs; fi
	doxygen Doxyfile

# Clean up object files, executables, and documentation
# Или можно rm -f *.o *.exe - альтернатива для удаления ВСЕХ файлов с расширением .o и .exe в текущей директории
# Возможно строчку rm -rf docs лучше удалить, если я не хочу чтобы doxygen документация удалялась\\\*
clean:
	rm -f *.o $(PROGRAM) $(TEST) PointersTests0.exe 
	rm -rf docs

# Build the program and generate documentation
all: build doc