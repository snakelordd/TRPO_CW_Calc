CC = gcc
CFLAGS = -Wall
#all:
#	$(CC) $(CFLAGS) -o exe calc.c -lm
all: bin build bin/calc 

bin/calc: build/calc.o build/main.o  build/interface.o build/digit.o build/check.o  
	$(CC) $(CFLAGS) build/calc.o build/main.o build/interface.o build/digit.o build/check.o -o bin/calc -lm -lncurses

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o 

build/calc.o: src/calc.c
	$(CC) $(CFLAGS) -c src/calc.c -o build/calc.o 

build/interface.o: src/interface.c
	$(CC) $(CFLAGS) -c src/interface.c -o build/interface.o

build/digit.o: src/digit.c
	$(CC) $(CFLAGS) -c src/digit.c -o build/digit.o

build/check.o: src/check.c
	$(CC) $(CFLAGS) -c src/check.c -o build/check.o

bin:
	mkdir bin
	
build:
	mkdir build

.PHONY: clean
clean:
	rm -rf build/*.o