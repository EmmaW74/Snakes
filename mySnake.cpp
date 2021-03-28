#include "mySnake.h"
#include "myWindow.h"
#include <iostream>
#include <stdlib.h>

mySnake::mySnake() {
	//Update this to get random starting points and directions
	srand(time(NULL));
	snakeLength = 16; // needs to be held somewhere else
	int x = -160; // needs to be held somewhere else
	int y = rand() % 300 + 50;
	for (int i = 0; i < snakeLength; i++) {

		body.push_back(std::make_unique<myDot>(x, y, 10, 10));
		x += 10;
	}
	current_direction = Direction::RIGHT;
	
}
Direction mySnake::getDirection() {
	return current_direction;
}

bool mySnake::checkTailCollision() {
	int head_x;
	int head_y;
	int tail_x;
	int tail_y;
	for (unsigned int x = 0; x < body.size()-1; x++) {
		head_x = body.at(body.size() - 1)->get_x();
		head_y = body.at(body.size() - 1)->get_y();
		tail_x = body.at(x)->get_x();
		tail_y = body.at(x)->get_y();
		
		if ((head_x == tail_x)&&(head_y==tail_y)) {
			return true;
			std::cout << "Collision" << std::endl;
		}
	}
	
	return false;
}


std::vector<std::shared_ptr<myDot>> mySnake::getBody() {
	return body;
}
void mySnake::changeDirection(Direction new_direction) {
	current_direction = new_direction;
	moveSnake();
}


int mySnake::getSnakeLength() {
	return snakeLength;
}

void mySnake::moveSnake() {
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	std::cout << "Move snake" << std::endl;
	//front of snake is back of vector
	int x = body.at(snakeLength-1)->get_x();
	int y = body.at(snakeLength-1)->get_y();
	if (current_direction == Direction::UP) {
		y -= 10;
		//Check if goes off screen and wrap around
		if (y < 0) {
			y = SCREEN_HEIGHT - body.at(snakeLength - 1)->get_height();
		}
	}
	else if (current_direction == Direction::DOWN) {
		y += 10;
		//Check if goes off screen and wrap around
		if (y > (SCREEN_HEIGHT - body.at(snakeLength - 1)->get_height())) {
			y = 0;
		}
	}
	else if (current_direction == Direction::LEFT) {
		x -= 10;
		//Check if goes off screen and wrap around
		if (x < 0) {
			x = SCREEN_WIDTH - body.at(snakeLength - 1)->get_width();
		}
	}
	else if (current_direction == Direction::RIGHT) {
		x += 10;
		//Check if goes off screen and wrap around
		if (x > SCREEN_WIDTH - body.at(snakeLength - 1)->get_width()) {
			x = 0;
		}
	}
	body.push_back(std::make_unique<myDot>(x, y, 10, 10));
	body.erase(body.begin());
	
}
void mySnake::increaseLength() {
	// take direction and use it to calculate next position then push back to new pos
}

mySnake::~mySnake(){}