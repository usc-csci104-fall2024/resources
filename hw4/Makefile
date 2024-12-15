CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

all: floorplan

floorplan: floorplan.cpp avlbst.h bst.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o floorplan