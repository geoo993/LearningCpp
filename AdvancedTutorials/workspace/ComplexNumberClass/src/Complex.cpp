/*
 * Complex.cpp
 *
 *  Created on: 30 Oct 2016
 *      Author: GeorgeQuentin
 */

#include "Complex.h"

namespace complexnumbering {

bool comp(const Complex &a, const Complex &b) {
	return a.getReal() < b.getReal();
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
