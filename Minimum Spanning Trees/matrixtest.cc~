#include <fstream>
#include "readGraphs.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
   ifstream fin(argv[1]);
   double** matrix;
   int size =readGraph(fin, matrix);
   for (int i=0;i<size;i++)
   {
      for (int k=0;k<size;k++)
      {
	 cout << matrix[i][k] << ' '; 
      }
      cout<<endl;
   }
   for (int i=0;i<size;i++)
      delete [] matrix[i];
   delete [] matrix;
}
