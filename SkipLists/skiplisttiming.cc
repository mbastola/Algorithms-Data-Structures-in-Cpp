#include <iostream> 
#include <cstdlib>
#include "SkipList.h"
#include <ctime>
#include <stdio.h>
#include <boost/timer.hpp>
using namespace boost;
using namespace std;

int main(int argc, char* argv[])
{
   timer clock;
   srand(time(0));
   int numBatches = atoi(argv[2]);
   int batchSize = atoi(argv[1]);
   SkipList<long long, int> Array;
   int k= 0;
   for(int i = 0;i<numBatches;i++)
   {
      cout<< Array.getSize();
      clock.restart();
      for (int j = 0; j<batchSize;j++)
      {
	 Array.insert(k,j);
	 k++;
      }
      cout<< ' ' << clock.elapsed()/batchSize<<endl;
   }
}

   
