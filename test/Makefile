CPPFLAGS=-g -std=c++11 -Wall -DNDEBUG

INCLUDES=-I ../src


test_%: test_%.cpp
	g++ ${CPPFLAGS} ${INCLUDES} test_$*.cpp -o test_$*

all: test

test: test_vector test_matrix test_nn test_lexer test_sigmoid
	./test_vector
	./test_matrix
	./test_nn
	./test_lexer

clean:
	rm -f test_vector test_matrix test_nn test_lexer test_sigmoid
