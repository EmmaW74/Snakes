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
- Add comments for more complicated functions
- Diamond - Points assigned in constructor could be random & image could show points
- star gem 
- Add molehills to avoid - rise up then down
- Change to smart pointers
- Make gem collision more accurate

image <a href='https://www.freepik.com/vectors/background'>Background vector created by macrovector - www.freepik.com</a>
*/