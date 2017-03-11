#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "List.h"
#include <iostream>
using namespace std;

template <class T>
class ArrayList:public List<T>
{
  private:
   int length;
   int capacity;
   T* array;

  public:
   ArrayList();
   ArrayList(int capacity);
   virtual int getCapacity() const;
   virtual ~ArrayList();

   virtual void pushBack(const T& num);
   virtual void popBack();
   virtual void remove(int index);
   virtual void insert(int index,const T& item); 
   virtual const T& getBack() const;
   virtual void pushFront(const T& item);
   virtual void popFront();
   virtual const T& getFront() const;
   virtual const T& getItem(int index) const;
   virtual void setItem(int index, const T& item);
   virtual int getSize() const;
   virtual bool isEmpty() const;
   virtual void print() const;	       
};


//-----------------------------------------//

template <class T>
ArrayList<T>::ArrayList()
{
   length = 0;
   capacity = 10;
   array = new T[10];
}

template <class T>
ArrayList<T>::ArrayList(int capacity)
{
   length = 0;
   array = new T[capacity];
   this->capacity =capacity;
}

template <class T>
int ArrayList<T>::getCapacity() const
{
   return capacity;
}

template <class T>
ArrayList<T>::~ArrayList()
{
   delete [] array;
}

template <class T>
void ArrayList<T>:: pushBack(const T& item)
{
   if (length < capacity)
   {
      array[length]=item;
      length++;
   }
   else
   {
      capacity*=2;
      T* newArray = new T[capacity];
      for (int i = 0; i<length;i++)
      {
	 newArray[i] = array[i];
      }
      T* temp = array;
      array = newArray;
      array[length]= item;
      length++;
      delete [] temp;
   }
}

template <class T>
void ArrayList<T>:: popBack()
{   
   if (length!=0)
   {
      length--;
   }
}

template <class T>
const T& ArrayList<T>::getBack() const
{
   return array[length-1];
}

template <class T>
void ArrayList<T>::pushFront(const T& item)
{
   insert(0,item);
}

template <class T>
void ArrayList<T>::popFront()
{
   remove(0);
}

template <class T>
const T& ArrayList<T>::getFront() const
{
   return array[0];
}

template <class T>
const T& ArrayList<T>::getItem(int index) const
{
   return array[index];
}

template <class T>
void ArrayList<T>::setItem(int index, const T& item)
{
   array[index]= item;
}

template <class T>
void ArrayList<T>::insert(int index, const T& item)
{
   if (index == length)
      pushBack(item);
   else
   {
      T temp = array[index];
      array[index]=item;
      insert(index+1,temp);
   }
}

template <class T>
void ArrayList<T>:: remove(int index)
{
   if (index == length)
      popBack();
   else
   {
      T temp = array[index+1];
      array[index]=temp;
      remove(index+1);
   }
}

template <class T>
int ArrayList<T>::getSize() const
{
   return length;
}

template <class T>
bool ArrayList<T>::isEmpty() const
{
   return length==0;
}

template <class T>
void ArrayList<T>::print() const
{
   cout<<"[";
   for(int i =0;i<length;i++)
      cout<< array[i]<<",";
   cout<<"]"<<endl;
}

#endif
