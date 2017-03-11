#include <iostream> 
#include <cstdlib>
#include <fstream>
#include "listTiming.h"
#include "ArrayList.h"
using namespace std;

int main(int argc, char* argv[])
{
   char* operation = argv[1];
   int numBatches = atoi(argv[2]);
   int numPerBatch = atoi(argv[3]);
   ofstream fout(argv[4]);
   ArrayList<int> intArray;
   if (*operation == 'a')
   {
      timeAppends(&intArray, numBatches, numPerBatch, fout);
   }
   else if (*operation == 'p')
   {
      timePrepends(&intArray, numBatches, numPerBatch, fout);
   }
   else if (*operation == 'i')
   {
      timeInserts(&intArray, numBatches, numPerBatch, fout);
   }
   else if (*operation == 'x')
   {
      timeAccesses(&intArray, numBatches, numPerBatch, fout);
   }
}

