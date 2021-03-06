//============================================================================
// Name        : MandelbrotSDL2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;

int main() {

	// Initialise screen
	Screen screen;
	if (screen.init() == false) {
		cout << "ERROR INITIALIZING SCREEN WITH SDL." << endl;
	}
	cout << "SDL Init succeeded." << endl;


	int max = 1000;
	int randomr = (rand() % 156);
	int randomg = (rand() % 156);
	int randomb = (rand() % 156);

	cout << random;

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

				int colorValueR=0;
				int colorValueG=0;
				int colorValueB=0;

				for (int i=0;i<iteration;i++)
				{

					if (i >= 512)
					{
						colorValueR = i - 512;
						colorValueG = 255 - colorValueR;
					}
					else if (i >= 256)
					{
						colorValueG = i - 256;
						colorValueB = 255 - colorValueG;
					}
					else
					{
						colorValueB = i;
					}
				}



				if (iteration < max){
					screen.setPixel(col, row, colorValueR + randomr, colorValueG + randomg, colorValueB + randomb);
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
