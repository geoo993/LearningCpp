/*
 * Mandelbrot.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include <complex>

namespace fractalnamespace {

class Mandelbrot {

public:
	static const int MAX_ITERATIONS = 400;

public:
	Mandelbrot();

	static int getIterations(double x, double y);

	virtual ~Mandelbrot();

};

}

#endif /* MANDELBROT_H_ */
