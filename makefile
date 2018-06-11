CC = gcc
CFLAGS = -Wall
#all:
#	$(CC) $(CFLAGS) -o exe calc.c -lm
all: bin build bin/calc 

bin/calc: build/calc.o build/main.o  build/nc.o  
	$(CC) $(CFLAGS) build/calc.o build/main.o build/nc.o -o bin/calc -lm -lncurses

build/main.o: src/calc.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o 

build/calc.o: src/calc.c
	$(CC) $(CFLAGS) -c src/calc.c -o build/calc.o 

build/nc.o: src/calc.c
	$(CC) $(CFLAGS) -c src/nc.c -o build/nc.o 
	
bin:
	mkdir bin
build:
	mkdir build

.PHONY: clean
clean:
	rm -rf build/*.o