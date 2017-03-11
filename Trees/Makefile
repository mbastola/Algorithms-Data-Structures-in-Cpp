OPTS = -Wall
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

treetime: treetime.cc BinarySearchTree.h RBTree.h RBTreeNode.h AssociativeMap.h
	g++ ${OPTS} ${DEBUG} -o treetime treetime.cc 

binarytreetest: bintest.cc BinarySearchTree.h RBTree.h RBTreeNode.h AssociativeMap.h
	g++ ${OPTS} ${DEBUG} -o binarytreetest bintest.cc 

rbtreetest: test.cc RBTree.h RBTreeNode.h AssociativeMap.h
	g++ ${OPTS} ${DEBUG} -o rbtreetest test.cc 

clean:
	rm *.o

cleantxt:
	rm *.txt
	rm *~
