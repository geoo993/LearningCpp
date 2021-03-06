/*
 * Mandelbrot.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#include <complex>
#include "Mandelbrot.h"

namespace bitmaptutorial {

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

int Mandelbrot::getIterations(double x, double y){

	std::complex<double> z = 0;
	std::complex<double> c(x, y);

	unsigned int iterations = 0;

	while(iterations < MAX_ITERATIONS){

		z = z*z + c; // z*z is squaring the number

		if(abs(z) > 2)//abs gets the magnitude of a complex number
		{
			break;
		}

		iterations++;
		//++iterations;
	}

	return iterations;
}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}

}
