#include "BinaryHeap.h"
#include <iostream>
using namespace std;

BinaryHeap::BinaryHeap(const double* priorities, int numItems)
{
   this->priorities = new double[numItems];
   items = new int[numItems];
   positions = new int[numItems];
   size = numItems;
   originalSize = numItems;
   for (int i=0;i<numItems;i++)
   {
      items[i]=i;
      positions[i]=i;
      this->priorities[i] = priorities[i];
   }
   for (int i=(size-1)/2;i>-1;i--)
   {
      heapify(i);
   }
}

int BinaryHeap::getMin()const
{
   return items[0];
}

double BinaryHeap::getPriority(int item) const
{
   return priorities[item];
}

int BinaryHeap::getMinChild(int item) const
{
   int leftChild = 2*item+1;
   int rightChild = 2*item+2;
   if (leftChild < size && rightChild < size)
   {
      if (priorities[items[leftChild]]<priorities[items[rightChild]])
	 return leftChild;
      else
	 return rightChild;
   }
   else if (leftChild < size) 
      return leftChild;
   else
      return -1; //if doesnt exist
}

void BinaryHeap::heapify(int item)
{
   int minChild = getMinChild(item);
   bool stop = false;
   while(minChild != -1 && !stop)
   {
      if (priorities[items[item]]>priorities[items[minChild]])
      {
	 int temp = items[item];
	 positions[items[item]] = minChild;
	 positions[items[minChild]] = item;

	 items[item]=items[minChild];
	 items[minChild]=temp;
	 item = minChild;
	 minChild = getMinChild(item);
      }
      else
	 stop = true;
   }
}

void BinaryHeap::percholateUp(int item)
{
   int parent = (item-1)/2;
   bool stop = false;
   while (parent > -1 && !stop)
   {
      if( priorities[items[item]] < priorities[items[parent]])
      {
	 int temp = items[item];
	 positions[items[item]]=parent;
	 positions[items[parent]]= item;

	 items[item] = items[parent];
	 items[parent] = temp;
	 item = parent;
	 parent = (item-1)/2;
      }
      else
	 stop = true;
   }
}

void BinaryHeap::popMin()
{
   if (size>0)
   {
      size--;
      positions[items[size]]= 0; //change positions
      positions[items[0]] = -1;   //doesnt exist
      items[0] = items[size];//make last node root
      items[size] = -1;
      heapify(0);
   }
}

bool BinaryHeap::contains(int item) const
{
   if (item > -1 && item < originalSize && positions[item]!=-1)
      return true;
   return false;
}

void BinaryHeap::decreasePriority(int item,double newPriority)
{
   if (contains(item) && getPriority(item)>newPriority)
   {
      priorities[item] = newPriority;
      percholateUp(positions[item]);
   }
}

BinaryHeap::~BinaryHeap()
{
   delete [] items;
   delete [] positions;
   delete [] priorities;
}

void BinaryHeap::print() const
{
   cout<< "Priorities : [";
   for (int i=0;i<originalSize;i++)
      cout<<priorities[i]<<",";
   cout<<"]"<<endl<<"Items : [";
   for (int i=0;i<originalSize;i++)
      cout<<items[i]<<",";
   cout<<"]"<<endl<<"Positions : [";
   for (int i=0;i<originalSize;i++)
      cout<<positions[i]<<",";
   cout<<"]"<<endl;
}





		      
