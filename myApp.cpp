#include "myApp.h"
#include "myWindow.h"
#include "mySnake.h"
#include <iostream>
#include <stdlib.h>


myApp::myApp(){
	game_window = new myWindow();
	game_snake1 = new mySnake();
	Running = true;
	Paused = false;
	std::cout << "myApp constructor called" << std::endl;
}
mySnake* myApp::getSnake() {
	return game_snake1;
}

void myApp::myContinue() {
	if (!Paused) {
		game_snake1->changeDirection(game_snake1->getDirection());
		game_window->drawSnake(*game_snake1);
		if (game_snake1->checkCollision()) {
			gameOver(game_window);
		}
	}
}

myWindow* myApp::getWindow() {
	return game_window;
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
		case SDLK_SPACE:
			Paused = !Paused;
			break;

		case SDLK_UP:
			if (!Paused) {
				std::cout << "UP" << std::endl;
				if (game_snake1->getDirection() == DOWN) {
					break;
				}
				else {
					game_snake1->changeDirection(UP);
					if (game_snake1->checkCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawSnake(*game_snake1);
					}
					break;
				}
			}

		case SDLK_DOWN:
			if (!Paused) {
				std::cout << "DOWN" << std::endl;
				if (game_snake1->getDirection() == UP) {
					break;
				}
				else {
					game_snake1->changeDirection(DOWN);
					if (game_snake1->checkCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawSnake(*game_snake1);
					}
					break;
				}
			}
		case SDLK_LEFT:
			if (!Paused) {
				std::cout << "LEFT" << std::endl;

				if (game_snake1->getDirection() == RIGHT) {
					break;
				}
				else {

					game_snake1->changeDirection(LEFT);
					if (game_snake1->checkCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawSnake(*game_snake1);
					}
					game_window->drawSnake(*game_snake1);
					break;
				}
			}

		case SDLK_RIGHT:
			if (!Paused) {
				std::cout << "RIGHT" << std::endl;
				if (game_snake1->getDirection() == LEFT) {
					break;
				}
				else {
					game_snake1->changeDirection(RIGHT);
					if (game_snake1->checkCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawSnake(*game_snake1);
					}
					game_window->drawSnake(*game_snake1);
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