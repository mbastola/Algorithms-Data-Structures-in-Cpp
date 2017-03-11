#include "ArrayList.h"
#include <iostream>

using namespace std;

int main()
{
   ArrayList<char> charArray;
   cout<<"Empty ="<<charArray.isEmpty()<<endl;
   cout << "Capacity" << charArray.getCapacity() << endl;
   for (int i=97;i<107;i++)
      charArray.pushBack(char(i));
   cout << "length" << charArray.getSize() << endl;
   charArray.print();
   cout<<"pushBack z"<< endl;
   charArray.pushBack('z');
   cout << "Capacity" << charArray.getCapacity() << endl;
   charArray.print();
   cout<<"popBack"<<endl;
   charArray.popBack(); 
   charArray.print();
   cout << "getBack" << charArray.getBack() << endl;
   charArray.pushFront('k');
   charArray.print();
   cout << "getFront " << charArray.getFront() << endl;
   charArray.popFront();
   cout<<"popFronted"<<endl;
   charArray.print();
   cout << "getItem 5 = " << charArray.getItem(5) << endl;
   charArray.remove(3);
   charArray.print();
   charArray.setItem(3,'k');
   cout << "Get Item= " << charArray.getItem(3) << endl;
   charArray.print();
   for (int i = charArray.getSize();i>0;i--)
   {
      charArray.popBack();
      cout<<charArray.getBack()<<"back"<<endl;
   }
   cout<<"Empty ="<<charArray.isEmpty()<<endl;
   cout<<"Test insert & Remove CharArray:"<<endl;
   for (int i=97;i<110;i++)
   {
      charArray.insert(i-97,char(i));
      cout<<charArray.getBack()<<endl;
   }
   cout << "Capacity" << charArray.getCapacity() << endl;
   charArray.print();
   cout<<"now Remove"<<endl;
   for (int i=13;i>-1;i--)
   {
      cout<<charArray.getBack()<<endl;
      charArray.remove(i);  
   }
   charArray.print();	
}


