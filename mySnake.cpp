#include "mySnake.h"
#include "myWindow.h"
#include "myPrize.h"
#include <iostream>
#include <stdlib.h>

mySnake::mySnake() {
	//Update this to get random starting points and directions
	//srand(time(NULL));
	snakeLength = 20; // needs to be held somewhere else
	snakeSpeed = 150; //needs to be held somewhere else
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
	int head_x = body.at(body.size() - 1)->get_x();
	int head_y = body.at(body.size() - 1)->get_y();
	int tail_x;
	int tail_y;
	if ((head_x <= 0 || head_x >= 630) || (head_y <= 50 || head_y >=470)) {
		return true;
	}
	
	for (unsigned int x = 0; x < body.size()-1; x++) {
		//head_x = body.at(body.size() - 1)->get_x();
		//head_y = body.at(body.size() - 1)->get_y();
		tail_x = body.at(x)->get_x();
		tail_y = body.at(x)->get_y();
		
		if ((head_x == tail_x)&&(head_y==tail_y)) {
			return true;
			std::cout << "Collision" << std::endl;
		}
	}
	
	return false;
}

bool mySnake::checkPrizeCollision(myPrize* prize) {

	int head_x = body.at(body.size() - 1)->get_x();
	int head_y = body.at(body.size() - 1)->get_y();
	int prize_x_min = prize->get_x()-5;
	int prize_y_min = prize->get_y()-5;
	int prize_x_max = (prize->get_x())+(prize->get_width()+5);
	int prize_y_max = (prize->get_y())+(prize->get_height()+5);
	bool x_collision = false;
	bool y_collision = false;

	if ((head_x >= prize_x_min) && (head_x <= prize_x_max)) {
		x_collision = true;
	}

	if ((head_y >= prize_y_min) && (head_y <= prize_y_max)) {
		y_collision = true;
	}
	if (x_collision && y_collision) {
		return true;
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

int mySnake::getSnakeSpeed() {
	return snakeSpeed;
}

void mySnake::increaseSnakeSpeed() {
	//Reducing snakeSpeed reduces frame delay
	if (getSnakeSpeed() > 50) {
		snakeSpeed -= 10;
	}
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
		/*//Check if goes off screen and wrap around
		if (y < 0) {
			y = SCREEN_HEIGHT - body.at(snakeLength - 1)->get_height();
		} */
	}
	else if (current_direction == Direction::DOWN) {
		y += 10;
		/*//Check if goes off screen and wrap around
		if (y > (SCREEN_HEIGHT - body.at(snakeLength - 1)->get_height())) {
			y = 0;
		}*/
	}
	else if (current_direction == Direction::LEFT) {
		x -= 10;
		/*//Check if goes off screen and wrap around
		if (x < 0) {
			x = SCREEN_WIDTH - body.at(snakeLength - 1)->get_width();
		} */
	}
	else if (current_direction == Direction::RIGHT) {
		x += 10;
		/*//Check if goes off screen and wrap around
		if (x > SCREEN_WIDTH - body.at(snakeLength - 1)->get_width()) {
			x = 0;
		} */
	}
	body.push_back(std::make_unique<myDot>(x, y, 15, 15));
	body.erase(body.begin());
	
}
void mySnake::increaseLength() {
	// take direction and use it to calculate next position then push back to new pos
	//body.push_back(std::make_unique<myDot>(x, y, 10, 10);
	snakeLength++;
	int front_x = body.at(body.size() - 1)->get_x();
	int front_y = body.at(body.size() - 1)->get_y();
	int width_height = body.at(body.size() - 1)->get_width();

	if (getDirection() == Direction::UP) {
		int new_y = front_y - 10;
		body.push_back(std::make_unique<myDot>(front_x, new_y, 10, 10));
	}
	else if (getDirection() == Direction::DOWN) {
		int new_y = front_y + 10;
		body.push_back(std::make_unique<myDot>(front_x, new_y, 10, 10));
	}
	else if (getDirection() == Direction::LEFT) {
		int new_x = front_x - 10;
		body.push_back(std::make_unique<myDot>(new_x, front_y, 10, 10));
	}
	else if (getDirection() == Direction::RIGHT) {
		int new_x = front_x + 10;
		body.push_back(std::make_unique<myDot>(new_x, front_y, 10, 10));
	}
}

mySnake::~mySnake(){}