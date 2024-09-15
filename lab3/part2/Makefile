all: tests

tests: FORCE Schedule_Tests
	# valgrind --leak-check=yes ./Schedule_Tests
	./Schedule_Tests

FORCE: ;

Schedule_Tests: tests.cpp Schedule.o Course.o Assignment.o 
	g++ -Wall -std=c++11 -g tests.cpp Schedule.o Course.o Assignment.o -I /usr/include/gtest/ -l gtest -l gtest_main -pthread -o Schedule_Tests

Schedule.o: Schedule.h Schedule.cpp Course.h Assignment.h
	g++ -Wall -std=c++11 -g -c Schedule.cpp -o Schedule.o

Course.o: Course.h Course.cpp Assignment.h
	g++ -Wall -std=c++11 -g -c Course.cpp -o Course.o

Assignment.o: Assignment.h Assignment.cpp
	g++ -Wall -std=c++11 -g -c Assignment.cpp -o Assignment.o

clean:
	rm *.o Schedule_Tests