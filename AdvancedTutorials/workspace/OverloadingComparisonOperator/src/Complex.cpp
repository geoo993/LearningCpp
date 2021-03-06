/*
 * Complex.cpp
 *
 *  Created on: 30 Oct 2016
 *      Author: GeorgeQuentin
 */

#include "Complex.h"

namespace complexnumbering {

bool comp(const Complex &a, const Complex &b) {
	//return a < b;
	//return a == b;
	//return a != b;
	return (a.real == b.real) && (a.imaginary == b.imaginary);
}

bool Complex::operator==(const Complex &other) const {
	return  (real == other.real) && (imaginary == other.imaginary);

}
bool Complex::operator!=(const Complex &other) const {
	//return  (real != other.real) && (imaginary != other.imaginary);
	return !(*this==other);
}

bool Complex::operator<(const Complex &other) const {

	if (real == other.real) {
		return imaginary < other.imaginary;
	} else {
		return real < other.real;
	}
}

ostream &operator<<(ostream &out, const Complex &c) {
	out << "(" << c.getReal() << "," << c.getImaginary() << ")";
	return out;
}

Complex operator+(const Complex &c1, const Complex &c2) {

	//when we add complex numbers together, you need to add their elements, which in this case is real and imaginary
	return Complex(c1.getReal() + c2.getReal(),
			c1.getImaginary() + c2.getImaginary());
}
Complex operator-(const Complex &c1, const Complex &c2) {
	return Complex(c1.getReal() - c2.getReal(),
			c1.getImaginary() - c2.getImaginary());
}

Complex operator+(const Complex &c1, double d) {
	return Complex(c1.getReal() + d, c1.getImaginary() + d);
}
Complex operator+(double d, const Complex &c1) {
	return Complex(d + c1.getReal(), d + c1.getImaginary());
}

Complex operator-(const Complex &c1, double d) {
	return Complex(c1.getReal() - d, c1.getImaginary() - d);
}
Complex operator-(double d, const Complex &c1) {
	return Complex(d - c1.getReal(), d - c1.getImaginary());
}

Complex::Complex() :
	real(0), imaginary(0) {
	// TODO Auto-generated constructor stub

}
Complex::Complex(double real, double imaginary) :
	real(real), imaginary(imaginary) {
}

//copy constructor
Complex::Complex(const Complex &other) {
	cout << "Copy Constructor Running" << endl;

	//real = other.real;
	//imaginary = other.imaginary;
	*this = other;
}

const Complex &Complex::operator=(const Complex &other) {

	cout << "Assignment Constructor running" << endl;
	real = other.real;
	imaginary = other.imaginary;

	return *this;
}

double Complex::getReal() const {
	return real;
}

double Complex::getImaginary() const {
	return imaginary;
}

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

}
