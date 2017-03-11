
OPTS = -Wall

sorttimes: sorttimes.cc fillArray.o sorts.o
	g++ ${OPTS} -o sorttimes sorttimes.cc fillArray.o sorts.o

fillArray.o: fillArray.cc fillArray.h
	g++ ${OPTS} -c fillArray.cc

sorts.o: sorts.cc sorts.h
	       g++ ${OPTS} -c sorts.cc

final: cleanemacs clean

cleanemacs:
	 rm *~
clean:
	rm *.o


