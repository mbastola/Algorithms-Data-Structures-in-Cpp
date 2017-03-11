OPTS = -Wall
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all: linkedlisttimes arraylisttimes testArrayList cleantxt

linkedlisttimes: linkedlisttimes.cc listTiming.o LinkedList.h
	 g++ ${OPTS} -o linkedlisttimes linkedlisttimes.cc listTiming.o

arraylisttimes: arraylisttimes.cc listTiming.o ArrayList.h
	 g++ ${OPTS} -o arraylisttimes arraylisttimes.cc listTiming.o

listTiming.o: listTiming.cc listTiming.h
	g++ ${OPTS} $(CFLAGS) listTiming.cc

testArrayList: ArrayList.h test.cc
	g++ ${OPTS} -o testArrayList test.cc 

ArrayIntList.o: ArrayIntList.h ArrayIntList.cc IntList.h
	g++ ${OPTS} $(CFLAGS) ArrayIntList.cc 
	 
clean:
	rm *.o

cleantxt:
	rm *.txt
	rm *~

