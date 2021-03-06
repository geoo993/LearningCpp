//============================================================================
// Name        : SDL_Basic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <math.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>


using namespace std;



unsigned int randomNumberInRange(unsigned int lowEnd, unsigned int highEnd)
{
    if(highEnd < lowEnd)
    {
        unsigned int tempForSwap = highEnd;
        highEnd = lowEnd;
        lowEnd = tempForSwap;
    }

    int rangeVal = (highEnd - lowEnd) + 1;
    return (std::rand() % rangeVal) + lowEnd;
}




int main(int argc, char** argv) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;


	if (SDL_Init(SDL_INIT_VIDEO) < 0){

		cout << "SDL Init failed." << endl;
		return 1;
	}
	cout << "SDL Init succeeded." << endl;


	//create window
	SDL_Window *window = SDL_CreateWindow(
			"Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
				);
	//if window is not working then quit
	if (window == NULL){
		cout << "WINDOW failed." << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}


	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);//adding renderer ensures that our rendering is in synchronize with the vertical alignment of the screen, so the computer screen is going to refresh a certain number per seconds (maybe 30 times per second )
	SDL_Texture *texture = SDL_CreateTexture(
			renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH,
			SCREEN_HEIGHT
			);//this is the texture that the renderer is going to render, and which you write the pixel infomation to


	//if renderer is not working then quit
	if (renderer == NULL){
		cout << "Could not create renderer." << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	//if texture is not working then quit
	if (texture == NULL){
		cout << "Could not create texture." << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

//	unsigned int rand = randomNumberInRange(1, 255);
//	Uint32 randomUINT32 = (Uint32)rand;

	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	//menset allows you to set a block of memory, with a particular value
	//first part is the buffer
	//second argument is the value we write into every bite which in this case is 255, which is the maximum value which going to give us white color
	//the third part is the number of bites we set overall
	//set memset value to (255 or 0xFF for white) or zero for black
	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	//this allows you to pick a pixel from the buffer, hex decimals are a lot easier
	//FF is maximum value you can set in a single bite and the next bites which is (FF,FF,FF,FF)
	//hex decimals represent the bites, for rgba values, so the first two value after x is (0x'00') r values, then the next two values (0x00'00') is g values, and the next two (0x0000'00') after is b values, and finally we have the alpha region (0x000000'00') is a values
	// if you want to read a value to hex, in hex you can use up to 15 characters(0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F), you use binary to covert each part of rgba(rrr,ggg,bbb,aaa), for example [(234,12,45,254)], based on [4096,256,16,1] which means [1,1,1,1,1,1,1,1,1,1,1,1,1]in binary place values is (4096,2048,1024,512),(256,128,64,32),(16,8,4,2),(1). So based on 234 in r, 16 can is the only number that can go into 234, it does it 14 times(224)  with remainder of 10 which makes the hex value 14 and 10 meaning EA
	//buffer[30000] = 0xFFFFFFFF;

	for (int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++){
		buffer[i] = 0xFF00FFFF;
	}



	SDL_Event event; //used to store any events from the OS
	bool runningGame = true; //used to determine if we are running the game

	Uint8 red = 255;
	Uint8 blue = 0;

	//created game loop, which is a loop that will run for as long as the game is running
	while (runningGame){
		//in this loop we will update particles, draw particles and we will check for messages/events like button/mouse click


		// Animate color
		//unsigned int redValue = 255;
		//unsigned int greenValue = 255;
		//unsigned int blueValue = 255;
		int elapsed = SDL_GetTicks();
		//double green = (1 + sin(elapsed * 0.001)) * ((green+1)/2);//sin takes a number and return with a range minus plus 1
		//int green = (1 + sin(M_PI/2)) * ((greenValue+1)/2);
		//if (green > max) max = green;

		unsigned char green = (unsigned char )((1 + sin(elapsed * 0.001)) * 128);

		for(int y=0; y < SCREEN_HEIGHT; y++){
			for(int x=0; x < SCREEN_WIDTH; x++){

				Uint32 color = 0;

				color += red;
				color <<= 8;
				color += green;
				color <<= 8;
				color += blue;
				color <<= 8;
				color += 0xFF;  // this is alpha channel FF, it is opaque

				buffer[(y * SCREEN_WIDTH) + x] = color;

			}
		}


		SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);



		//poll for events from SDL, this check for the events that are happening, it will fetch the latest event in the queue of possible events that have been built up
	      while(SDL_PollEvent(&event))// Referencing or getting the address of this event object
	      {

	    	  //Here we are also going to loop through all the possible events by the user and process them


	          // determine if the user still wants to have the window open
	          // (this basically checks if the user has pressed 'X')

	    	  //runningGame = event.type != SDL_QUIT;
	    	  if (event.type == SDL_QUIT){//the SDL_QUIT event is raised when the user click one of the declarations on the window, in this case is the when they click the cross on the corner of the window
	    		  runningGame = false;
	    	  }


	      }
	}


	delete [] buffer;//delete removes array
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
