/*
 * Screen.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */


#include "Screen.h"

namespace fractalnamespace {

Screen::Screen(int width, int height) :
	m_screenWidth(width),
	m_screenHeight(height),
	m_window(NULL),
	m_renderer(NULL),
	m_texture(NULL),
	m_buffer1(NULL),
	m_buffer2(NULL) {
	// TODO Auto-generated constructor stub

	//"SCREEN CONSTRUCTOR ";
}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		assert ("SCREEN INITIALISATION FAILED.\n");
		return false;
	}

	m_window = SDL_CreateWindow("Mandelbrot Fractal", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, m_screenWidth, m_screenHeight,
			SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		assert( "WINDOW FAILED: could not created window.");
		assert ( SDL_GetError() );
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, m_screenWidth, m_screenHeight);

	if (m_renderer == NULL) {
		assert ( "RENDERER FAILED: Could not create renderer.");
		assert ( SDL_GetError() );
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return 3;
	}

	if (m_texture == NULL) {
		assert ( "TEXTURE FAILED: Could not create texture.");
		assert ( SDL_GetError() );
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return 4;
	}

	m_buffer1 = new Uint32[m_screenWidth * m_screenHeight];
	m_buffer2 = new Uint32[m_screenWidth * m_screenHeight];

	memset(m_buffer1, screenColor, m_screenWidth * m_screenHeight * sizeof(Uint32));
	memset(m_buffer2, screenColor, m_screenWidth * m_screenHeight * sizeof(Uint32));

	return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){

	if (x < 0 || x >= m_screenWidth || y < 0 || y >= m_screenHeight)
	{
		return;
	}
	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;  // this is alpha channel FF, it is opaque

	//RGBA
	m_buffer1[(y * m_screenWidth) + x] = color;


}

void Screen::clear(){

	memset(m_buffer1, screenColor, m_screenWidth * m_screenHeight * sizeof(Uint32));

}

void Screen::boxBlur(){
	//swap the buffers so pixels is in m_buffer2 and we are drawing in m_buffer1.
	Uint32 *temp = m_buffer1; //first we store the location m_buffer1 was pointing at
	m_buffer1 = m_buffer2; //then we change m_buffer1 to point at m_buffer2 memory which is clean.
	m_buffer2 = temp; // then we tell m_buffer2 to point at the original value of stored in m_buffer1

	//now we are going to keep blurring the screen more and more
	for (int y=0; y < m_screenHeight; y++){

		for(int x=0; x < m_screenWidth; x++){


			/*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 *
			 */

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			// this means that whatever pixel we are looking at, we will end up calling the  other pixels around it
			for(int row= -1; row<=1; row++){
				for(int col= -1; col<=1; col++){

					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && m_screenWidth && currentY >= 0 && currentY < m_screenHeight){
						Uint32 color = m_buffer2[currentY*m_screenWidth + currentX];

						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;


						redTotal += red;
						greenTotal += green;
						blueTotal += blue;

					}

				}
			}


			Uint8 redResult = redTotal / 9;
			Uint8 greenResult = greenTotal / 9;
			Uint8 blueResult = blueTotal / 9;

			setPixel(x, y, redResult, greenResult, blueResult);


		}
	}


}


void Screen::update() {

	SDL_UpdateTexture(m_texture, NULL, m_buffer1, m_screenWidth * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

}


bool Screen::proccessEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT) {
			return false;
		}
	}

	return true;
}


void Screen::close() {

	delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);

	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub

	//"SCREEN DESTRUCTOR ";
}

}
