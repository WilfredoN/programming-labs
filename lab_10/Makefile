CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC_DIR = src
INCLUDE_DIR = include
SRC_FILES = main.c $(SRC_DIR)/lib.c
OBJ_FILES = $(SRC_FILES:.c=.o)
EXECUTABLE = main

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)
	rm -rf output.txt