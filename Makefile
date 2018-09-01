CC = gcc
CFLAGS = -Wall

all: bin build bin/hundred

test: ./bin/test
		./bin/test

bin/hundred: build/check.o build/main.o test
		$(CC) $(CFLAGS) build/check.o build/main.o -o bin/hundred

build/main.o: src/main.c
		$(CC) $(CFLAGS) -c src/main.c -o build/main.o 

build/check.o: src/check.c
		$(CC) $(CFLAGS) -c src/check.c -o build/check.o 

bin/test: ./build/check.o ./build/main_test.o bin
		$(CC) $(CFLAGS) ./build/main_test.o ./build/check.o -o bin/test

./build/main_test.o: ./test/main.c ./thirdparty/ctest.h ./src/check.h
		$(CC) $(CFLAGS) -I thirdparty -I src -c ./test/main.c -o ./build/main_test.o

bin:
		mkdir bin

build:
		mkdir build

.PHONY: clean
clean:
		rm -rf build/*.o
