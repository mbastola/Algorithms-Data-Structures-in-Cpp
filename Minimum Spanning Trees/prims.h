#ifndef PRIMS_H
#define PRIMS_H
#include <utility>
using namespace std;

pair<int, int>* prims(const double* const * adjMatrix, int numVertices);
//It implements Prim's algorithm on graphs represented using an adjacency matrix.

pair<int, int>* listPrims(const int* const* adj, const double* const* weights, const int* lengths, int numVertices);
//Impelemts Prims on adjacency list.

#endif
