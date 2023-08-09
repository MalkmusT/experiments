CPPFLAGS=-std=c++11 -Wall

INCLUDES=-I ./src

all:
	g++ ${CPPFLAGS} ${INCLUDES} main.cpp -o main

clean:
	rm main
