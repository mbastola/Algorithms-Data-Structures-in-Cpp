OPTS = -Wall
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all: suggestwords shortestpath currencyexchange

suggestwords: suggestwords.cc editDistance.o
	 g++ ${OPTS} ${DEBUG} -o suggestwords suggestwords.cc editDistance.o

editDistance.o: editDistance.cc editDistance.h
	g++ ${OPTS} ${DEBUG} -c editDistance.cc

currencyexchange: currencyexchange.cc readGraphs.o bellmanford.o
	g++ ${OPTS} ${DEBUG} -o currencyexchange currencyexchange.cc readGraphs.o bellmanford.o

shortestpath: shortestpath.cc readGraphs.o bellmanford.o	
	g++ ${OPTS} ${DEBUG} -o shortestpath shortestpath.cc readGraphs.o bellmanford.o


bellmanford.o : bellmanford.cc bellmanford.h 
	g++ ${OPTS} ${DEBUG} -c bellmanford.cc

readGraphs.o : readGraphs.cc readGraphs.h 
	g++ ${OPTS} ${DEBUG} -c readGraphs.cc

clean:
	rm *.o
	rm *~
