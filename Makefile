CXX := g++
CXXFLAGS := -std=c++20 -fmodules-ts -Wall -Wextra

.PHONY: all clean

all: dice

gcm.cache/iostream.stamp: Makefile
	$(CXX) $(CXXFLAGS) -x c++-system-header iostream
	touch gcm.cache/iostream.stamp

dice: main.cpp gcm.cache/iostream.stamp Makefile
	$(CXX) $(CXXFLAGS) main.cpp -o dice

clean:
	rm -rf gcm.cache
	rm -f dice