#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

long long transform(char* codon, int length)
{
   long long addOpp = 0;
   int i=0;
   while (i<length-1)
   {
      addOpp = addOpp|codon[i]; //bitwise or
      addOpp = addOpp<<8;    //bitwise left shift
      i++;
   }
   addOpp = addOpp|codon[i]; //for last bit donot shift just or
   return addOpp;
}

void untransform(char* codonToFill, int length, long long num)
{
   int i=0;
   while(i<length-1)
   {
      char clone = char(num);  //cuts of the higher order bits
      codonToFill[i] = clone;
      num = num>>8;           // right shift
      i++;
   }
   codonToFill[i]=num;
   return;
}

