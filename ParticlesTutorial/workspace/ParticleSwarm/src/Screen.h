/*
 * Screen.h
 *
 *  Created on: Oct 8, 2016
 *      Author: GeorgeQuentin
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace programmingparticles {

class Screen {

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;


private:
	//using m for making that these are member variables
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:

	Screen();
	bool init();
	bool proccessEvents();
	void close();


};

}

#endif /* SCREEN_H_ */