/*
 * FractalGenerator.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#include "FractalGenerator.h"
#include <iostream>

namespace fractalnamespace {


void FractalGenerator::addZoomIn(const Zoom& zoom){
	m_zoomList.addUp(zoom);
}

void FractalGenerator::addZoomOut(const Zoom& zoom){
	m_zoomList.addDown(zoom);
}


void FractalGenerator::run(){

	if (output_type == "bitmap"){
		runBitmap("MandelbrotFractal.bmp");
	}else if (output_type == "window") {
		runWindow();
	}
}

void FractalGenerator::runBitmap(string name){

	setUp();
	writeBitmap(name);

}

void FractalGenerator::runWindow(){


	if (m_screen.init() == false) {
		assert ("ERROR INITIALIZING SCREEN WITH SDL.\n");
	}

	setUp();

	bool running = true;
	while (running) {

		// Draw the screen
		m_screen.update();

		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					m_zooms.push_back(std::make_pair(event.motion.x, event.motion.y));
					addZoomIn(Zoom(event.motion.x, event.motion.y, 0.3) );
					setUp();
				}
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					m_zooms.push_back(std::make_pair(event.motion.x, event.motion.y));
					addZoomOut(Zoom(event.motion.x, event.motion.y, 0.3) );
					setUp();
				}



			}

			if (event.type == SDL_KEYDOWN){

				switch( event.key.keysym.sym ){

					case SDLK_SPACE:

						for (int i = m_zooms.size() ; i >= 0; i--)
						{
							m_zoomList.reset(i);
							setUp();
						}

						resetAll();

						break;
					default:
						break;
				}

			}


		}


	}

	m_screen.close();

}

void FractalGenerator::setUp(){
	calculateIterations();
	calculateTotalIterations();
	drawFractal();
}


FractalGenerator::FractalGenerator(int width, int height, bool smooth_color, string output_type):
	m_width(width),
	m_height(height),
	m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
	m_fractal(new int[m_width * m_height]{0}),
	m_bitmap(m_width, m_height),
	m_screen(m_width, m_height),
	m_zoomList(m_width, m_height),
	m_total(0),
	m_zooms({}),
	smooth_color(smooth_color),
	output_type(output_type)
	{

	int n = m_width * m_height;
	m_fractal_copy.reserve(n);
	for (int i = 0; i < n; ++i) {
	    m_fractal_copy.push_back(0);
	}

	m_zoomList.addUp( Zoom(m_width/2, m_height/2, SCALE/m_width) );

}

void FractalGenerator::calculateIterations(){

	for (int y = 0; y < m_height; y++){

		for (int x = 0; x < m_width; x++){

			pair <double, double> coords = m_zoomList.doZoom(x, y);
			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			m_fractal[y * m_width + x] = iterations;
			m_fractal_copy[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS){
				m_histogram[iterations]++;
			}

		}
	}

}

void FractalGenerator::calculateTotalIterations(){

	for( int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		m_total +=  m_histogram[i];
	}

}



void FractalGenerator::drawFractal(){

	std::cout << " length of m_fractal: " << m_fractal_copy.size() << std::endl;

	RGB rgb(0, 255, 255);

	for (int y = 0; y < m_height; y++){

		for (int x = 0; x < m_width; x++){

			int iterations = m_fractal[y * m_width + x]  ;

			if (!smooth_color){
				rgb.get_rgb_smooth(iterations, 100);
			}else{
				rgb.get_rgb_piecewise_linear(iterations, 100);
			}

			if (output_type == "bitmap"){
				m_bitmap.setPixel(x, y, rgb.r, rgb.g, rgb.b);
			}else if (output_type == "window") {
				m_screen.setPixel(x, y, rgb.r, rgb.g, rgb.b);
			}

		}
	}

}


void FractalGenerator::writeBitmap(string name){
	m_bitmap.write(name);
}


void FractalGenerator::resetAll(){

	m_total = 0;
	m_bGotFirstRange = false;
	m_colors.clear();

	m_histogram = std::unique_ptr<int[]>(new int[Mandelbrot::MAX_ITERATIONS]{0});
	m_fractal = std::unique_ptr<int[]>(new int[m_width * m_height]{0});

	m_zooms.erase (m_zooms.begin()+1, m_zooms.end());
	m_zoomList.resize();

}


FractalGenerator::~FractalGenerator() {}

}
