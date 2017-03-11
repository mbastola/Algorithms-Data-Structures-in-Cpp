#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <stack>
#include "readGraphs.h"
#include "bellmanford.h"
using namespace std;

int main(int argc,char* argv[])
{
   ifstream fin(argv[1]);
   int src = atoi(argv[2]);
   double** matrix;
   int numV = readGraph(fin,matrix);
   double* dist;
   int* prev;
   dist = new double[numV];
   prev = new int[numV];
   for (int i=0;i<numV;i++)
   {
      dist[i] = numeric_limits<double>::infinity();
      prev[i] = -1;  //Nil vertex is -1 and not 0 as 0 could be one of the vertex.
   }
   int val = shortestPath(matrix,numV,src,dist,prev);
   if (val==0)
   {
      for (int i = 0;i<numV;i++)
      {
	 cout<<i<<":  "<< dist[i] <<" Path: ";
	 int j=i;
	 stack<int> myStack;
	 while (j!=src)
	 {
	    myStack.push(prev[j]);
	    j = prev[j];
	 }
	 while(!myStack.empty())
	 {
	    cout<<myStack.top()<< " -> ";
	    myStack.pop();
	 }
	 cout<<i<< endl;
      }
   }
   
   else
   {
      cout<<"Negative Cycle Detected!"<<endl;
      vector<bool> path(numV,false);
      int weight = 0;
      stack<int> myStack;
      int j = val-1;
      cout<<"Cycle: ";                        
      while (!path[j])
      {
	 myStack.push(prev[j]);
	 path[j] = true;
	 j = prev[j];
      }
      j = myStack.top();
      myStack.pop();
      int size  = myStack.size();
      int k = j;     //keeps track of next element of prev[j]
      while (path[j])
      {	 
	 path[j]= false;
	 cout<<j<< " -> ";
	 int k = j;
	 if (size==0)
	    break;
	 j = myStack.top();
	 weight+=matrix[k][j];
	 myStack.pop();
	 size--;
      }
      weight+=matrix[j][k];
      cout<<k<<endl<<"Total Weight: "<<weight<<endl;	 
   }
   for (int i=0;i<numV;i++)
      delete [] matrix[i];
   delete [] matrix;
   delete [] dist;
   delete [] prev;
}
