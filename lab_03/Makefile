CC = gcc
CFLAGS = -Wall
TARGET = main
REPORT = ./report.md

all: build

build: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

x86: $(TARGET).c
	$(CC) $(CFLAGS) -m32 -o $(TARGET)_x86 $(TARGET).c

x86_64: $(TARGET).c
	$(CC) $(CFLAGS) -m64 -o $(TARGET)_x86_64 $(TARGET).c

asm: $(TARGET).c
	$(CC) $(CFLAGS) -S -masm=intel -o $(TARGET).s $(TARGET).c

clean:
	rm -f $(TARGET) $(TARGET)_x86 $(TARGET)_x86_64 $(TARGET).s

doc: $(REPORT)
	pandoc --pdf-engine=pdfroff --toc-depth=1 $(REPORT) -o report.pdf

debug: build
	gdb ./$(TARGET)