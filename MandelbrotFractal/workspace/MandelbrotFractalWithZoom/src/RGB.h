/*
 * RGB.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef RGB_H_
#define RGB_H_


namespace fractalnamespace {

struct RGB {
	double r;
	double g;
	double b;

	RGB(double r, double g, double b);
	void get_rgb_piecewise_linear(int n, int iter_max);
	void get_rgb_smooth(int n, int iter_max);
};

RGB operator-(const RGB &first, const RGB &second);

RGB operator+(const RGB &first, const RGB &second);

}

#endif /* RGB_H_ */
