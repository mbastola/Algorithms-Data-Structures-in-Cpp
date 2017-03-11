#ifndef SORTS_H
#define SORTS_H


void insertionSort(int* begin, int* end) ;
//performs Insertion sort using pointers to array indices.

void selectionSort(int* begin, int* end);
//performs Selection sort using pointers to array indices.

void quickSort(int* begin, int* end);
//performs Quick sort using pointers to array indices.

void insertionSort(int* a, int low, int high) ;
//performs Insertion sort using an array, the lower index from which to begin sorting and and upper index before which to stop sorting.

void selectionSort(int* a, int low, int high);
//performs Selection using an array, the lower index from which to begin sorting and and upper index before which to stop sorting.

void quickSort(int* a, int low, int high) ;
//performs Quick sort using an array, the lower index from which to begin sorting and and upper index before which to stop sorting.

void mergeSort(int* a, int low, int high);
//performs Merge sort using an array, the lower index from which to begin sorting and and upper index before which to stop sorting.

#endif
