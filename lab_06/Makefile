CC = gcc
CFLAGS = -Wall -Iinclude -IUnity/include -fprofile-arcs -ftest-coverage
LDFLAGS = -L. -fprofile-arcs -ftest-coverage
SRC_DIR = src
TEST_DIR = test
UNITY_SRC = Unity/src/unity.c
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
EXECUTABLE = main
TEST_EXECUTABLE = run_tests

.PHONY: all clean test

all: $(EXECUTABLE)

$(EXECUTABLE): main.o libproject.a
	$(CC) $(CFLAGS) -o $@ $^

libproject.a: $(OBJ_FILES)
	ar rcs $@ $^

main.o: main.c 
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES) libproject.a
	$(CC) $(CFLAGS) -o $@ $(UNITY_SRC) $^

clean:
	rm -rf $(OBJ_FILES) $(EXECUTABLE) $(TEST_EXECUTABLE) *.o libproject.a *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report