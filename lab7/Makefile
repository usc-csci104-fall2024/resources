cxx = g++
cxx_flags = -g -Wall -std=c++17
link_gtest = -I /usr/include/gtest/ -lgtest -lgtest_main -pthread

all: tests
	./tests

fermat.o: fermat.cpp fermat.h
	$(cxx) $(cxx_flags) -c $< -o $@

tests: fermat.o tests.cpp
	$(cxx) $(cxx_flags) $^ $(link_gtest) -o $@

clean:
	rm -f *.o tests

.PHONY: all clean
