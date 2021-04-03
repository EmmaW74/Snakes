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
	bool started;
	bool Running;
	bool Paused;
	mySnake* game_snake1;
	myWindow* game_window;
	std::vector<myPrize*> current_prizes;
	int score = 100;
	int gameTimer;

public:
	myApp();
	void incrementGameTimer();
	int get_timer();
	void addPrize();
	void runGame();
	void OnEvent(SDL_Event& e); // on event do something
	bool checkRunning();
	int random_position();
	bool getStarted();
	void updateStarted();
	void collectPoints();
	void stopGame();
	mySnake* getSnake();
	myWindow* getWindow();
	void myContinue();
	void gameOver(myWindow* window);
	~myApp();
};

#endif


