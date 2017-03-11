#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "editDistance.h"
using namespace std;

int main(int argc, char* argv[])
{
   ifstream fin(argv[1]);
   string myStr = argv[2];
   int threshold = atoi(argv[3]);
   string input;
   while (!fin.eof( ))
   {
      getline(fin,input);
      if (editDistance(input,myStr,0,0) == threshold)
      {
	 cout << input << endl;
      }
   }
}
