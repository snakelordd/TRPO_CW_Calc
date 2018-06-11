CC = gcc
CFLAGS = -Wall
#all:
#	$(CC) $(CFLAGS) -o exe calc.c -lm
all: bin build build/src/ build/test/ bin/calc bin/test

bin/calc: build/src/calc.o build/src/main.o  build/src/interface.o build/src/digit.o build/src/check.o  
	$(CC) $(CFLAGS) build/src/calc.o build//src/main.o build/src/interface.o build/src/digit.o build/src/check.o -o bin/calc -lm -lncurses

build/src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/src/main.o 

build/src/calc.o: src/calc.c
	$(CC) $(CFLAGS) -c src/calc.c -o build/src/calc.o 

build/src/interface.o: src/interface.c
	$(CC) $(CFLAGS) -c src/interface.c -o build/src/interface.o

build/src/digit.o: src/digit.c
	$(CC) $(CFLAGS) -c src/digit.c -o build/src/digit.o

build/src/check.o: src/check.c
	$(CC) $(CFLAGS) -c src/check.c -o build/src/check.o

bin/test: build/test/test.o build/src/calc.o build/test/main.o
	$(CC) $(CFLAGS) build/test/test.o build/src/calc.o build/test/main.o -o bin/test -lm -lncurses

build/test/test.o: test/test.c
	$(CC) $(CFLAGS) -c test/test.c -o build//test/test.o -Ithirdparty -Isrc

build/test/main.o: test/main.c
	$(CC) $(CFLAGS) -c test/main.c -o build/test/main.o -Ithirdparty

bin:
	mkdir bin
	
build:
	mkdir build

build/src/:
	mkdir build/src

build/test/:
	mkdir build/test

.PHONY: clean
clean:
	rm -rf build/src/*.o
	rm -rf build/src
	rm -rf build/test/*.o
	rm -rf build/test
