#ifndef READ_GRAPHS_H
#define READ_GRAPHS_H
#include <fstream>
using namespace std;

int readGraph(ifstream& fin, double **& matrix);
//reads in a adjacency matrix from a given file. Takes a file and a double pointer as inputs and creates a nested array out of them. 

int readGraph(ifstream& fin, int**& adj, double**& weights, int*& lengths);
//reads in a adjacency list from a given file. Takes a file and two double pointers and a array of lengths as input.
#endif
