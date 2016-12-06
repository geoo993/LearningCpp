/*
 * FractalGenerator.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef FRACTALGENERATOR_H_
#define FRACTALGENERATOR_H_

#include <cstdint>
#include <assert.h>
#include <math.h>
#include <vector>
#include <string>
#include <memory>
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "Screen.h"
#include "ZoomList.h"
#include "RGB.h"
#include <SDL.h>
#include <stdlib.h>
#include <sstream>



namespace fractalnamespace {

class FractalGenerator {

private:
	int m_width;
	int m_height;
	int m_mouseX;
	int m_mouseY;

	double const SCALE{4.0};

	unique_ptr<int[]> m_histogram;//use this array to store the number of pixels that corresponds to each particular number of iterations
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	Screen m_screen;
	ZoomList m_zoomList;
	int m_total{0};


	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;

	bool m_bGotFirstRange{false};
	bool m_clicked{false};

private:

	void calculateIterations();
	void calculateTotalIterations();
	void calculateRangeTotals();
	void drawFractal();
	void writeBitmap(string name);
	int getRange(int iterations) const;

public:
	FractalGenerator(int width, int height);
	void runBitmap(string name);
	void runWindow();
	void addRange(double rangeEnd, const RGB &rgb);
	void addZoom(const Zoom& zoom);
	virtual ~FractalGenerator();

};

}

#endif /* FRACTALGENERATOR_H_ */