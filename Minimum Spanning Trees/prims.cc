#include <iostream>
#include <utility>
#include <limits>
#include "BinaryHeap.h"
using namespace std;

pair<int,int>* prims(const double* const * adjMatrix, int numVertices)
{
   double* dist = new double[numVertices];
   pair<int,int>* prev = new pair<int,int>[numVertices-1];  
   for (int i=0;i<numVertices;i++)
   {
      dist[i] = numeric_limits<double>::infinity();
   }
   dist[0] = 0;
   int n = 0;
   for (int i = 1;i<numVertices;i++)
   {
      for (int j = 0;j<numVertices; j++)
      {
	 if (j!=n && adjMatrix[j][n] < dist[j])
	 {
	    dist[j] = adjMatrix[j][n];
	    prev[j-1] = pair<int,int>(n,j);
	 }
      }
      double min = numeric_limits<double>::infinity();
      for (int k = 0;k<numVertices; k++)
      {
	 if (0 < dist[k] &&  dist[k] < min)
	 {
	    n = k;
	    min = dist[k];
	 }
      }
      dist[n] = 0;
   }
   delete [] dist;
   return prev;
}
   
pair<int, int>* listPrims(const int* const* adj, const double* const* weights, const int* lengths, int numVertices)
{
   double* dist = new double[numVertices];
   pair<int,int>* prev = new pair<int,int>[numVertices-1]; 
   for (int i=0;i<numVertices;i++)
   {
      dist[i] = numeric_limits<double>::infinity();
   }
   BinaryHeap myHeap = BinaryHeap(dist,numVertices);
   myHeap.decreasePriority(0,0);
   int n = myHeap.getMin();
   myHeap.popMin();
   for (int i=1;i<numVertices;i++)
   {
      for (int j=0;j<lengths[n];j++)
      {
	 int k = adj[n][j];
	 if (myHeap.contains(adj[n][j]) && weights[n][j]<myHeap.getPriority(k))
	 {
	    myHeap.decreasePriority(k,weights[n][j]);
	    prev[k-1] = pair<int,int>(n,k);
	 }
      }
      n = myHeap.getMin();
      myHeap.popMin();
   }
   delete [] dist;
   return prev;
}


	    
