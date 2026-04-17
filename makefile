CXX = g++
CXXFLAGS = -Wall -g

# target executable
TARGET = testbst

# build target
$(TARGET): testbst.o intbst.o
	$(CXX) $(CXXFLAGS) testbst.o intbst.o -o $(TARGET)

# compile source files
testbst.o: testbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c testbst.cpp

intbst.o: intbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c intbst.cpp

# clean up
clean:
	rm -f *.o $(TARGET)