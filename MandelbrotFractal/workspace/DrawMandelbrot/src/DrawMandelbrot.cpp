//============================================================================
// Name        : DrawMandelbrot.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <complex>
#include "Screen.h"
#include <SDL.h>

int main() {

	enum{ Width = 800, Height = 720 };

	// Initialise screen
	Screen screen(Width, Height);
	if (screen.init() == false) {
		std::cerr << "ERROR INITIALIZING SCREEN WITH SDL.\n";
	}

	enum{ PaletteSize = 100 };
	int palette[PaletteSize + 1][3];
	for (int i = 0; i <= PaletteSize; ++i) {

		palette[i][0] = i < 2 * PaletteSize / 3 ? i * 255 * 3 / (2 * PaletteSize) : 255;
		palette[i][1] = i < PaletteSize / 3 ? 0 : (i - PaletteSize / 3) * 255 * 3 / (2 * PaletteSize);
		//palette[i][2] = i < 2 / PaletteSize / 3 ? 0 : (i - 2 * PaletteSize / 3) * 255 / (PaletteSize / 3);
		palette[i][2] = 0;


		//palette[i][0] = i * 255 / PaletteSize;
		//palette[i][1] = i * 255 / PaletteSize;
		//palette[i][2] = i * 255 / PaletteSize;
	}

	int m_mouseX;
	int m_mouseY;
	bool m_clicked = false;
	double scale = 1.0;

	while (true) {

		if (SDL_GetMouseState(&m_mouseX, &m_mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT) ) {

			if (m_clicked == false){
				std::cout << "x: " << m_mouseX << "\n";
				std::cout << "y: " << m_mouseY << "\n";

				scale -= 0.1;

				//m_clicked = true;
				std::cout << "scale is " << scale <<  "\n";


			}
		}

		for (int y = 0; y < Height; ++y) {
			for (int x = 0; x < Width; ++x) {

				std::complex<double> c ( scale * ((m_mouseX + x) - (Width - Height) / 2) / Height * 4.0 - 2.0, scale * (m_mouseY + y) / Height * 4.0 - 2.0);
				std::complex<double> z (0.0, 0.0);

				int iterations = 0;
				while (iterations < PaletteSize){
					z = z * z + c;

					if(abs(z) > 2.0)
						break;

					++iterations;
				}

				screen.setPixel(x, y, palette[iterations][0], palette[iterations][1], palette[iterations][2]);
				//screen.setPixel(x, y, iterations, iterations, iterations);

			}
		}

		// Draw the screen
		screen.update();

		//m_clicked = false;

		// Check for messages/events
		if(screen.proccessEvents() == false){
			break;
		}

	}

	screen.close();

	return 0;
}
