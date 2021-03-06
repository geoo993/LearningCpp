/*
 * Screen.h
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>//must install sdl
#include <assert.h>

namespace fractalnamespace {

class Screen {

public:
	int m_screenWidth{0};
	int m_screenHeight{0};

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
	const static int screenColor = 60;


public:
	Screen(int width, int height);
	virtual ~Screen();

	bool init();
	bool proccessEvents();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void update();
	void boxBlur();
	void clear();
	void close();


};

}

#endif /* SCREEN_H_ */
