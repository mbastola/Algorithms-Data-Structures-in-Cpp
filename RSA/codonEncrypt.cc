#include <iostream>
#include <fstream>
#include "numberTheory.h"
#include "transform.h"
#include <cstdlib>

using namespace std;



int main(int argc, char** argv)
{
   ifstream toEncrypt(argv[2]);
   ofstream encrypted(argv[3]);
   ifstream publicKey(argv[1]);
   char c;
   unsigned long long e;
   unsigned long long n;
   publicKey >> e;
   publicKey >> n;
   toEncrypt.get(c);
   while (toEncrypt.fail()==false)
   {
      int j=1;
      char myArray[]= {c,' ',' '}; //create array of chars with spaces sothat if we run out of chars,there will be spaces.
      while (j<3)                     //taking out 3 chars at a time
      {
	 toEncrypt.get(c);
	 myArray[j]=c;
	 j++;
      }
      unsigned long long num = transform(myArray,3);  //transform each codon
      encrypted << modPower(num,e,n)<< " ";          //print it to the encrypted file
      toEncrypt.get(c);
   }
   return 0;
}
