#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H
#include <string>
using namespace std;

int editDistanceMemo(string& s1,string& s2,int i,int j, int** & distMatrix); 
//helper function.

int editDistance(string& s1,string& s2,int i,int j);
//gives the edit distance between two strings. 

#endif
