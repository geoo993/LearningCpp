//============================================================================
// Name        : MandelbrotSDL2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include "Screen.h"
#include <complex>

using namespace std;

int main() {

	// Initialise screen
	Screen screen;
	if (screen.init() == false) {
		cout << "ERROR INITIALIZING SCREEN WITH SDL." << endl;
	}
	cout << "SDL Init succeeded." << endl;


	int max = 1000;

	while (true) {

		for (int row = 0; row < Screen::SCREEN_HEIGHT; row++) {
			for (int col = 0; col < Screen::SCREEN_WIDTH; col++) {

				double c_re = (col - Screen::SCREEN_WIDTH/2.0)*4.0/Screen::SCREEN_WIDTH;
				double c_im = (row - Screen::SCREEN_HEIGHT/2.0)*4.0/Screen::SCREEN_WIDTH;
				double x = 0;
				double y = 0;
				int iteration = 0;

				while ( (x*x+y*y <= 4.0 ) && iteration < max) {

					double x_new = x*x - y*y + c_re;
					y = 2*x*y + c_im;
					x = x_new;
					iteration++;
				}

				if (iteration < max){
					screen.setPixel(col, row, 255, 255, 255);
				} else {
					screen.setPixel(col, row, 0, 0, 0);
				}
			}
		}

		// Draw the screen
		screen.update();

		// Check for messages/events
		if(screen.proccessEvents() == false){
			break;
		}

	}

	screen.close();

	return 0;
}
