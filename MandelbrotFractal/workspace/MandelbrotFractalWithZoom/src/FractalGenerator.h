/*
 * FractalGenerator.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef FRACTALGENERATOR_H_
#define FRACTALGENERATOR_H_

#include <SDL.h>
#include <vector>
#include <string>
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "Screen.h"
#include "ZoomList.h"
#include "RGB.h"



namespace fractalnamespace {

class FractalGenerator {

private:
	int m_width;
	int m_height;

	double const SCALE{4.0};

	unique_ptr<int[]> m_histogram;//use this array to store the number of pixels that corresponds to each particular number of iterations
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	Screen m_screen;
	ZoomList m_zoomList;

	vector <int> m_fractal_copy;

	vector<RGB> m_colors;
	int m_total{0};
	vector<pair<int,int>> m_zooms;

	bool m_bGotFirstRange{false};
	bool smooth_color;
	string output_type;

private:

	void calculateIterations();
	void calculateTotalIterations();
	void drawFractal();
	void writeBitmap(string name);

public:
	FractalGenerator(int width, int height, bool smooth_color, string output_type);
	void run();
	void runBitmap(string name);
	void runWindow();
	void addZoomIn(const Zoom& zoom);
	void addZoomOut(const Zoom& zoom);
	std::tuple<int, int, int> get_rgb_piecewise_linear(int n, int iter_max);
	std::tuple<int, int, int> get_rgb_smooth(int n, int iter_max) ;
	void setUp();
	void resetAll();
	virtual ~FractalGenerator();

};

}

#endif /* FRACTALGENERATOR_H_ */
