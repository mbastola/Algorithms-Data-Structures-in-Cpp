OPTS = -Wall
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)


skiplisttiming: skiplisttiming.cc SkipList.h SkipListNode.h SkipListTail.h AssociativeMap.h
	 g++ ${OPTS} -o skiplisttiming skiplisttiming.cc

skiptest: test.cc SkipList.h SkipListNode.h SkipListTail.h AssociativeMap.h
	g++ ${OPTS} ${DEBUG} -o skiptest test.cc 

clean:
	rm *~
