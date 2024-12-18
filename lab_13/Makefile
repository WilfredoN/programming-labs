CC = gcc
CFLAGS = -Wall -g -Iinclude

SRC_DIR = src
INCLUDE_DIR = include

SRC_FILES = main.c $(SRC_DIR)/lib.c
OBJ_FILES = $(SRC_FILES:.c=.o)

IO_SRC_FILES = main_io.c $(SRC_DIR)/lib_io.c
IO_OBJ_FILES = $(IO_SRC_FILES:.c=.o)

LIB_OBJ = $(SRC_DIR)/lib.o

EXECUTABLE = main
IO_EXECUTABLE = main_io

.PHONY: all clean

all: $(EXECUTABLE) $(IO_EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(IO_EXECUTABLE): $(IO_OBJ_FILES) $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(IO_OBJ_FILES) $(EXECUTABLE) $(IO_EXECUTABLE)