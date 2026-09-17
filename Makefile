CXX := g++
CXXFLAGS := -std=c++20 -fmodules-ts -Wall -Wextra

.PHONY: all clean

all: dice

gcm.cache/iostream.stamp: Makefile
	$(CXX) $(CXXFLAGS) -x c++-system-header iostream
	touch gcm.cache/iostream.stamp

gcm.cache/fstream.stamp: Makefile
	$(CXX) $(CXXFLAGS) -x c++-system-header fstream
	touch gcm.cache/fstream.stamp

experiment.o: experiment.cpp gcm.cache/iostream.stamp Makefile
	$(CXX) $(CXXFLAGS) -c experiment.cpp -o experiment.o

experiment-impl.o: experiment-impl.cpp experiment.o Makefile
	$(CXX) $(CXXFLAGS) -c experiment-impl.cpp -o experiment-impl.o

main.o: main.cpp experiment.o gcm.cache/iostream.stamp gcm.cache/fstream.stamp Makefile
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

dice: main.o experiment.o experiment-impl.o
	$(CXX) main.o experiment.o experiment-impl.o -o dice

clean:
	rm -rf gcm.cache
	rm -f dice main.o experiment-impl.o experiment.o 
