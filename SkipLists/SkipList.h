#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include "SkipListNode.h"
#include "SkipListTail.h"
#include "AssociativeMap.h"
#include <cstdlib>
#include <stack>
#include <iostream>
using namespace std;

template <class key_t,class val_t>

class SkipList:public AssociativeMap<key_t,val_t>
{
  private:
   SkipListNode<key_t,val_t>* head;
   SkipListTail<key_t,val_t>* tail;
   int size;

  protected:
   virtual SkipListNode<key_t, val_t>* createNode(const key_t& key,const val_t& value);
   virtual SkipListNode<key_t, val_t>* createNode(const key_t& key);


  public:
   SkipList();
   virtual ~SkipList();
   virtual void insert(const key_t& key, const val_t& value);
   virtual void remove(const key_t& key);
   virtual bool contains(const key_t& key);
   virtual const val_t& find(const key_t& key);
   virtual int getSize();
   virtual bool isEmpty();
   virtual void printList() const;
};
//------------------------------------------------------------------------------

template <class key_t,class val_t>
SkipList<key_t,val_t>::SkipList()
{
   head = new SkipListNode<key_t,val_t>(1);
   tail = new SkipListTail<key_t,val_t>(1);
   size = 0;
   head->setNext(0,tail);
}

template <class key_t,class val_t>
SkipList<key_t,val_t>::~SkipList()
{
   SkipListNode<key_t,val_t>* curNode = head;
   for(int i =0;i<size+2;i++)  //total size = number of keys+head+tail
   {
      SkipListNode<key_t,val_t>* temp = curNode;
      curNode = curNode->getNext(0);
      delete temp;
   }
}

template <class key_t,class val_t>
SkipListNode<key_t, val_t>* SkipList<key_t,val_t>::createNode(const key_t& key,const val_t& value)
{
   SkipListNode<key_t,val_t>* node = new SkipListNode<key_t,val_t>(key,value,1);
   int coin = rand()%2;
   while(coin==0)
   {     
      node->setHeight(node->getHeight()+1);
      coin = rand()%2;
   }
   return node;
}

template <class key_t,class val_t>
SkipListNode<key_t, val_t>* SkipList<key_t,val_t>::createNode(const key_t& key)
{
   SkipListNode<key_t,val_t>* node = new SkipListNode<key_t,val_t>(key,1);
   int coin = rand()%2;
   while(coin==0)
   {     
      node->setHeight(node->getHeight()+1);
      coin = rand()%2;
   }
   return node;
}

template <class key_t,class val_t>
void SkipList<key_t,val_t>::insert(const key_t& key, const val_t& value)
{
   stack<SkipListNode<key_t,val_t>*> myStack;
   SkipListNode<key_t,val_t>* curNode = head;
   int level = head->getHeight()-1;      //used int instead of unsigned because i want level to be less than 0 for while loop to stop
   while(level>=0)
   {
      while (curNode->getNext(level)->lessThan(key))        //if curNode.next = sentinel, it will always return false.
      {
	 curNode = curNode->getNext(level);
      }
      if (curNode->getNext(level)->getKey()==key)         //if key, change value, return.
      {
      curNode->getNext(level)->setValue(value);
      return;
      }
      myStack.push(curNode);
      level--;
   }
   SkipListNode<key_t,val_t>* node = createNode(key,value);
   int nodeSize = node->getHeight();
   if (nodeSize > head->getHeight())
   {
      head->setHeight(nodeSize);
      tail->setHeight(nodeSize);
   }
   int stackSize = myStack.size();
   int* temp = &stackSize;
   if (stackSize>nodeSize)          //which ever is smaller
      *temp = nodeSize;
   for (level = 0;level<*temp;level++)
   {
      node->setNext(level, myStack.top()->getNext(level));
      myStack.top()->setNext(level, node);
      myStack.pop();
   }
   for (level = stackSize;level<nodeSize;level++)
   {
      head->setNext(level,node);
      node->setNext(level,tail);
   }
   size++;
}

