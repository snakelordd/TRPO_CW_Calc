CC = gcc
CFLAGS = -Wall
#all:
#	$(CC) $(CFLAGS) -o exe calc.c -lm
all: bin build bin/calc 

bin/calc: build/calc.o build/main.o   
	$(CC) $(CFLAGS) build/calc.o build/main.o -o bin/calc -lm

build/main.o: src/calc.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o 

build/calc.o: src/calc.c
	$(CC) $(CFLAGS) -c src/calc.c -o build/calc.o 

build/move.o: src/move.c
	$(CC) $(CFLAGS) -c src/move.c -o build/move.o 
	
bin:
	mkdir bin
build:
	mkdir build

.PHONY: clean
clean:
	rm -rf build/*.o