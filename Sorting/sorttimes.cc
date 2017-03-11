#include <iostream> 
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <boost/timer.hpp> 
#include "fillArray.h"
#include "sorts.h"
using namespace boost;
using namespace std;

int main(int argc, char* argv[])
{
   timer clock;
   ofstream output(argv[1]);

   char* type = argv[2];
   int i;
   for (i=3;i< argc;i++)
   {
      int size = atoi(argv[i]);
      output << argv[i] <<' ';
      int* array = new int[size];
      if (*type == 's')
      {
	 fillIncreasing(array,size);
	 clock.restart();
	 insertionSort(array,0,size);
	 output << clock.elapsed()<< ' ';

	 clock.restart();
	 selectionSort(array,0,size);
	 output << clock.elapsed()<< ' ';
	 
	 clock.restart();
	 quickSort(array,0,size);
	 output << clock.elapsed()<< ' ';

	 clock.restart();
	 mergeSort(array,0,size);
	 output << clock.elapsed()<< ' ';

      }
      else if (*type == 'r')
      {
	 fillDecreasing(array,size);
	 clock.restart();
	 insertionSort(array,0,size);
	 output << clock.elapsed()<< ' ';

	 fillDecreasing(array,size);
	 clock.restart();
	 selectionSort(array,0,size);
	 output << clock.elapsed()<< ' ';

	 fillDecreasing(array,size);
	 clock.restart();
	 quickSort(array,0,size);
	 output << clock.elapsed()<< ' ';
	
	 fillDecreasing(array,size);
	 clock.restart();
	 mergeSort(array,0,size);
	 output << clock.elapsed()<< ' ';
	
      }

      else if (*type == 'm')
      {
	 fillRandom(array,size);
	 clock.restart();
	 insertionSort(array,0,size);
	 output << clock.elapsed()<< ' ';

	 fillRandom(array,size);
	 clock.restart();
	 selectionSort(array,0,size);
	 output << clock.elapsed()<< ' ';

	 fillRandom(array,size);
	 clock.restart();
	 quickSort(array,0,size);
	 output << clock.elapsed()<< ' ';

	 fillRandom(array,size);
	 clock.restart();
	 mergeSort(array,0,size);
	 output << clock.elapsed()<< ' ';

      }
      output << endl;
      delete [] array;
   }   
   return 0;
}
