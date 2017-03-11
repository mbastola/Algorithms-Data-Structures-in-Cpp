#include <iostream>
#include <fstream>
#include "numberTheory.h"
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
   ifstream toDecrypt(argv[2]); //Original file
   ofstream decrypted(argv[3]); //fileDestination
   ifstream privateKey(argv[1]); //private key from keyGen
   unsigned long long d;
   unsigned long long n;
   privateKey >> d;  
   privateKey >> n;
   long long num;
   toDecrypt >> num;
   while(!toDecrypt.eof())
   {
      unsigned long long val = modPower(num,d,n);
      //cout << val << endl;
      decrypted << char(val);
      toDecrypt >> num;
   }
   return 0;
}

