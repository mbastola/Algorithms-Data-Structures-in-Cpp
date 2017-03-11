#ifndef LINKED_LIST__H
#define LINKED_LIST__H
#include "List.h"
#include "LinkedListNode.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList:public List<T>
{
  private:
   LinkedListNode<T>* head;
   LinkedListNode<T>* tail;
   int size;
   
  public:
   LinkedList();
   virtual ~LinkedList();

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
LinkedList<T>::LinkedList()
{
   head = tail = 0;
   size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
   LinkedListNode<T>* curNode = head;
   while (curNode!=0)
   {
      LinkedListNode<T>* temp = curNode;
      curNode = curNode->getNext();
      delete temp;
   }
}

template <class T>
void LinkedList<T>:: pushBack(const T& item)
{
   if (size == 0)
   {
      LinkedListNode<T>* newNode = new LinkedListNode<T>(tail,item);
      tail = head = newNode;
   }
   else
   {
      LinkedListNode<T>* newNode = new LinkedListNode<T>(tail->getNext(),item);
      tail->setNext(newNode);
      tail = newNode;
   }
   size++;
}

template <class T>
void LinkedList<T>:: popBack()
{
   LinkedListNode<T>* temp = tail;
   if (size == 1)
   {  
      head = tail = 0;
   }
   else if (size==0)
   {
      cout<<"empty List"<<endl;
      return;
   }
   else
   {
      LinkedListNode<T>* curNode = head;
      for(int i = 1;i<size-1;i++)
      {
	 curNode = curNode->getNext();
      }
      curNode->setNext(tail->getNext());
      tail = curNode;
   }
   delete temp;
   size--;
}

template <class T>
const T& LinkedList<T>::getBack() const
{
   if (size>0)
      return tail->getItem();
}

template <class T>
void LinkedList<T>::pushFront(const T& item)
{
   if (size==0)
      pushBack(item);
   else
   {
      LinkedListNode<T>* newNode = new LinkedListNode<T>(head,item);
      head = newNode;
      size++;
   } 
}

template <class T>
void LinkedList<T>::popFront()
{
   if (size ==1)
      popBack();
   else
   {
      LinkedListNode<T>* temp = head;
      head = head->getNext();
      delete temp;
      size--;
   }
}

template <class T>
const T& LinkedList<T>::getFront() const
{
   return head->getItem();
}

template <class T>
const T& LinkedList<T>::getItem(int index) const
{
   LinkedListNode<T>* curNode= head;
   for(int i = 0;i< index;i++)
   {
      curNode = curNode->getNext();
   }
   return curNode->getItem();
}

template <class T>
void LinkedList<T>::setItem(int index, const T& item)
{
   LinkedListNode<T>* curNode= head;
   for(int i = 0;i< index;i++)
   {
      curNode = curNode->getNext();
   }
   return curNode->setItem(item);
}

template <class T>
void LinkedList<T>::insert(int index, const T& item)
{
   if (index == 0)
      pushFront(item);
   else if (index == size)
      pushBack(item);
   else
   {
      LinkedListNode<T>* curNode= head;
      for(int i = 0;i< index-1;i++)
      {
	 curNode = curNode->getNext();
      }
      LinkedListNode<T>* newNode = new LinkedListNode<T>(curNode->getNext(),item);
      curNode->setNext(newNode);
      size++;
   }
}

template <class T>
void LinkedList<T>:: remove(int index)
{
   if (index == size-1)
      popBack();
   else if (index == 0)
      popFront();
   else if ( index>0 && index<size-1)
   {
      LinkedListNode<T>* curNode= head;
      for(int i = 0;i< index-1;i++)
      {
	 curNode = curNode->getNext();
      }
      LinkedListNode<T>* temp = curNode->getNext();
      curNode->setNext(temp->getNext());
      delete temp;
      size--;
   }
   else
      cout<<"index out of range"<<endl;
}

template <class T>
int LinkedList<T>::getSize() const
{
   return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
   return size==0;
}

template <class T>
void LinkedList<T>::print() const
{
   cout<<"[";
   LinkedListNode<T>* curNode = head;
   for(int i =0;i<size;i++)
   {
      cout<< curNode->getItem()<<",";
      curNode = curNode->getNext();
   }
   cout<<"]"<<endl;
}

#endif
 



