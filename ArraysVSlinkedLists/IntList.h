#ifndef INT_LIST_H
#define INT_LIST_H

class IntList
{
  public:
   virtual ~IntList() { }

   //Adds item to the end of the list
   virtual void pushBack(int item) = 0;
   //Removes, but does not return, the last element of the list
   virtual void popBack() = 0;
   //Returns, but does not remove, the last element of the list
   virtual int getBack() const = 0;
   //Adds item to the front of the list
   virtual void pushFront(int item) = 0;
   //Removes, but does not return, the first element of the list
   virtual void popFront() = 0;
   //Returns, but does not remove, the first element of the list
   virtual int getFront() const = 0;

   //Returns the item at position index
   virtual int getItem(int index) const = 0;
   //Sets the item at position index
   virtual void setItem(int index, int item) = 0;

   //Makes item the element at position index. All elements at position
   //index and beyond move right one position.
   virtual void insert(int index, int item) = 0;
   //Removes the element at position index. All elements beyond
   //position index move left on position.
   virtual void remove(int index) = 0;

   //Returns the number of elements in the list.
   virtual int getSize() const = 0;
   //Returns false if the list contains any elements and true if it
   //contains no elements.
   virtual bool isEmpty() const = 0;
};

#endif
