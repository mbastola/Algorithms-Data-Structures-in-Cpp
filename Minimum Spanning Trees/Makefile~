OPTS = -Wall
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

mst: mst.cc prims.o readGraphs.o BinaryHeap.o
	g++ ${OPTS} ${DEBUG} -o mst mst.cc prims.o readGraphs.o BinaryHeap.o

heaptest: heaptest.cc BinaryHeap.o
	g++ ${OPTS} ${DEBUG} -o heaptest heaptest.cc BinaryHeap.o

BinaryHeap.o: BinaryHeap.cc BinaryHeap.h
	g++ ${OPTS} ${DEBUG} -c BinaryHeap.cc

listtest: listtest.cc readGraphs.o
	g++ ${OPTS} ${DEBUG} -o listtest listtest.cc readGraphs.o

prims.o: prims.cc prims.h
	g++ ${OPTS} ${DEBUG} -c prims.cc

matrixtest: matrixtest.cc readGraphs.o	
	g++ ${OPTS} ${DEBUG} -o matrixtest matrixtest.cc readGraphs.o

readGraphs.o : readGraphs.cc readGraphs.h 
	g++ ${OPTS} ${DEBUG} -c readGraphs.cc

clean:
	rm *.o
	rm *~
