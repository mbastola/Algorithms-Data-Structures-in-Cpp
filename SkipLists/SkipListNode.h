#ifndef SKIP_LIST_NODE_H
#define SKIP_LIST_NODE_H
#include <vector>
#include <iostream>

using namespace std;

template <class key_t,class val_t>

class SkipListNode
{
  private:
   key_t key;
   val_t value;
   vector<SkipListNode<key_t,val_t>*> next;

  public:
   SkipListNode(const key_t& k, const val_t& v, unsigned height);
   SkipListNode(const key_t& k, unsigned height);
   SkipListNode(unsigned height);

   virtual const key_t& getKey();
   //returns the value of the key member

   virtual void setKey(const key_t& newKey);
   //Sets the key member to the given value

   virtual const val_t& getValue();
   //returns the value of the value member

   virtual void setValue(const val_t& newVal);
   //sets the value member to the given value

   virtual unsigned getHeight();
   //Returns the height of the node (the size of the vector)

   virtual void setHeight(unsigned newHeight);
   //Makes a height and resizes the next vector.

   virtual SkipListNode<key_t, val_t>* getNext(unsigned level);
   // Returns a pointer to the next node at the given level.

   virtual void setNext(unsigned level, SkipListNode<key_t, val_t>* newNext); 
   //takes a level and a SkipListNode* and sets the next pointer at the given level to the given pointer value.

   virtual bool greaterThan(const key_t& someKey) const;
   //checks whether a node has bigger key than some key.

   virtual bool lessThan(const key_t& someKey) const;
   //checks whether a  node has smaller key than a key passed in as parameter.

   virtual bool isTail() const;
   //checks whether the node is tail node.

};


//---------------------------------------------------------------------------

template <class key_t,class val_t>
SkipListNode<key_t,val_t>::SkipListNode(const key_t& k, const val_t& v, unsigned height)
{
   key = k;
   value = v;
   for (unsigned i=0;i<height;i++)
      next.push_back(0);
}

template <class key_t,class val_t>
SkipListNode<key_t,val_t>::SkipListNode(const key_t& k,unsigned height):value()
{
   key = k;
   for (unsigned i=0;i<height;i++)
      next.push_back(0);
}

template <class key_t,class val_t>
SkipListNode<key_t, val_t>::SkipListNode(unsigned height):key(),value()
{
   for (unsigned i=0;i<height;i++)
      next.push_back(0);  
   
}   

template <class key_t,class val_t>
const key_t& SkipListNode< key_t, val_t>::getKey()   
{
   return key;
}


template <class key_t,class val_t>
void SkipListNode<key_t,val_t>::setKey(const key_t& newKey)
{
   key = newKey;
}

template <class key_t,class val_t>
const val_t& SkipListNode< key_t, val_t>::getValue()   
{
   return value;
}


template <class key_t,class val_t>
void SkipListNode<key_t,val_t>::setValue(const val_t& newValue)
{
   value = newValue;
}

template <class key_t,class val_t>
unsigned SkipListNode< key_t, val_t>::getHeight()   
{
   return next.size();
}


template <class key_t,class val_t>
void SkipListNode<key_t,val_t>::setHeight(unsigned newHeight)
{
   next.resize(newHeight);
}

template <class key_t,class val_t>
SkipListNode<key_t, val_t>* SkipListNode<key_t,val_t>::getNext(unsigned level) 
{
   if (level<next.size())
      return next[level];
   else
      return 0;
}

template <class key_t,class val_t>
void SkipListNode<key_t,val_t>::setNext(unsigned level,SkipListNode<key_t, val_t>* newNext)
{
   if (level<next.size())
      next[level] = newNext;
}

template <class key_t,class val_t>
bool SkipListNode<key_t,val_t>::greaterThan(const key_t& someKey) const
{
   return key > someKey;
}

template <class key_t,class val_t>
bool SkipListNode<key_t,val_t>::lessThan(const key_t& someKey) const
{
   return key < someKey;
}

template <class key_t,class val_t>
bool SkipListNode<key_t,val_t>::isTail() const
{
   return false;
}

#endif

