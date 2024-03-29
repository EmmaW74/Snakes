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
#include "dimensions.h"
#include "introController.h"
#include "myGameOver.h"

//Handles the logic of the game
class myApp
{
private:
	bool started;
	bool Running;
	bool Paused;
	std::shared_ptr<mySnake> game_snake1;
	myWindow* game_window;
	std::shared_ptr<myPrizePot> current_prizes;
	std::shared_ptr <Score_controller> score; 
	std::shared_ptr <RenderableImage> myBackground;
	std::shared_ptr <introController> intro;
	int gameTimer;
	std::shared_ptr <Dimensions> measurements;
	std::shared_ptr<myGameOver> game_over_control;

public:
	myApp();
	
	// game progress methods
	void updateStarted();
	void runGame();
	void OnEvent(SDL_Event& e); 
	void myContinue();
	void addPrize();
	void collectPoints();
	void stopGame();
	void gameOver();
	void reset_game();

	// gets methods
	bool getStarted() const;
	bool getRunning() const;
	std::shared_ptr<mySnake> getSnake() const;
	myWindow* getWindow() const;
	int get_timer() const;

	// general tasks
	void incrementGameTimer();
	int random_position() const;
	
};

#endif


