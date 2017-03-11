#include "SkipList.h"
#include <iostream>

using namespace std;

int main()
{
   SkipList<int,int> Array;
   cout<<"Empty ="<<Array.isEmpty()<<endl;
   Array.insert(14,1);
   Array.insert(15,2);
   Array.insert(17,3);
   Array.insert(14,4);
   Array.insert(12,5);
   cout<<"size"<<Array.getSize();
   cout<<"find 14:"<<Array.find(14)<<endl;
   Array.printList();
   cout<<"find 13:"<<Array.find(13)<<endl;
   Array.printList();
   Array.remove(14);
   Array.printList();
   cout<<Array.contains(14)<<":contains 14"<<endl;
   cout<<Array.contains(21)<<":contains 21"<<endl;
}
 
