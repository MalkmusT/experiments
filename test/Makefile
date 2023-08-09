CPPFLAGS=-g -std=c++11 -Wall -DNDEBUG

INCLUDES=-I ../src


main: main.cpp
	g++ ${CPPFLAGS} ${INCLUDES} main.cpp -o main


all: main

test: main
	./main


clean:
	rm main
