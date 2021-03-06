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



}

#endif /* COMPLEX_H_ */
