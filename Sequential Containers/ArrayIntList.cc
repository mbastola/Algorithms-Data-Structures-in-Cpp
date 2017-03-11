#include "ArrayIntList.h"
#include <iostream>
using namespace std;

ArrayIntList::ArrayIntList()
{
   length = 0;
   capacity = 10;
   array = new int[10];
}

ArrayIntList::ArrayIntList(int capacity)
{
   length = 0;
   array = new int[capacity];
   this->capacity =capacity;
}

int ArrayIntList::getCapacity() const
{
   return capacity;
}

ArrayIntList::~ArrayIntList()
{
   delete [] array;
}

void ArrayIntList:: pushBack(int item)
{
   if (length < capacity)
   {
      array[length]=item;
      length++;
   }
   else
   {
      capacity*=2;
      int* newArray = new int[capacity];  //if length > capacity make new list
      for (int i = 0; i<length;i++)
      {
	 newArray[i] = array[i];
      }
      int* temp = array;
      array = newArray;
      array[length]= item;
      length++;
      delete [] temp;
   }
}

void ArrayIntList:: popBack()
{   
   if (length!=0)
   {
      length--;
   }
}

int ArrayIntList::getBack() const
{
   return array[length-1];
}

void ArrayIntList::pushFront(int item)
{
   insert(0,item);
}

void ArrayIntList::popFront()
{
   remove(0);
}

int ArrayIntList::getFront() const
{
   return array[0];
}

int ArrayIntList::getItem(int index) const
{
   return array[index];
}

void ArrayIntList::setItem(int index, int item)
{
   array[index]= item;
}

void ArrayIntList::insert(int index, int item)
{
   if (index == length)
      pushBack(item);
   else
   {
      int temp = array[index];
      array[index]=item;
      insert(index+1,temp);
   }
}

void ArrayIntList:: remove(int index)
{
   if (index == length)
      popBack();
   else
   {
      int temp = array[index+1];
      array[index]=temp;
      remove(index+1);
   }
}

int ArrayIntList::getSize() const
{
   return length;
}

bool ArrayIntList::isEmpty() const
{
   return length==0;
}

void ArrayIntList::print() const  //prints my array
{
   cout<<"[";
   for(int i =0;i<length;i++)
      cout<< array[i]<<",";
   cout<<"]"<<endl;
}


	    
      
   
