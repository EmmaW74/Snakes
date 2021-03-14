#ifndef MYAPP_H
#define MYPP_H
#include "SDL.h"
#include "myDot.h"
#include "mySnake.h"
#include "myWindow.h"
#include <SDL_image.h>
#include <string>
#include <vector>

class myApp
{
private:
	bool Running;
	bool Paused;
	mySnake* game_snake1;
	myWindow* game_window;

public:
	myApp();
	void OnEvent(SDL_Event& e); // on event do something
	bool checkRunning();
	void stopGame();
	mySnake* getSnake();
	myWindow* getWindow();
	void myContinue();
	void gameOver(myWindow* window);
	~myApp();
};

#endif


