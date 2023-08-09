CPPFLAGS=-g -std=c++11 -Wall -DNDEBUG

INCLUDES=-I ../src

all: train

train: train.cpp
	g++ ${CPPFLAGS} ${INCLUDES} train.cpp -o train
	
train_data:
	for k in `seq 1 1 1000`; do ( echo $k; echo $k | md5sum | cut -d" " -f1-2 ) | xargs -L 2 ; done > train_data

clean:
	rm train 
	rm train_data