template <class key_t,class val_t>
void SkipList<key_t, val_t>:: printList() const
{
   SkipListNode<key_t,val_t>* curNode = head;
   cout<<"(head) ";
   int j=0;
   while (j<size+1)
   {
      for (unsigned i = 0; i<curNode->getHeight();i++)
      {
	 if (curNode->getNext(i)->isTail())  //if tail
	 {
	    cout<<"tail ";
	 }
	 else
	    cout<< curNode->getNext(i)->getKey()<< " ";
      }
      if (curNode->getNext(0)->isTail())
	 {
	    cout<<endl<<"(tail)"<<endl;
	    return;
	 }
      curNode = curNode->getNext(0);
      j++;
      cout<<endl<< "("<< curNode->getKey()<< ","<<curNode->getValue()<<") ";
   }  
}

template <class key_t,class val_t>
void SkipList<key_t, val_t>::remove(const key_t& key)
{
   stack<SkipListNode<key_t,val_t>*> myStack;
   SkipListNode<key_t,val_t>* curNode = head;
   int level = head->getHeight()-1;
   while (level>=0)
   {
      while (curNode->getNext(level)->lessThan(key))
      {
	 curNode = curNode->getNext(level);
      }
      myStack.push(curNode);
      level--;
   }
   curNode = curNode->getNext(0);
   if (curNode->getKey() == key)
   { 
      int stackSize = myStack.size();
      int nodeSize = curNode->getHeight();
      int* temp = &stackSize;
      if (stackSize>nodeSize)
	 *temp = nodeSize;
      for (int i = 0;i<*temp;i++)
      {
	 myStack.top()->setNext(i, curNode->getNext(i));
	 myStack.pop();
      }
      int j= head->getHeight();
      int k = j;
      while (head->getNext(j-1)->isTail())
	 j--;
      if (k!=j)
      {
	 head->setHeight(j);
	 tail->setHeight(j);
      }
      size--;
      delete curNode;
   }
}

template <class key_t,class val_t>
bool SkipList<key_t,val_t>::contains(const key_t& key)
{
   SkipListNode<key_t,val_t>* curNode = head;
   int level = head->getHeight()-1;
   while (level>=0)
   {
      if (curNode->getNext(level)->greaterThan(key))  //if curNode.next = sentinel, it will always return true.
	 level--;
      else if (curNode->getNext(level)->getKey() == key)
	 return true;
      else
	 curNode = curNode->getNext(level);
   }
   return false;
}

template <class key_t,class val_t>
const val_t& SkipList<key_t,val_t>::find(const key_t& key)
{
   stack<SkipListNode<key_t,val_t>*> myStack;
   SkipListNode<key_t,val_t>* curNode = head;
   int level = head->getHeight()-1;
   while(level>=0)
   {
      while (curNode->getNext(level)->lessThan(key))
      {
	 curNode = curNode->getNext(level);
      }
      if (curNode->getNext(level)->getKey()==key)
      {
	 return curNode->getNext(level)->getValue();
      }
      myStack.push(curNode);
      level--;
   }
   SkipListNode<key_t,val_t>* node = createNode(key);
   int nodeSize = node->getHeight();
   if (nodeSize > head->getHeight())
   {
      head->setHeight(nodeSize);
      tail->setHeight(nodeSize);
   }
   int stackSize = myStack.size();
   int* temp = &stackSize;
   if (stackSize>nodeSize)
      *temp = nodeSize;
   for (level = 0;level<*temp;level++)
   {
      node->setNext(level, myStack.top()->getNext(level));
      myStack.top()->setNext(level, node);
      myStack.pop();
   }
   for (level = stackSize;level<nodeSize;level++)
   {
      head->setNext(level,node);
      node->setNext(level,tail);
   }
   size++;
   return node->getValue();
}

template <class key_t,class val_t>
int SkipList<key_t, val_t>::getSize()
{
   return size;
}

template <class key_t,class val_t>
bool SkipList< key_t, val_t>:: isEmpty()
{
   return size == 0;
}

#endif
