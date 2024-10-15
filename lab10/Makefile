CC = g++
CPPFLAGS = -g -Wall -std=c++17
TEST_DIR = tests
BIN_DIR = bin
GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all test tests: $(BIN_DIR) $(BIN_DIR)/QueueTest
	valgrind --leak-check=yes ./$(BIN_DIR)/QueueTest

QueueTest: $(BIN_DIR) $(BIN_DIR)/QueueTest
	valgrind --leak-check=yes  ./$(BIN_DIR)/QueueTest

$(BIN_DIR)/QueueTest: $(TEST_DIR)/QueueTest.cpp $(BIN_DIR)/Queue.o
	$(CC) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

$(BIN_DIR)/Queue.o: Queue.cpp Queue.h
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir $(BIN_DIR)

.phony: clean test

clean:
	rm -rf $(BIN_DIR)
