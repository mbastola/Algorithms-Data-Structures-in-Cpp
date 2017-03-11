#ifndef LIST_H
#define LIST_H

template <class item_t>
class List
{
  public:
   virtual ~List() { }

   virtual void pushBack(const item_t& item) = 0;
   virtual void popBack() = 0;
   virtual const item_t& getBack() const = 0;
   
   virtual void pushFront(const item_t& item) = 0;
   virtual void popFront() = 0;
   virtual const item_t& getFront() const = 0;

   virtual const item_t& getItem(int index) const = 0;
   virtual void setItem(int index, const item_t& item) = 0;

   virtual void insert(int index, const item_t& item) = 0;
   virtual void remove(int index) = 0;

   virtual int getSize() const = 0;
   virtual bool isEmpty() const = 0;
};

#endif
