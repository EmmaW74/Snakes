#include "myApp.h"
#include "myWindow.h"
#include "mySnake.h"
#include "Ruby.h"
#include "Diamond.h"
#include <iostream>
#include "dimensions.h"


myApp::myApp(){
	
	measurements = std::make_shared<Dimensions>(15,45,20,150);
	intro = std::make_shared<introController>(new introController(true));
	myBackground = std::make_shared<RenderableImage>(0, 0, "Images/grass.jpg");
	game_window = new myWindow(measurements, intro,myBackground);
	game_snake1 = std::make_shared<mySnake> (measurements);
	current_prizes = std::make_shared<myPrizePot>();
	Running = true;
	Paused = false;
	started = false;
	gameTimer = 0;
	srand(time(NULL));
	score = std::make_shared<Score_controller>(5, 5, 0xff, 0xff, 0xff);
	game_over_control = std::make_shared<myGameOver>(game_window,game_snake1,measurements,myBackground,score);
	
	
}

void myApp::updateStarted() {
	started = !started;
}

void myApp::runGame() {
	SDL_Event e;
	while (!getStarted()) {
		//ADD HERE CODE TO SELECT COLLIDE OPTION


		//Wait for Enter to start the game
		if (SDL_PollEvent(&e) != 0 && e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_b) {
				intro->update_border_choice();
				game_snake1->setBorderCollide();
				intro->draw_element(game_window->get_myRenderer(),myBackground);
				game_window->publishTexture();
			}

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
			gameOver();
		}
		collectPoints();
	}
}

void myApp::addPrize() {
	//Adds a prize of random type to the prizes vector
	if (get_timer() == 30) {
		bool position_check = true;
		ImyPrize* temp;
		do {
			int type = 1 + (int)(2.0 * (rand() / (RAND_MAX + 1.0)));
			if (type == 1) {
				temp = new Ruby{ random_position(), random_position(), 30 };
				position_check = game_snake1->checkPrizeOverlap(temp); 
				if (!position_check) {
					current_prizes->add_prize(temp);
				}
			}
			else {
				temp = new Diamond{ random_position(), random_position(), 30 };
				position_check = game_snake1->checkPrizeOverlap(temp); 
				if (!position_check) {
					current_prizes->add_prize(temp);
				}
			}
		} while (position_check);
		
	}
}

void myApp::collectPoints() {
	
	if (current_prizes->get_prize_count() > 0) {
		
		int x = 0;
		auto temp = current_prizes->getchildren();
		for (auto& i:*temp){
			bool temp = game_snake1->checkPrizeCollision(i.data);
			//std::cout << "Collision checked: " << x << std::endl;
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

void myApp::gameOver() {
	//window->showGameOver(snake, myBackground);
	//score->enter_high_score_name(myRenderer);
	game_over_control->run_game_over();
	stopGame();
	SDL_Delay(3000);
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
	return 30 + (rand() % (measurements->get_screen_height()-measurements->get_banner_height()-30) / measurements->get_cell_size()) * measurements->get_cell_size();
	
}
