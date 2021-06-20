EXECUTABLE  = word_snake


# designate which compiler to use
CXX         = g++

# list of sources used in project
SOURCES     = $(wildcard *.cpp)
# list of objects used in project
OBJECTS     = $(SOURCES:%.cpp=%.o)

#Default Flags (we prefer -std=c++17 but Mac/Xcode/Clang doesn't support)
CXXFLAGS = -std=c++1z

$(EXECUTABLE): $(OBJECTS)




# rule for creating objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

# make clean - remove .o files, executables, tarball
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -Rf *.dSYM



# ADD YOUR OWN DEPENDENCIES HERE
word_snake.o: word_snake.cpp

.PHONY: clean
