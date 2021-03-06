/*
 * RGB.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef RGB_H_
#define RGB_H_

namespace bitmaptutorial {

struct RGB {
	double r;
	double g;
	double b;

	RGB(double r, double g, double b);
	//virtual ~RGB();
};

RGB operator-(const RGB &first, const RGB &second);
RGB operator+(const RGB &first, const RGB &second);

}

#endif /* RGB_H_ */
