CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -L. -fprofile-arcs -lm
SRC_DIR = src

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

EXECUTABLE = main

.PHONY: all clean 

all: $(EXECUTABLE)

$(EXECUTABLE): main.o libproject.a
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

libproject.a: $(OBJ_FILES)
	ar rcs $@ $^

main.o: main.c 
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(EXECUTABLE) *.o
	rm -rf output_reverse.txt output_uppercase.txt