#include <cmath> 
#include <iostream>

using namespace std;

bool isPrime(long long num)
{
  long long myRoot = sqrt(num);
  long long j= 2;
  bool notPrime = true; 
  while (j < myRoot + 1 && notPrime==true)
    {
      if (num%j==0)
	 notPrime = false; //if divisible by number,its not a prime
      j++;
    }
  return notPrime;
}

long long extendedEuclid(long long a, long long b, long long* px, long long* py)
{
   if (b==0)
   {
      *px= 1;            //in base case x=1 and y=0
      *py = 0;
      return a;
   }
   else
   {
      long long d = extendedEuclid(b, a%b , px, py);
      cout<<*px;
      long long temp = *py;
      *py = *px - *py*(a/b);
      *px = temp;
      
      return d;
    }
}

unsigned long long modPower(long long base, unsigned long long exponent, unsigned long long modulus)
{
  if (exponent==0)
    return 1;
  else
    {
       unsigned long long temp = modPower(base,exponent/2,modulus);  //recursive step
       if (exponent%2==0)
	  return (temp*temp)%modulus;
       else
	  return (((temp*temp)%modulus)*base)%modulus;  //mod after each multiplication
    }
}

  

	
       



      
      
  
