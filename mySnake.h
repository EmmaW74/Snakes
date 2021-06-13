#ifndef MYSNAKE_H
#define MYSNAKE_H
#include "SDL.h"
#include "MyDot.h"
#include "ImyPrize.h"
#include "myLinkedList.h"
#include <SDL_image.h>
#include<memory>
#include "dimensions.h"

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class mySnake
{
	//Represents the snake and manages its movement
private:
	std::shared_ptr<Dimensions> dimensions;
	std::shared_ptr<myLinkedList<MyDot>> children;
	Direction current_direction;
	int snakeLength;
	int snakeSpeed;
	bool border_collide;

public:
	mySnake(std::shared_ptr<Dimensions> dimensions);

	//methods to manage snake properties and movement
	void set_start();
	void changeDirection(Direction new_direction);
	void increaseSnakeSpeed();
	void increaseLength();
	void moveSnake();
	bool checkTailCollision();
	bool checkPrizeCollision(ImyPrize* &prize);
	bool checkPrizeOverlap(ImyPrize*& prize);
	void changeSnakeColour(uint8_t colour_red, uint8_t colour_green, uint8_t colour_blue);
	void draw_element(SDL_Renderer* myRenderer);
	void setBorderCollide();
		
	// get methods
	bool getBorderCollide()const;
	Direction getDirection() const;
	int getSnakeLength() const;
	int getSnakeSpeed() const;
	std::shared_ptr<myLinkedList<MyDot>> getchildren() const;
};

#endif
