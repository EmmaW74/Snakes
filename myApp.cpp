#include "myApp.h"
#include "myWindow.h"
#include "mySnake.h"
#include "Ruby.h"
#include "Diamond.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

myApp::myApp(){
	game_window = new myWindow();
	game_snake1 = new mySnake();
	Running = true;
	Paused = false;
	started = false;
	gameTimer = 0;
	srand(time(NULL));
	std::cout << "myApp constructor called" << std::endl;
}
mySnake* myApp::getSnake() {
	return game_snake1;
}

int myApp::random_position() {
	//srand(time(NULL));
	//return rand() % 300 + 50;
	return 30 + (int)(420.0 * (rand() / (RAND_MAX + 30.0)));
}
void myApp::runGame() {
	SDL_Event e;
	while (!getStarted()) {
		//Wait for Enter to start the game
		if (SDL_PollEvent(&e) != 0) {
			if (e.key.keysym.sym == SDLK_RETURN) {
				updateStarted();
			}
		}
	}
	game_window->setBackground();
	game_window->countdown();
	
	while (checkRunning()) {
		if (!Paused) {
			incrementGameTimer();
			addPrize();
		}
		//While running, action event or if no event continue to move snake
		if (SDL_PollEvent(&e) != 0) {
			OnEvent(e);
		}
		else {
			myContinue();
			std::cout << "Continue" << std::endl;
		}
	}
}
void myApp::incrementGameTimer() {
	//increments between 0 - 49 then restarts
	gameTimer += 1;
	gameTimer = gameTimer % 50;
}

void myApp::addPrize() {
	if (get_timer() == 30) {
		
		int type = 1 + (int)(2.0 * (rand() / (RAND_MAX + 1.0)));
		if (type == 1) {
			current_prizes.push_back(new Ruby(random_position(), random_position()));
		}
		else {
			current_prizes.push_back(new Diamond(random_position(), random_position()));
		}
	}
}

int myApp::get_timer() {
	return gameTimer;
}
void myApp::myContinue() {

	if (!Paused) {
		game_snake1->changeDirection(game_snake1->getDirection());
		game_window->drawFrame(game_snake1,current_prizes,score);
		if (game_snake1->checkTailCollision()) {
			gameOver(game_window);
		}
		collectPoints();
	}
}

void myApp::collectPoints(){
	for (int x = 0; x < current_prizes.size(); x++) {
		if (game_snake1->checkPrizeCollision(current_prizes.at(x))) {
			score += current_prizes.at(x)->get_points();
			current_prizes.erase(current_prizes.begin() + x);
			game_snake1->increaseSnakeSpeed();
			game_snake1->increaseLength();
		}
	}
}

myWindow* myApp::getWindow() {
	return game_window;
}

void myApp::updateStarted() {
	started = !started;
}

bool myApp::getStarted() {
	return started;
}

void myApp::OnEvent(SDL_Event& e) {
	//User requests quit
	if (e.type == SDL_QUIT)
	{
		stopGame();
	}
	else if (e.type == SDL_KEYDOWN)
	{
		//Select surfaces based on key press
		switch (e.key.keysym.sym)
		{

		case SDLK_RETURN:
			updateStarted();
			break;

		case SDLK_SPACE:
			Paused = !Paused;
			break;

		case SDLK_UP:
			if (!Paused) {
				std::cout << "UP" << std::endl;
				if (game_snake1->getDirection() == Direction::DOWN) {
					break;
				}
				else {
					game_snake1->changeDirection(Direction::UP);
					if (game_snake1->checkTailCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawFrame(game_snake1,current_prizes,score);
						collectPoints();
					}
					break;
				}
			}

		case SDLK_DOWN:
			if (!Paused) {
				std::cout << "DOWN" << std::endl;
				if (game_snake1->getDirection() == Direction::UP) {
					break;
				}
				else {
					game_snake1->changeDirection(Direction::DOWN);
					if (game_snake1->checkTailCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawFrame(game_snake1, current_prizes,score);
						collectPoints();
					}
					break;
				}
			}
		case SDLK_LEFT:
			if (!Paused) {
				std::cout << "LEFT" << std::endl;

				if (game_snake1->getDirection() == Direction::RIGHT) {
					break;
				}
				else {

					game_snake1->changeDirection(Direction::LEFT);
					if (game_snake1->checkTailCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawFrame(game_snake1, current_prizes, score);
						collectPoints();
					}
					//game_window->drawFrame(game_snake1, current_prizes, score);
					break;
				}
			}

		case SDLK_RIGHT:
			if (!Paused) {
				std::cout << "RIGHT" << std::endl;
				if (game_snake1->getDirection() == Direction::LEFT) {
					break; 
				}
				else {
					game_snake1->changeDirection(Direction::RIGHT);
					if (game_snake1->checkTailCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawFrame(game_snake1, current_prizes, score);
						collectPoints();
					}
					//game_window->drawFrame(game_snake1, current_prizes, score);
					break;
				}
			}

		}
	}
}
bool myApp::checkRunning() {
	std::cout << "Check running" << std::endl;
	return Running;
}

void myApp::stopGame() {
	Running = false;
}

void myApp::gameOver(myWindow* window) {
	window->showGameOver();
	Running = false;
	SDL_Delay(5000);
	exit(0);
}

myApp::~myApp() {
	std::cout << "myApp destructor called" << std::endl;
}