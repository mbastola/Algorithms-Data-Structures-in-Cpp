#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "AssociativeMap.h"
#include "RBTree.h"
#include "RBTreeNode.h"

template <class key_t, class val_t>
class BinarySearchTree : public RBTree<key_t, val_t>
{
  protected:
   virtual void insertFixup(RBTreeNode<key_t, val_t>* insertedNode);
   virtual void deleteFixup(RBTreeNode<key_t, val_t>* replacementNode);

  public:
   BinarySearchTree();
};

template <class key_t,class val_t>
BinarySearchTree<key_t,val_t>::BinarySearchTree():RBTree<key_t,val_t>()
{
}

template <class key_t, class val_t>
void BinarySearchTree<key_t, val_t>::insertFixup(RBTreeNode<key_t, val_t>* insertedNode)
{
}

template <class key_t, class val_t>
void BinarySearchTree<key_t, val_t>::deleteFixup(RBTreeNode<key_t, val_t>* replacementNode)
{
}

#endif
