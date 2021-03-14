#include <SDL.h>
#include <SDL_image.h>
#include "myApp.h"
#include <iostream>

int main(int argc, char* args[])
{
	myApp game;
	while (game.checkRunning()) {
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {
			game.OnEvent(e);
		}
		else {
			game.myContinue();
			std::cout << "Continue" << std::endl;
			
		}
	}
	//Free resources and close SDL
	//game.OnClose();

	return 0;
}


/*
- tidy code (sort continue to avoid setting get direction on same direction)
- Check memory management (every create Texture needs a destroy texture)
- add to length after x seconds & increase points - timer?
- add prizes to pick up (points / slow down / reduce length)
- Add molehills to avoid - rise up then down
- Text intro - Title & use arrows to navigate
- Random start position

image <a href='https://www.freepik.com/vectors/background'>Background vector created by macrovector - www.freepik.com</a>
*/