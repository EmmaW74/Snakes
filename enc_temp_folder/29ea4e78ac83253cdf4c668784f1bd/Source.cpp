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
- timer to make gems appear and disappear (variable in prize for length of time on display - counter on frame 1 to ?? then restart)
- myApp on_close() at end 
- Check memory management (every create Texture needs a destroy texture)
- add to length after x seconds & increase points - timer?
- add prizes to pick up (points / slow down / reduce length)
- Add molehills to avoid - rise up then down
- 
- Random start position
- Separate move snake from change direction

image <a href='https://www.freepik.com/vectors/background'>Background vector created by macrovector - www.freepik.com</a>
*/