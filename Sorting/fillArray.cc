#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

void fillRandom(int* array, int length)
{
   srand(time(0)); //so that random numbers dont repeat
   for(int i=0;i<length;i++)
   {
      array[i] = rand(); //add random numbers to my array.
   }
   return;
}

void fillIncreasing(int* array, int length)
{
   for(int i=0;i<length;i++)
   {
      array[i] = i ;    // increases the numbers as index increases
   }
   return;
   
}

void fillDecreasing(int* array, int length)
{
   int a = length;
   for(int i=0;i<length;i++)
   {
      array[i] = a ;
      a--;
         // decreases the numbers as index increases
   }
   return;
}

