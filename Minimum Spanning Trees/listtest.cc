#include <fstream>
#include "readGraphs.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   ifstream fin(argv[1]);
   int** adj;
   double** weights;
   int* lengths;
   int size =readGraph(fin,adj,weights,lengths);
   cout<<"Lengths"<<endl;
   for (int i=0;i<size;i++)
   {
      cout<<lengths[i]<<endl;
   }
   cout<<endl;
   cout<<"Adjacent Vertices"<<endl;
    for (int i=0;i<size;i++)
   {
      for (int j=0;j<lengths[i];j++)
      {
	 cout<<adj[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
   cout<<"Weights"<<endl;
   for (int i=0;i<size;i++)
   {
      for (int j=0;j<lengths[i];j++)
      {
	 cout<<weights[i][j]<<" ";
      }
      cout<<endl;
   }
   for (int i=0;i<size;i++)
   {
      delete [] adj[i];
      delete [] weights[i];
   }
   cout<<endl;
   delete [] adj;
   delete [] weights;
   delete [] lengths;
}
