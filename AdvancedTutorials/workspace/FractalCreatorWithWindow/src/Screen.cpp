/*
 * Screen.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */


#include "Screen.h"


using namespace std;

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

	//cout << "SCREEN CONSTRUCTOR " << endl;
}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		//cout << "SDL Init failed." << endl;
		return false;
	}

	m_window = SDL_CreateWindow("Mandelbrot Fractal", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, m_screenWidth, m_screenHeight,
			SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		//cout << "WINDOW failed." << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, m_screenWidth, m_screenHeight);

	if (m_renderer == NULL) {
		//cout << "Could not create renderer." << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return 3;
	}

	if (m_texture == NULL) {
		//cout << "Could not create texture." << SDL_GetError() << endl;
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

	//cout << "SCREEN DESTRUCTOR " << endl;
}

}
