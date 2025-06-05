#####################################################
# You may need to change the parameters under here. #
#####################################################

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


############################
# Settings for the library #
############################


# Compiler flag -Idir specifies, that there are includes in the 'dir' directory
LIB_CXXFLAGS = $(CXXFLAGS) -Iinclude

# List of objects for the library
LIBOBJS = obj/Stack.o obj/Queue.o obj/Linkedlist.o obj/Node.o obj/datastructuretest.o 

# Name of the library
LIBRARY = lib/libdatastructure.a

################################
# Settings for the testing app #
################################

# Compiler flags for the testing app
APP_CXXFLAGS = $(CXXFLAGS) -Iinclude

# Linker flags (order the compiler to link with our library)
LFLAGS += -Llib -ldatastructure

# The object for the testing app
TESTOBJS = obj/datastructuretest.o

# The name of the testing app
TESTAPP = bin/datastructuretest

# This is the first target. It will be built when you run 'make' or 'make build'
build: $(LIBRARY)

# Create the library by using 'ar'
$(LIBRARY) : $(LIBOBJS)
	ar cr $(LIBRARY) $(LIBOBJS)

# Compile each source file of the librar
obj/Stack.o: src/Stack.cpp
	$(CXX) $(LIB_CXXFLAGS) -c src/Stack.cpp -o obj/Stack.o

obj/Queue.o: src/Queue.cpp
	$(CXX) $(LIB_CXXFLAGS) -c src/Queue.cpp -o obj/Queue.o

obj/Linkedlist.o: src/Linkedlist.cpp 
	$(CXX) $(LIB_CXXFLAGS) -c src/Linkedlist.cpp -o obj/Linkedlist.o

obj/Node.o: src/Node.cpp 
	$(CXX) $(LIB_CXXFLAGS) -c src/Node.cpp -o obj/Node.o

# Rule for linking the test app with our library
$(TESTAPP): $(TESTOBJS) $(LIBRARY)
	$(CXX) $(TESTOBJS) -o $(TESTAPP) $(LFLAGS) 

# Compile each source file of the library
obj/datastructuretest.o: tests/datastructuretest.cpp
	$(CXX) $(APP_CXXFLAGS) -c tests/datastructuretest.cpp -o obj/datastructuretest.o 

test: $(TESTAPP)
	./$(TESTAPP)

doc:
	doxygen

clean:
	rm -f $(LIBOBJS)
	rm -f $(TESTOBJS)
	rm -f $(LIBRARY)
	rm -f $(TESTAPP)
	rm -rf docs/html
	rm -rf docs/latex
