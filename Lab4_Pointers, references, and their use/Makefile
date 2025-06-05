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
LIBOBJS = obj/Functions.o obj/Point2.o

# Name of the library
LIBRARY = lib/libneljas.a

################################
# Settings for the testing app #
################################

# Compiler flags for the testing app
APP_CXXFLAGS = $(CXXFLAGS) -Iinclude

# Linker flags (order the compiler to link with our library)
LFLAGS += -Llib -lneljas

# The object for the testing app
TESTOBJS = obj/neljastest.o

# The name of the testing app
TESTAPP = bin/neljastest

# This is the first target. It will be built when you run 'make' or 'make build'
build: $(LIBRARY) $(TESTAPP)

# Create the library by using 'ar'
$(LIBRARY) : $(LIBOBJS)
	ar cr $(LIBRARY) $(LIBOBJS)

# Compile each source file of the library
obj/Functions.o: src/Functions.cpp
	$(CXX) $(LIB_CXXFLAGS) -c src/Functions.cpp -o obj/Functions.o

# Compile each source file of the library
obj/Point2.o: src/Point2.cpp
	$(CXX) $(LIB_CXXFLAGS) -c src/Point2.cpp -o obj/Point2.o

# Rule for linking the test app with our library
$(TESTAPP): $(TESTOBJS) $(LIBRARY)
	$(CXX) $(TESTOBJS) -o $(TESTAPP) $(LFLAGS) 

# Compile each source file of the library
obj/neljastest.o: tests/neljastest.cpp
	$(CXX) $(APP_CXXFLAGS) -c tests/neljastest.cpp -o obj/neljastest.o
	
test: $(TESTAPP)
	./$(TESTAPP)

doc:
	doxygen

clean:
	rm -f $(LIBOBJS)
	rm -f $(TESTOBJS)
	rm -f $(LIBRARY)
	rm -f $(TESTAPP)
	rm -rf docs/*
	
all: build doc

