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
- top score held in file & shown on header
- star gem that speeds game up
- global variables for header and navigation areas (and stop gems and snake appearing over the top of the header)
- myApp on_close() at end 
- Check memory management (every create Texture needs a destroy texture)
- add to length after x seconds & increase points - timer?
- add prizes to pick up (points / slow down / reduce length)
- Add molehills to avoid - rise up then down
- Change to smart pointers
- Random start position
- Make gem collision more accurate

image <a href='https://www.freepik.com/vectors/background'>Background vector created by macrovector - www.freepik.com</a>
*/