#include <iostream>
#include <fstream>
#include "numberTheory.h"
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
   long long p = atoll(argv[1]);  //first prime
   long long q = atoll(argv[2]);  //2nd prime
   ofstream publicFile("public.txt");
   ofstream privateFile("private.txt");
   if (not(isPrime(p) && isPrime(q)))
   {
      cout << "Error: The given numbers were not Prime" << endl;
      return 1;
   }
   long long n = p*q;
   long long t = (p-1)*(q-1);
   long long e = 2;
   bool stop = false;
   long long gcd;
   long long x=1;
   long long y=1;
   while (stop == false && e < t)
   {
      gcd = extendedEuclid(e,t, &x, &y);
      if (gcd == 1)
	 stop = true;
      else
	 e++;
   }
   if(x<0)
      x+=t;
   publicFile << e << " " << n << endl;
   privateFile << x << " " << n << endl;  //x == d
}

   
      
      
   



