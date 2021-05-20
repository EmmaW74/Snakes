#include "myApp.h"
#include "myWindow.h"
#include "mySnake.h"
#include "Ruby.h"
#include "Diamond.h"
#include <iostream>
#include "dimensions.h"


myApp::myApp(){
	
	measurements = std::make_shared<Dimensions>(15,45,20,150);
	game_window = new myWindow(measurements);
	game_snake1 = std::make_shared<mySnake> (measurements);
	current_prizes = std::make_shared<myPrizePot>();
	Running = true;
	Paused = false;
	started = false;
	gameTimer = 0;
	srand(time(NULL));
	score = std::make_shared<Score_controller>(5, 5, 0xff, 0xff, 0xff);
	myBackground = std::make_shared<RenderableImage>(0,0,"Images/grass.jpg"); 
	
}

void myApp::updateStarted() {
	started = !started;
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
	
	game_window->countdown(myBackground);

	while (getRunning()) {
		//if (!Paused) {
		//	incrementGameTimer();
		//	addPrize();
		//}
		//While running, action event or if no event continue to move snake
		if (Paused) {
			if (SDL_PollEvent(&e) != 0 && e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_SPACE) {
					Paused = !Paused;
				}
			}
		}
		else {
			if (SDL_PollEvent(&e) != 0) {
				OnEvent(e);
			}
			else {
				myContinue();
			}
		}
	}
}
/*
void myApp::OnEvent(SDL_Event& e) {
	//User requests quit
	if (e.type == SDL_QUIT)
	{
		stopGame();
	}
	else if (e.type == SDL_KEYDOWN)
	{
		//Action key presses
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
			
				if (game_snake1->getDirection() == Direction::DOWN) {
					break;
				}
				else {
					game_snake1->changeDirection(Direction::UP);
					if (game_snake1->checkTailCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawFrame(game_snake1, current_prizes, score);
						collectPoints();
					}
					break;
				}
			}

		case SDLK_DOWN:
			if (!Paused) {
				
				if (game_snake1->getDirection() == Direction::UP) {
					break;
				}
				else {
					game_snake1->changeDirection(Direction::DOWN);
					if (game_snake1->checkTailCollision()) {
						gameOver(game_window);
					}
					else {
						game_window->drawFrame(game_snake1, current_prizes, score);
						collectPoints();
					}
					break;
				}
			}
		case SDLK_LEFT:
			if (!Paused) {

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

					break;
				}
			}

		case SDLK_RIGHT:
			if (!Paused) {
				
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

					break;
				}
			}

		}
	}
}
*/

void myApp::OnEvent(SDL_Event& e) {
	//User requests quit
	if (e.type == SDL_QUIT)
	{
		stopGame();
	}
	else if (e.type == SDL_KEYDOWN)
	{
			switch (e.key.keysym.sym)
			{

			case SDLK_RETURN:
				updateStarted();
				break;

			case SDLK_SPACE:
				Paused = !Paused;
				break;

			case SDLK_UP:
				game_snake1->changeDirection(Direction::UP);
				break;

			case SDLK_DOWN:
				game_snake1->changeDirection(Direction::DOWN);
				break;
				
			case SDLK_LEFT:
				game_snake1->changeDirection(Direction::LEFT);
				break;

			case SDLK_RIGHT:
				game_snake1->changeDirection(Direction::RIGHT);
				break;
			}
			myContinue();
		}
	}
	

void myApp::myContinue() {
	//Calls methods to move snake, draw frame and check for collision
	if (!Paused) {
		incrementGameTimer();
		addPrize();
		game_snake1->moveSnake();
		game_window->drawFrame(game_snake1, current_prizes, score, myBackground);
		if (game_snake1->checkTailCollision()) {
			gameOver(game_window);
		}
		collectPoints();
	}
}

void myApp::addPrize() {
	//Adds a prize of random type to the prizes vector
	if (get_timer() == 30) {

		int type = 1 + (int)(2.0 * (rand() / (RAND_MAX + 1.0)));
		if (type == 1) {
			current_prizes->add_prize(new Ruby{ random_position(), random_position(), 30 });
			//current_prizes->push_back(std::make_unique<Ruby>(random_position(), random_position(),30)); 
		}
		else {
			current_prizes->add_prize(new Diamond{ random_position(), random_position(), 30 } );
		}
	}
}

void myApp::collectPoints() {
	
	if (current_prizes->get_prize_count() > 0) {
		
		int x = 0;
		auto temp = current_prizes->getchildren();
		for (auto& i:*temp){
			bool temp = game_snake1->checkPrizeCollision(i.data);
			std::cout << "Collision checked: " << x << std::endl;
				if (temp) {
					score->update_score(i.data->get_points());
					current_prizes->remove_prize(i.data);
					game_snake1->increaseSnakeSpeed();
					game_snake1->increaseLength();
					break;
				}
			}
		}
	}


void myApp::stopGame() {
	Running = false;
}

void myApp::gameOver(myWindow* window) {
	window->showGameOver();
	stopGame();
	SDL_Delay(3000);
	
	delete window;
	

}

const bool myApp::getStarted() {
	return started;
}

const bool myApp::getRunning() {
	return Running;
}

const std::shared_ptr<mySnake> myApp::getSnake() {
	return game_snake1;
}

const myWindow* myApp::getWindow() {
	return game_window;
}

const int myApp::get_timer() {
	return gameTimer;
}

void myApp::incrementGameTimer() {
	//increments between 0 - 49 then restarts
	gameTimer += 1;
	gameTimer = gameTimer % 50;
}

int myApp::random_position() {
	return 30 + (int)(420.0 * (rand() / (RAND_MAX + 30.0)));
}
