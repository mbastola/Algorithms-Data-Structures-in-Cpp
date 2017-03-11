#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
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
	 if (i==j)
	    matrix[i][j] = 0;
	 else if (i!=j && elements == 0)
	    matrix[i][j] = numeric_limits<double>::infinity();
	 else
	    matrix[i][j] = elements;
      }
   }
   return size;
}

int readExchangeRates(ifstream& fin, double **& matrix, string*& countries,float& cost)
{
   int size=0;
   fin >> size;
   matrix = new double*[size];
   countries = new string[size];
   for (int i=0;i<size;i++)
   {
      matrix[i] = new double[size];
      string str = "";
      fin >> str;
      countries[i] = str;
   }
   double elements;
   for (int i=0;i<size;i++)
   {
      for (int j =0;j<size;j++)
      {
	 fin >> elements;
	 if (i==j)
	    matrix[i][j] = 0;
	 else if (i!=j && elements == 0)
	    matrix[i][j] = numeric_limits<double>::infinity();
	 else
	    matrix[i][j] = -log(elements*(1-cost));
      }
   }
   return size;
}

