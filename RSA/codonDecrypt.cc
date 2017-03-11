#include <iostream>
#include <fstream>
#include "numberTheory.h"
#include "transform.h"
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
   ifstream toDecrypt(argv[2]);
   ofstream decrypted(argv[3]);
   ifstream privateKey(argv[1]);
   unsigned long long d;
   unsigned long long n;
   privateKey >> d;
   privateKey >> n;
   long long num;
   toDecrypt >> num;
   while(!toDecrypt.eof())
   {
      char myArray[] = {' ',' ',' '};  //create array of chars that are spaces
      long long val = modPower(num,d,n);
      untransform(myArray,3,val); //untransform
      int j = 2;
      while(j>=0)      //print the array out to decrypted file.
      {
	 decrypted << myArray[j];
	 j--;
      }
      toDecrypt >> num;
   }
   return 0;
}
