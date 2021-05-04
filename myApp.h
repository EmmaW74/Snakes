#ifndef MYAPP_H
#define MYPP_H
#include "SDL.h"
#include "MyDot.h"
#include "mySnake.h"
#include "myWindow.h"
#include <SDL_image.h>
#include <string>
#include <vector>
#include "myPrizePot.h"
#include "RenderableText.h"
#include "Score_controller.h"

class myApp
{
	//This class handles the logic of the game
private:
	bool started;
	bool Running;
	bool Paused;
	std::shared_ptr<mySnake> game_snake1;
	myWindow* game_window;
	std::shared_ptr<myPrizePot> current_prizes;
	int score = 100;
	//std::shared_ptr <Score_controller> score; //Need to create this in constructor and add to collect points and draw frame
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
	const bool getStarted();
	const bool getRunning();
	const std::shared_ptr<mySnake> getSnake();
	const myWindow* getWindow();
	const int get_timer();

	// general tasks
	void incrementGameTimer();
	int random_position();
};

#endif


