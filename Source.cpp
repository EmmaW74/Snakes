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
- END GAME - TIDY UP AND GIVE OPTION TO PLAY AGAIN
- Diamond - Points assigned in constructor could be random & image could show points
- top score held in file & shown on header
- star gem 
- global variables for header and navigation areas 
- myApp on_close() at end 
- Add molehills to avoid - rise up then down
- Change to smart pointers
- Random start position
- Make gem collision more accurate
- End game - show score and advise if new high score

image <a href='https://www.freepik.com/vectors/background'>Background vector created by macrovector - www.freepik.com</a>
*/