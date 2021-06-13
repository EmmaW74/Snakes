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
	game_window = new myWindow(measurements, intro,myBackground,measurements);
	game_snake1 = std::make_shared<mySnake> (measurements);
	current_prizes = std::make_shared<myPrizePot>();
	Running = true;
	Paused = false;
	started = false;
	gameTimer = 0;
	srand(time(NULL));
	score = std::make_shared<Score_controller>(measurements, 5, 5);
	game_over_control = std::make_shared<myGameOver>(game_window,game_snake1,measurements,myBackground,score);
		
}

void myApp::reset_game() {
	//Resets values ready to play game again and refreshes the game window
	game_snake1->set_start();
	current_prizes->reset_prize_pot();
	Running = true;
	Paused = false;
	started = false;
	gameTimer = 0;
	score->reset_score();
	score->update_text();  
	intro->draw_element(game_window->get_myRenderer(), myBackground);
	game_window->publishTexture();
	
}

void myApp::updateStarted() {
	started = !started;
}

void myApp::runGame() {
	//manages progress of the game
	SDL_Event e;
	int x;
	while (!getStarted()) {
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
		
		//While running, action event or, if no event, continue to move snake
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
	//Actins keyboard events
	if (e.type == SDL_QUIT)
		//User requests quit
	{
		stopGame();
	}
	else if (e.type == SDL_KEYDOWN)
		//user presses a key
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
		//removes collided prize from prize pot and updates score
		int x = 0;
		auto temp = current_prizes->getchildren();
		for (auto& i:*temp){
			bool temp = game_snake1->checkPrizeCollision(i.data);
			
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
	//Runs game over sequence, actions change based on user's play again choice
	game_over_control->run_game_over();

	if (game_over_control->play_again() == 1) {
		reset_game();
		runGame();
	}
	else {
		stopGame();
		score->write_high_scores_file();
		SDL_Delay(300);
	}	
}

bool myApp::getStarted() const {
	return started;
}

bool myApp::getRunning() const {
	return Running;
}

std::shared_ptr<mySnake> myApp::getSnake() const {
	return game_snake1;
}

myWindow* myApp::getWindow() const {
	return game_window;
}

int myApp::get_timer() const {
	return gameTimer;
}

void myApp::incrementGameTimer() {
	//increments between 0 - 49 then restarts
	gameTimer += 1;
	gameTimer = gameTimer % 50;
}

int myApp::random_position() const {
	//returns a random number for element positioning
	return 30 + (rand() % (measurements->get_screen_height()-measurements->get_banner_height()-30) / measurements->get_cell_size()) * measurements->get_cell_size();
	
}
