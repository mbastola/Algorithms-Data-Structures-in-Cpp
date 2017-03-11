#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <class T>
class LinkedListNode
{
  private:
   LinkedListNode<T>* next;
   T item;

  public:
   LinkedListNode();
   LinkedListNode(LinkedListNode<T>* next,T item);

   virtual LinkedListNode<T>* getNext() const;
   virtual const T& getItem() const;
   virtual void setNext(LinkedListNode<T>* next);
   virtual void setItem(const T& item);
};

//_____________________________________________//

template <class T>
LinkedListNode<T>::LinkedListNode()
{
   next =0;
}

template <class T>
LinkedListNode<T>::LinkedListNode(LinkedListNode<T>* next,T item)
{
   this->next=next;
   this->item=item;
}

template <class T>
const T& LinkedListNode<T>::getItem() const
{
   return item;
}

template <class T>
void LinkedListNode<T>::setItem(const T& item)
{
   this->item = item;
}

template <class T>
LinkedListNode<T>* LinkedListNode<T>::getNext() const
{
   return next;
}

template <class T>
void LinkedListNode<T>::setNext(LinkedListNode<T>* next)
{
   this->next = next;
}


#endif
