#ifndef TRANSFORM_H
#define TRANSFORM_H

long long transform(char* codon, int length);
//take as parameters an array of characters and the length of the array and performs bitwise operations and returns long long value.

void untransform(char* codonToFill, int length, long long num); 
//takes an array of characters to fill up, its length, and a long long which encodes the codon. It undos the transformation and fill the array with the resulting characters. 

#endif
