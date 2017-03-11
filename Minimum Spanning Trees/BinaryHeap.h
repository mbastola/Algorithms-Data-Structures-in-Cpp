#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

class BinaryHeap
{
  private:
   double* priorities;
   int* items;
   int* positions;
   int size; //keeps track of list size.
   int originalSize; //keeps track of numItems.
   
  protected:
   virtual void heapify(int pos);
   //percholates down the heap

   virtual int getMinChild(int pos) const;
   //finds the child with minimum priority

   virtual void percholateUp(int pos);
   //percholates up retaining heap properties.

   void print() const;
   //prints the heap.

  public:

   BinaryHeap(const double* priorities, int numItems);
   //This is a constructor take an array of priorities and the number of items in the array. 
   
   virtual ~BinaryHeap();
   // Cleans up any dynamically allocated members of the heap.

   virtual int getMin() const;
   //Returns the item with the minimum priority, but does not alter the heap.

   virtual void popMin();
   //Removes the minimum element from the heap.

   virtual bool contains(int item) const; 
//Returns true if item is in the heap.
   
   virtual double getPriority(int item) const; 
   //Returns the priority of the given item. 

   virtual void decreasePriority(int item, double newPriority);
   //changes the priority of the item and fixes the heap accordingly.

};
#endif
