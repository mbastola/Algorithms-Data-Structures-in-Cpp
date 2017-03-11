#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
using namespace std;

int readGraph(ifstream& fin, double **& matrix)
{
   int size=0;
   fin >> size;
   matrix = new double*[size];
   for (int i=0;i<size;i++)
   {
      matrix[i] = new double[size];
   }
   double elements;
   for (int i=0;i<size;i++)
   {
      for (int j =0;j<size;j++)
      {
	 fin >> elements;
	 if (elements < 0)
	    matrix[i][j] = numeric_limits<double>::infinity();
	 else
	    matrix[i][j] = elements;
      }
   }
   return size;
}

int readGraph(ifstream& fin, int**& adj, double**& weights, int*& lengths)
{
   int size=0;
   fin >> size;
   adj = new int*[size];
   weights = new double*[size];
   lengths = new int[size];
   double elements;
   int length=0;
   queue<double> weightQueue;
   queue<int> lengthQueue;
   queue<int> adjQueue;
   for (int i=0;i<size;i++)
   {
      length = 0;
      for (int j = 0;j<size;j++)
      {
	 fin >> elements;
	 if (elements>0)
	 {
	    lengthQueue.push(length);
	    adjQueue.push(j);
	    weightQueue.push(elements);
	    length++;
	 }
      }
      adj[i] = new int[length];
      weights[i] = new double[length];
      lengths[i]=length;
      while (!lengthQueue.empty())
      {
	 int k = lengthQueue.front();
	 lengthQueue.pop();
	 adj[i][k]=adjQueue.front();
	 adjQueue.pop();
	 weights[i][k] = weightQueue.front();
	 weightQueue.pop();
      }
   }

   return size;
}
