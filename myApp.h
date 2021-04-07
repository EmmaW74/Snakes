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
	std::shared_ptr<mySnake> game_snake1;
	myWindow* game_window;
	std::vector<std::shared_ptr<myPrize>> current_prizes;
	int score = 100;
	int gameTimer;

public:
	myApp();
	
	// game progress
	void updateStarted();
	void runGame();
	void OnEvent(SDL_Event& e); 
	void myContinue();
	void addPrize();
	void collectPoints();
	void stopGame();
	void gameOver(myWindow* window);
	
	// gets
	bool getStarted();
	bool getRunning();
	std::shared_ptr<mySnake> getSnake();
	myWindow* getWindow();

	// general tasks
	void incrementGameTimer();
	int get_timer();
	int random_position();
};

#endif


