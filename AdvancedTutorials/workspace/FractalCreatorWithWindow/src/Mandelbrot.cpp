/*
 * Mandelbrot.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#include <complex>
#include "Mandelbrot.h"

namespace fractalnamespace {

Mandelbrot::Mandelbrot() {}

int Mandelbrot::getIterations(double x, double y){

	std::complex<double> z = 0;
	std::complex<double> c(x, y);

	unsigned int iterations = 0;

	while(iterations < MAX_ITERATIONS){

		z = z*z + c;

		if(abs(z) > 2)
		{
			break;
		}

		iterations++;
	}

	return iterations;
}

Mandelbrot::~Mandelbrot() {}

}
