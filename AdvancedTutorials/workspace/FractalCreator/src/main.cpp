//============================================================================
// Name        : FractalCreator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdint>
#include <math.h>
#include <memory>
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
//#include "FractalGenerator.h"

using namespace std;
using namespace bitmaptutorial;


int main() {

	int const m_width = 800;
	int const m_height = 600;
	//int const DIFFERENCE = WIDTH - HEIGHT;
	double const SCALE = 4.0;


	//FractalGenerator fractalGenerator(800, 600);
	//fractalGenerator.addZoom( Zoom(295, 202, 0.1) );
	//fractalGenerator.addZoom( Zoom(312, 304, 0.1) );
	//fractalGenerator.run("test.bmp");

	///*

	Bitmap m_bitmap(m_width, m_height);

	//the thing to know about bitmap is y at zero is at the bottom and y max is at the top
	//x is zero at the left and x max is at the far right
	//bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);//so, here we set the pixel in the middle of the screen

	double min = 999999;
	double max = -999999;

	ZoomList m_zoomlist(m_width, m_height);
	m_zoomlist.add( Zoom(m_width/2, m_height/2, SCALE/m_width) );

	m_zoomlist.add( Zoom(295, 202, 0.1) );
	m_zoomlist.add( Zoom(312, 304, 0.1) );


	unique_ptr<int[]> m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});//use this array to store the number of pixels that corresponds to each particular number of iterations
	unique_ptr<int[]> m_fractal(new int[m_width * m_height]{0});


	for (int y = 0; y < m_height; y++){

		for (int x = 0; x < m_width; x++){

			//offsets are always done via addition and subtraction but scaling on the other means scale the coordinate system which is done via multiplication or division
			//double xFractal = (x - WIDTH/2 - DIFFERENCE) * 2.0/HEIGHT;// now the x will range from -400 as min to 400 as max
			//double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
			//int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			pair <double, double> coords = m_zoomlist.doZoom(x, y);
			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			//the coordinate system of the bitmap starts at the bottom left corner, so we iterate by going from y*WIDTH +x, x goes from left to right
			m_fractal[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS){
				m_histogram[iterations]++;
			}

		}
	}

	int total = 0;
	for( int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total +=  m_histogram[i];
	}

	for (int y = 0; y < m_height; y++){

		for (int x = 0; x < m_width; x++){

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = m_fractal[y * m_width + x]  ;

//			uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);
			//Google Mandelbrot histogram colouring for more info
			//color = color * color * color * color;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for (int i = 0; i <= iterations; i++){
					hue += (double)m_histogram[i]/total;
				}

				green = hue * 255;//pow( 255, hue );
			}


			m_bitmap.setPixel(x, y, red, green, blue);


			if (green < min) min = green;
			if (green > max) max = green;

		}
	}


//	int count = 0;
//
//	for( int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
//
//	   cout << histogram[i] << " " << flush;
//
//	   count += histogram[i];
//	}
//
//	cout << endl;
//	cout << count << "; " << WIDTH*HEIGHT << endl;
//
//	cout << endl;
//
	cout << min << ", " << max << endl;


	m_bitmap.write("test.bmp");



//*/

	cout << "Finished" << endl;

	return 0;
}
