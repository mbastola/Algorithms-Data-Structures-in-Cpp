#ifndef ARRAY_INT_LIST_H
#define ARRAY_INT_LIST_H
#include "IntList.h"

class ArrayIntList: public IntList
{
private:
   int length;
   int capacity;
   int* array;

public:
   ArrayIntList();
   ArrayIntList(int capacity);
   virtual int getCapacity() const;
   virtual ~ArrayIntList();

   virtual void pushBack(int num);
   virtual void popBack();
   virtual void remove(int index);
   virtual void insert(int index, int item); 
   virtual int getBack() const;
   virtual void pushFront(int item);
   virtual void popFront();
   virtual int getFront() const;
   virtual int getItem(int index) const;
   virtual void setItem(int index, int item);
   virtual int getSize() const;
   virtual bool isEmpty() const;
   virtual void print() const;
		       
};
#endif

