/*
 * Complex.h
 *
 *  Created on: 30 Oct 2016
 *      Author: GeorgeQuentin
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace complexnumbering {

class Complex {
private:

	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);

	//copy constructor
	Complex(const Complex &other);

	//assignment operator, this has to be a non static function
	const Complex &operator=(const Complex &other);


	//overloading insertion operator
	double getReal() const;

	double getImaginary() const;

	friend ostream &operator<<(ostream &out, const Complex &test);

	//overloading comparison operator
	friend bool comp(const Complex &a, const Complex &b);
	bool operator<(const Complex &other) const;

	virtual ~Complex();
};


ostream &operator<<(ostream &out, const Complex &c);

//overloading plus operator
//the plus and minus overloaded function is going to return a number from real and imaginary
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator-(const Complex &c1, const Complex &c2);

//overloading plus and minus operator and passing value,
Complex operator+(const Complex &c1, double d);//adding from the right
Complex operator+( double d, const Complex &c1);//adding from the left
Complex operator-(const Complex &c1, double d);//adding from the right
Complex operator-( double d, const Complex &c1);//adding from the left



}

#endif /* COMPLEX_H_ */
