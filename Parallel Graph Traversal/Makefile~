OPTS = -g -Wall
LIB = -lboost_thread

all: printqueue average dijkstras

printqueue: printqueue.cc
	g++ ${OPTS} -o printqueue printqueue.cc ${LIB}

average: average.cc
	g++ ${OPTS} -o average average.cc ${LIB}

dijkstras: dijkstras.cc
	g++ ${OPTS} -o dijkstras dijkstras.cc ${LIB}

clean:
	rm printqueue
	rm average
	rm dijkstras