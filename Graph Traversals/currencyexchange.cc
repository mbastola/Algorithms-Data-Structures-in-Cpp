#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <stack>
#include <cmath>
#include "readGraphs.h"
#include "bellmanford.h"
using namespace std;

int main(int argc,char* argv[])
{
   ifstream fin(argv[1]);
   int src = atoi(argv[2]);
   float cost = atof(argv[3]);
   double** matrix;
   string* countries;
   int numV = readExchangeRates(fin,matrix,countries,cost);
   double* dist;
   int* prev;
   dist = new double[numV];
   prev = new int[numV];
   for (int i=0;i<numV;i++)
   {
      dist[i] = numeric_limits<double>::infinity();
      prev[i] = 0;
   }
   for (int i=0;i<numV;i++)
   {
      for (int j=0;j<numV;j++)
      {
	 cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
   int val = shortestPath(matrix,numV,src,dist,prev);
   if (val == 0)
   {
      for (int i = 0;i<numV;i++)
      {
	 cout<<countries[i]<<":  "<< exp(dist[i]) <<" Path: ";
	 int j=i;
	 stack<string> myStack;
	 while (j!=src)
	 {
	    myStack.push(countries[prev[j]]);
	    j = prev[j];
	 }
	 while(!myStack.empty())
	 {
	    cout<<myStack.top()<< " -> ";
	    myStack.pop();
	 }
	 cout<<countries[i]<<endl;
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
	 cout<<countries[j]<< " -> ";
	 int k = j;
	 if (size==0)
	    break;
	 j = myStack.top();
	 weight+=matrix[k][j];
	 cout<<"W:"<<weight<<endl;
	 myStack.pop();
	 size--;
      }
      weight+=matrix[j][k];
      cout<<"W:"<<weight<<endl;
      cout<<countries[k]<<endl<<"Total Weight: "<<exp(weight)<<endl;	 
   }
   for (int i=0;i<numV;i++)
      delete [] matrix[i];
   delete [] matrix;
   delete [] dist;
   delete [] prev;
   delete [] countries;
}
