#include <iostream>
#include <utility>
#include <limits>
#include <fstream>
#include "prims.h"
#include "readGraphs.h"

using namespace std;

int main(int argc, char* argv[])
{
   ifstream fin(argv[1]);
   ofstream fout(argv[2]);
   char* operation;
   if (argc == 4)
      operation = argv[3];
   int size=0;
   pair<int,int>* minEdges;
   int** adj;
   double** weights;
   int* lengths;
   double** matrix;
   if (*operation == 'l')
   {
      size = readGraph(fin,adj,weights,lengths);
      minEdges = listPrims(adj,weights,lengths,size);
   }
   else
   {
      size = readGraph(fin,matrix);
      minEdges = prims(matrix,size);
   }
   double minWeight = 0;
   for (int i=0;i<size-1;i++)
   {
      fout<< minEdges[i].first << ' ' << minEdges[i].second<<endl;
      if (*operation == 'l')
      {
	 int k = 0;
	 for (int j = 0;j<lengths[i];j++) //find the index in adj list.
	 {
	    k = adj[minEdges[i].first][j];
	    if (k == minEdges[i].second)
	    {   
	       minWeight+= weights[minEdges[i].first][j];
	    }
	 }
      }
      else
	 minWeight+= matrix[minEdges[i].first][minEdges[i].second];
   }
   cout<< minWeight <<endl;
   for (int i=0;i<size;i++)
   {
      if (*operation == 'l')
      {
	 delete [] adj[i];
	 delete [] weights[i];
      }
      else
	 delete [] matrix[i];
   }
   delete [] minEdges;
   if (*operation == 'l')
   {
      delete [] adj;
      delete [] weights;
      delete [] lengths;
   }
   else
      delete [] matrix;
}


   
