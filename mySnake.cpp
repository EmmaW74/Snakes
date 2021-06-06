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

mySnake::mySnake(std::shared_ptr<Dimensions> dimensions):
	dimensions{ dimensions }, border_collide(true) {
	srand(time(NULL));
	snakeLength = dimensions->get_length();
	snakeSpeed = dimensions->get_speed();
	int x = 0;
	int y = ((rand() % 300)/dimensions->get_cell_size())*dimensions->get_cell_size() + 50;
	children = std::make_shared<myLinkedList<MyDot>>(new MyDot{ x, y,dimensions->get_cell_size(), dimensions->get_cell_size() });
	
	
	for (int i = 0; i < snakeLength; i++) {
	
		children->add_node_tail(new MyDot{ x, y, dimensions->get_cell_size(), dimensions->get_cell_size() });
		x -= dimensions->get_cell_size();
	}
	current_direction = Direction::RIGHT;
}

void mySnake::changeDirection(Direction new_direction) {
//Changes snake direction provided it's not turning back the opposite way
		switch (new_direction) {
		case Direction::DOWN:
			if (current_direction == Direction::UP) {
				break;
			}
			else {
				current_direction = new_direction;
			}
		case Direction::UP:
			if (current_direction == Direction::DOWN) {
				break;
			}
			else {
				current_direction = new_direction;
			}

		case Direction::LEFT:
			if (current_direction == Direction::RIGHT) {
				break;
			}
			else {
				current_direction = new_direction;
			}
		case Direction::RIGHT:
			if (current_direction == Direction::LEFT) {
				break;
			}
			else {
				current_direction = new_direction;
			}
		}
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
		int new_y = tail_y + width_height;
		children->add_node_tail(new MyDot(tail_x, new_y, width_height, width_height));
	}
	else if (getDirection() == Direction::DOWN) {
		int new_y = tail_y - width_height;
		children->add_node_tail(new MyDot(tail_x, new_y, width_height, width_height));
	}
	else if (getDirection() == Direction::LEFT) {
		int new_x = tail_y + width_height;
		children->add_node_tail(new MyDot(new_x, tail_y, width_height, width_height));
	}
	else if (getDirection() == Direction::RIGHT) {
		int new_x = tail_y - width_height;
		children->add_node_tail(new MyDot(new_x, tail_y, width_height, width_height));
	}
}

void mySnake::moveSnake() {
	
	int x = children->get_head()->data->get_x();
	int y = children->get_head()->data->get_y();
	int cell_size = children->get_head()->data->get_height();
	
	if (border_collide == true) {
		if (current_direction == Direction::UP) {
			y -= cell_size;

		}
		else if (current_direction == Direction::DOWN) {
			y += cell_size;

		}
		else if (current_direction == Direction::LEFT) {
			x -= cell_size;

		}
		else if (current_direction == Direction::RIGHT) {
			x += cell_size;

		}
	}
	else {
		if (current_direction == Direction::UP) {
			y -= cell_size;
			if (y < dimensions->get_banner_height()) {
				y = (dimensions->get_screen_height() - dimensions->get_cell_size());
			}
		}
		else if (current_direction == Direction::DOWN) {
			y += cell_size;
			if (y > (dimensions->get_screen_height() - dimensions->get_cell_size())) {
				y = 0 + dimensions->get_banner_height();
			}
		}
		else if (current_direction == Direction::LEFT) {
			x -= cell_size;
			if (x < 0) {
				x = (dimensions->get_screen_width() - dimensions->get_cell_size());
			}
		}
		else if (current_direction == Direction::RIGHT) {
			x += cell_size;
			if (x > (dimensions->get_screen_width() - dimensions->get_cell_size())) {
				x = 0;
			}
		}
	}
	children->add_node_head(new MyDot(x, y,cell_size , cell_size));
	children->remove_node_tail();
}

bool mySnake::getBorderCollide()const{
	return border_collide;
}

void mySnake::setBorderCollide(){
	border_collide = !border_collide;
}
bool mySnake::checkPrizeOverlap(ImyPrize*& prize) { 
	//Checks if a prize overlaps any part of the snake body
	int prize_x = prize->get_x();
	int prize_y = prize->get_y();
	node<MyDot>* ptr = children->get_head()->next;
	int ptr_x;
	int ptr_y;

	while (ptr->next != nullptr) {
		ptr_x = ptr->data->get_x();
		ptr_y = ptr->data->get_y();

		if ((ptr_x >= prize_x - prize->get_width()) && (ptr_x <= prize_x + prize->get_width()) && (ptr_y >= prize_y - prize->get_height()) && (ptr_y <= prize_y + prize->get_height())) {
			//std::cout << "Prize Overlap" << std::endl;
			return true;
		}
		ptr = ptr->next;
	}
	//std::cout << "No prize Overlap" << std::endl;
	return false;
}
bool mySnake::checkTailCollision() {
	//checks if head dot has collided with any other dot in snake body	
	int cell_size = children->get_head()->data->get_height();
	int head_x = children->get_head()->data->get_x();
	int head_y = children->get_head()->data->get_y();
	node<MyDot>* ptr = children->get_head()->next;
	int ptr_x;
	int ptr_y;

	if (border_collide == true) {
		if ((head_x <= (0 - cell_size) || head_x >= dimensions->get_screen_width()) || (head_y <= (dimensions->get_banner_height()) || head_y >= dimensions->get_screen_height())) {
			return true;
		}
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

//bool mySnake::checkPrizeCollision(ImyPrize* const& prize) {
bool mySnake::checkPrizeCollision(ImyPrize* &prize) {
	
	if (prize == nullptr) {
		return false;
	}
	else {

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

void mySnake::changeSnakeColour(uint8_t colour_red, uint8_t colour_green, uint8_t colour_blue) {
	for (auto& i : *children) {
		i.data->change_colour(colour_red, colour_green, colour_blue);
	}
}