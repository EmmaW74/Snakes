#include "mySnake.h"
#include "myWindow.h"
#include "ImyPrize.h"
#include "IRenderable.h"
#include "myLinkedList.h"
#include "myApp.h"
#include "MyDot.h"
#include <time.h>
#include <iostream>
#include "SDL.h"

template<class T>
struct node;

mySnake::mySnake() {
	srand(time(NULL));
	snakeLength = 20;
	snakeSpeed = 150;
	int x = 0;
	int y = rand() % 300 + 50;
	children = std::make_shared<myLinkedList<MyDot>>(new MyDot{ x, y, 10, 10 });
	
	x -= 10;
	for (int i = 0; i < snakeLength; i++) {
		
		children->add_node_tail(new MyDot{ x, y, 10, 10 });
		x -= 10;
	}
	current_direction = Direction::RIGHT;
}

void mySnake::changeDirection(Direction new_direction) {
	current_direction = new_direction;
	//moveSnake();
}

void mySnake::increaseSnakeSpeed() {
	//Reducing snakeSpeed reduces frame delay
	if (getSnakeSpeed() > 50) {
		snakeSpeed -= 10;
	}
}

void mySnake::increaseLength() {

	snakeLength++;
	int tail_x = children->get_tail()->data->get_x();
	int tail_y = children->get_tail()->data->get_y();
	int width_height = children->get_tail()->data->get_width();

	if (getDirection() == Direction::UP) {
		int new_y = tail_y + 10;
		children->add_node_tail(new MyDot(tail_x, new_y, 10, 10));
	}
	else if (getDirection() == Direction::DOWN) {
		int new_y = tail_y - 10;
		children->add_node_tail(new MyDot(tail_x, new_y, 10, 10));
	}
	else if (getDirection() == Direction::LEFT) {
		int new_x = tail_y + 10;
		children->add_node_tail(new MyDot(new_x, tail_y, 10, 10));
	}
	else if (getDirection() == Direction::RIGHT) {
		int new_x = tail_y - 10;
		children->add_node_tail(new MyDot(new_x, tail_y, 10, 10));
	}
}

void mySnake::moveSnake() {
	
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	int x = children->get_head()->data->get_x();
	int y = children->get_head()->data->get_y();
	if (current_direction == Direction::UP) {
		y -= 10;

	}
	else if (current_direction == Direction::DOWN) {
		y += 10;

	}
	else if (current_direction == Direction::LEFT) {
		x -= 10;

	}
	else if (current_direction == Direction::RIGHT) {
		x += 10;

	}
	children->add_node_head(new MyDot(x, y, 15, 15));
	children->remove_node_tail();
}

bool mySnake::checkTailCollision() {
	//checks if head dot has collided with any other dot in snake body

	
	int head_x = children->get_head()->data->get_x();
	int head_y = children->get_head()->data->get_y();
	node<MyDot>* ptr = children->get_head()->next;
	int ptr_x;
	int ptr_y;

	
	if ((head_x <= -10 || head_x >= 640) || (head_y <= 40 || head_y >= 480)) {
		return true;
		
	}
	while (ptr->next != nullptr) {
		ptr_x = ptr->data->get_x();
		ptr_y = ptr->data->get_y();

		if ((head_x == ptr_x) && (head_y == ptr_y)) {
			return true;
			
		}
		ptr = ptr->next;
	}
	
	return false;
}

bool mySnake::checkPrizeCollision(std::shared_ptr<ImyPrize> prize) {

	int head_x = children->get_head()->data->get_x();
	int head_y = children->get_head()->data->get_y();
	int prize_x_min = prize->get_x() - 5;
	int prize_y_min = prize->get_y() - 5;
	int prize_x_max = (prize->get_x()) + (prize->get_width() + 5);
	int prize_y_max = (prize->get_y()) + (prize->get_height() + 5);
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

Direction mySnake::getDirection() const {
	return current_direction;
}

int mySnake::getSnakeLength() const {
	return snakeLength;
}

int mySnake::getSnakeSpeed()  const {
	return snakeSpeed;
}

std::shared_ptr<myLinkedList<MyDot>> mySnake::getchildren() const {
	return children;
}

void mySnake::draw_element(SDL_Renderer* myRenderer) {
	node<MyDot>* temp = children->get_head();
	while (temp != NULL) {
		temp->data->draw_element(myRenderer);
		temp = temp->next;
	} 
}