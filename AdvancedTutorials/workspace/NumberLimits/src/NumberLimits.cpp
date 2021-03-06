//============================================================================
// Name        : NumberLimits.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

int main() {

   char c;
   bool b;
   short int s;
   int i;
   long int l;
   int *ip;
   int &ir = i;
   float f;
   double d;
   long double ld;
   char carray[10];

   cout << "sizeof(char) = " << sizeof(char) << "\tsizeof c = " << (sizeof c) << endl;
   cout << "sizeof(bool) = " << sizeof(bool) << "\tsizeof b = " << (sizeof b) << endl;
   cout << "sizeof(short int) = " << sizeof(short int) << "\tsizeof s = " << (sizeof s) << endl;
   cout << "sizeof(int) = " << sizeof(int) << "   \tsizeof i = " << (sizeof i) << endl;
   cout << "sizeof(long int) = " << sizeof(long int) << "\tsizeof l = " << (sizeof l) << endl;
   cout << "sizeof(int *) = " << sizeof(int *) << "\tsizeof ip = " << (sizeof ip) << endl;
   cout << "sizeof(int &) = " << sizeof(int &) << "\tsizeof ir = " << (sizeof ir) << endl;
   cout << "sizeof(float) = " << sizeof(float) << "\tsizeof f = " << (sizeof f) << endl;
   cout << "sizeof(double) = " << sizeof(double) << "\tsizeof d = " << (sizeof d) << endl;
   cout << "sizeof(long double) = " << sizeof(long double) << "\tsizeof ld = " << (sizeof ld) << endl;
   cout << "sizeof(char[10]) = " << sizeof(char[10]) << "\tsizeof carray = " << (sizeof carray) << endl;

   cout << "Smallest and largest short ints are "
		<< numeric_limits<short int>::min() << " and "
		<< numeric_limits<short int>::max() << endl;
   cout << "Smallest and largest ints are "
		<< numeric_limits<int>::min() << " and "
		<< numeric_limits<int>::max() << endl;
   cout << "Smallest and largest long ints are "
		<< numeric_limits<long int>::min() << " and "
		<< numeric_limits<long int>::max() << endl;
   cout << "Smallest and largest floats are "
		<< numeric_limits<float>::min() << " and "
		<< numeric_limits<float>::max() << endl;
   cout << "Smallest and largest doubles are "
		<< numeric_limits<double>::min() << " and "
		<< numeric_limits<double>::max() << endl;
   cout << "Smallest and largest long doubles are "
		<< numeric_limits<long double>::min() << " and "
		<< numeric_limits<long double>::max() << endl;

   cout << "Infinity: " << std::numeric_limits<long double>::infinity() << endl;

   	   long double max = std::numeric_limits<long double>::max();
   	   long double inf = std::numeric_limits<long double>::infinity();

   	   if(inf > max)
   	   std::cout << inf << " is greater than " << max << '\n';


	return 0;
}
