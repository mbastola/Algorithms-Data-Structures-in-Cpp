#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int editDistanceMemo(string& s1,string& s2,int i,int j, int** & distMatrix) 
{
   if (distMatrix[i][j]<0)
   {
      if(i == s1.length())
	 distMatrix[i][j] = s2.length()-j;
      else if (j== s2.length())
	 distMatrix[i][j] = s1.length()-i;
      else if (s1[i]==s2[j])
      {
	 
	 distMatrix[i][j]=editDistanceMemo(s1,s2,i+1,j+1,distMatrix);
      }
      else
      {
	 int dist[3] = {editDistanceMemo(s1,s2,i+1,j+1,distMatrix),editDistanceMemo(s1,s2,i,j+1,distMatrix),editDistanceMemo(s1,s2,i+1,j,distMatrix)};
	 distMatrix[i][j]= 1+*min_element(dist,dist+3); 
      }
   }
   return distMatrix[i][j];
}

int editDistance(string& s1,string& s2,int i,int j) 
{
   int** distMatrix = new int*[s1.length()+1];
   for (int k =0;k < s1.length()+1;k++)
   {
      distMatrix[k] = new int[s2.length()+1];
   }
   for (int k = 0;k < s1.length()+1; k++) 
   {
      for (int m = 0; m< s2.length()+1;m++)
      {
	 distMatrix[k][m]=-1;
      }
   }
   int temp = editDistanceMemo(s1,s2,i, j,distMatrix);
   for (int k = 0;k < s1.length()+1;k++)
   {
      delete [] distMatrix[k];
   }
   delete [] distMatrix;
   return temp;
}



