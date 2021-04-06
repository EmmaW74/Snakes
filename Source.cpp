#include "SDL.h"
#include "myApp.h"
#include <iostream>

int main(int argc, char* args[])
{
	myApp game;
	game.runGame();
	
	return 0;
}


/*
- bug - delay on game over
- top score held in file & shown on header
- star gem 
- global variables for header and navigation areas 
- myApp on_close() at end 
- Check memory management (every create Texture needs a destroy texture)
- Add molehills to avoid - rise up then down
- Change to smart pointers
- Random start position
- Make gem collision more accurate
- End game - show score and advise if new high score

image <a href='https://www.freepik.com/vectors/background'>Background vector created by macrovector - www.freepik.com</a>
*/