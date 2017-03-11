#ifndef READ_GRAPHS_H
#define READ_GRAPHS_H
#include <fstream>
using namespace std;

int readGraph(ifstream& fin, double **& matrix);
//reads in a adjacency matrix from a given file. Takes a file and a double pointer as inputs and creates a nested array out of them. 

int readExchangeRates(ifstream& fin, double **& matrix, string*& countries,float& cost);
//reads in a adjacency matrix of exchange rates from a given file. Takes a file and a double pointer as inputs and creates a nested array out of them. 

#endif
