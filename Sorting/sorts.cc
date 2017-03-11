#include <iostream> 
#include <cstdlib>
#include <limits>
using namespace std;
 
void insertionSort(int* a, int low, int high) 
{
  int j = low+1;
  while (j < high)
    {
      int key = a[j];
      int i = j-1;
      while (i>low-1 && a[i]>key)
	{
	  a[i+1]=a[i];
	  i--;
	}
      a[i+1]=key;
      j++;
    }
  return;
}

void selectionSort(int* a, int low, int high)
{
   int j = high-1;
   while (j>low-1)
   {
      int maxPos = low;
      int i = low+1;
      while (i<j+1)
      {
	 if (a[i]>a[maxPos])
	    maxPos = i;
	 i++;	 
      }
      int temp = a[maxPos];
      a[maxPos] = a[j];
      a[j] = temp;
      j--;
   }
   return;
}

int partition(int*a, int low, int high)
{
   int right = a[high];
   int i = low -1;      
   int j;
   for (j=low;j<high;j++)
   {
      if (a[j]<=right)
      {
	 i++;
	 int temp = a[i];  //swap
	 a[i]=a[j];
	 a[j]=temp;
      }
   }
   int temp2 = a[i+1]; //swap
   a[i+1]= a[high];
   a[high]= temp2;
   return i+1;       //pivot
}

void quickSortHelper(int* a, int low, int high)
{
   if (low<high)
   {
      int split = partition(a,low,high);  //finds the pivot point
      quickSortHelper(a,low, split-1); //performs quick sort recursively
      quickSortHelper(a,split+1,high);
   }
   return;
}

void quickSort(int* a,int low, int high)
{
   quickSortHelper(a, low, high -1);       //see readme
   return;
}


void merge(int* array,int low,int mid,int high)
{
   int *b = new int [mid-low];       //dynamically create two small arrays
   int *c = new int [high-mid];
   int i;
   int j;
   for (i=low; i<mid;i++)
   {
      b[i-low]=array[i];          //fill them
   }
   for (j=mid;j<high;j++)
   {
      c[j-mid] =array[j];
   }  
   int m = 0;
   int n = 0;
   int k= low;
   while (m < mid-low && n<high-mid)  //merge them 
   {
      if (b[m]<c[n])                        //compare which one is smaller and assign the min to arrays lower index
      {
	  array[k]=b[m];
    	 m++;
       }
       else
       {
	  array[k]=c[n];
    	 n++;
       }
      k++;
   }
   while (m<mid-low)                //if 2nd list is out of index but not the first one
    {
       array[k] = b[m];
       m++;
       k++;
    }
   while (n<high-mid)  // if 1st list is out of index but not the 2nd one
    {
       array[k]=c[n];
       n++;
       k++;
    }
      
   delete [] b; //delete the dynamic arrays to avoid memmory leaks
   delete [] c;
   return;
}

void mergeSort(int* array, int low, int high)
{
   if (high-low>1)               //if one element, no need to sort
   {
      int mid = (high + low)/2; 
      mergeSort(array,low,mid);  //recursive step
      mergeSort(array,mid,high);
      merge(array,low,mid,high);
      
   }
   return;
}

//////////////////////////////////////////////////////////

void insertionSort(int* begin, int* end) 
{
   int* j = begin;       //create new pointer that points to low + 1th index
   j++;
   while (j < end)
   {
      int key = *j;        //a int variable
      int* i = j;
      i--;
      while (i > begin-1 && *i > key)
      {
	 int temp = *i; 
	 i++;
	 *i = temp;//assignment
	 i--;
	 i--;
      }
      i++;
      *i=key;
      j++;
   }
   return;
}

void selectionSort (int* begin, int* end)
{
   int* j = end;
   j--;
   while (j>begin-1)
   {
      int* maxPos = begin;
      int* i = begin;
      i++;
      while (i<j+1)
      {
	 if (*i>*maxPos)
	    maxPos = i;
	 i++;	 
      }
      int temp = *maxPos;
      *maxPos = *j;
      *j = temp;
      j--;
   }
   return;
}

int* partition(int* begin, int* end)
{
   int right = *end;
   int* i = begin;
   i--;
   for (int* j= begin;j<end;j++)
   {
      if (*j<=right)
      {
	 i++;
	 int temp = *i;
	 *i=*j;
	 *j=temp;
      }
   }
   i++;
   int temp2 = *i;
   *i= *(end);
   *(end)= temp2;
   return i;
}	    

void quickSortHelper(int* begin, int* end)
{
   if (begin<end)
   {
      int* split = partition(begin,end);
      split--;
      quickSortHelper(begin, split);
      split++;                //bring it back to its position
      split++;
      quickSortHelper(split,end);
   }
   return;
}

void quickSort(int* begin, int* end)
{
   end--;
   quickSortHelper(begin,end);
   return;
}
