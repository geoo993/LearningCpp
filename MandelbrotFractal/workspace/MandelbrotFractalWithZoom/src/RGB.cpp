/*
 * RGB.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#include "RGB.h"

namespace fractalnamespace {

RGB::RGB(double r, double g, double b): r(r), g(g), b(b) {}

RGB operator-(const RGB &first, const RGB &second){
	return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
}

RGB operator+(const RGB &first, const RGB &second){
	return RGB(first.r + second.r, first.g + second.g, first.b + second.b);
}

void RGB::get_rgb_piecewise_linear(int n, int iter_max) {
	int N = 256; // colors per element
	int N3 = N * N * N;
	// map n on the 0..1 interval (real numbers)
	double t = (double)n/(double)iter_max;
	// expand n on the 0 .. 256^3 interval (integers)
	n = (int)(t * (double) N3);

	int b = n/(N * N);
	int nn = n - b * N * N;
	int r = nn/N;
	int g = nn - r * N;


	this ->r = r;
	this ->g = g;
	this ->b = b;

}

void RGB::get_rgb_smooth(int n, int iter_max) {
	// map n on the 0..1 interval
	double t = (double)n/(double)iter_max;

	// Use smooth polynomials for r, g, b
	int r = (int)(9*(1-t)*t*t*t*255);
	int g = (int)(15*(1-t)*(1-t)*t*t*255);
	int b =  (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);

	this ->r = r;
	this ->g = g;
	this ->b = b;
}



}
