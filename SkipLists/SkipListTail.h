#ifndef SKIP_LIST_TAIL_H
#define SKIP_LIST_TAIL_H
#include <vector>
#include "SkipListNode.h"

using namespace std;

template <class key_t,class val_t>

class SkipListTail:public SkipListNode<key_t,val_t>
{
  public:
   SkipListTail(int height);
   virtual bool greaterThan(const key_t& someKey) const;
   virtual bool lessThan(const key_t& someKey) const;
   virtual bool isTail() const;
};

template <class key_t,class val_t>
SkipListTail<key_t,val_t>::SkipListTail(int height):SkipListNode<key_t,val_t>(height)
{
}

template <class key_t,class val_t>
bool SkipListTail<key_t,val_t>::greaterThan(const key_t& someKey) const
{
   return true;
}

template <class key_t,class val_t>
bool SkipListTail<key_t,val_t>::lessThan(const key_t& someKey) const
{
   return false;
}

template <class key_t,class val_t>
bool SkipListTail<key_t,val_t>::isTail() const
{
   return true;
}

#endif

