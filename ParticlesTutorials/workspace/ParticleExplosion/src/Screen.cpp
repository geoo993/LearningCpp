/*
 * Screen.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include "Screen.h"

using namespace std;

namespace programmingparticles {

Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
	// TODO Auto-generated constructor stub

	cout << "SCREEN CONSTRUCTOR " << endl;

}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		cout << "SDL Init failed." << endl;
		return false;
	}

	m_window = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		cout << "WINDOW failed." << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		cout << "Could not create renderer." << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return 3;
	}

	if (m_texture == NULL) {
		cout << "Could not create texture." << SDL_GetError() << endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return 4;
	}

	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_buffer[i] = 0x00FFFFFF;
	}

	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	cout << "SDL Init succeeded." << endl;

	return true;
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

	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);

	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub

	cout << "SCREEN DESTRUCTOR " << endl;
}

}