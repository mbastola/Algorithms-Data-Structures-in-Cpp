#include <iostream>
#include <fstream>
#include "numberTheory.h"
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
   ifstream toEncrypt(argv[2]);  //Original file
   ofstream encrypted(argv[3]);  //fileDestination
   ifstream publicKey(argv[1]);  // key from keyGen
   char c;
   unsigned long long e; 
   unsigned long long n; 
   publicKey >> e;    //extract the exponent
   publicKey >> n;  //extract the modulus
   toEncrypt.get(c);
   while (toEncrypt.fail()==false)
   {
      unsigned long long num = int(c);
      //cout << num << endl;
      encrypted << modPower(num,e,n)<< " ";
      toEncrypt.get(c);
   }
   return 0;
}
   
   
