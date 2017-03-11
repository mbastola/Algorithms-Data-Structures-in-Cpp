#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H

//Returns true if num is prime (false otherwise)
bool isPrime(long long num);

//Performs the exended Euclid algorithm. Returns the GCD of a and b
//Also sets the variables pointed to by px and py to the integers x
//and y such that ax + by = GCD(a, b)
long long extendedEuclid(long long a, long long b, long long* px, long long* py);
//Efficiently performs the modular exponent operation
//Should work for any base, any exponent >= 0, and any modulus > 0
unsigned long long modPower(long long base, unsigned long long exponent, unsigned long long modulus);


#endif
