#ifndef LIST_TIMING_H
#define LIST_TIMING_H
#include "List.h"
#include <fstream>
using namespace std;

void timeAppends(List<int>* list, int numBatches, int numPerBatch, ofstream& fout);
//This function takes the given list and append items to the list in batches of size numPerBatch.It does this numBatches times.

void timePrepends(List<int>* list, int numBatches, int numPerBatch, ofstream& fout);
//This function should do the same as timeAppends, except it should insert items at the beginning of the list, using pushFront, rather than at the end.


void timeInserts(List<int>* list, int numBatches, int numPerBatch, ofstream& fout);
//This function should do the same as the previous two, except it should insert items at the middle
//position in the list rather than the beginning or the end.

void timeAccesses(List<int>* list, int numBatches, int numPerBatch, ofstream& fout);
//This function is a little different. For each batch, it should add numPerBatch items to the list. Then it
//should output the list's size (after the insertions) as well as how long it takes to call getItem on
//numPerBatch randomly selected locations in the list.

#endif
