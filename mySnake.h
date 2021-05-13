#ifndef MYSNAKE_H
#define MYSNAKE_H
#include "SDL.h"
#include "MyDot.h"
#include "ImyPrize.h"
#include "myLinkedList.h"
#include <SDL_image.h>
#include <vector>
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
	std::shared_ptr<myLinkedList<MyDot>> children;
	Direction current_direction;
	int snakeLength;
	int snakeSpeed;
	

public:
	mySnake(std::shared_ptr<Dimensions> measurements);

	void changeDirection(Direction new_direction);
	void increaseSnakeSpeed();
	void increaseLength(std::shared_ptr<Dimensions> measurements);
	void moveSnake(std::shared_ptr<Dimensions> measurements);
	bool checkTailCollision(std::shared_ptr<Dimensions> measurements);
	bool checkPrizeCollision(ImyPrize* prize);
		
	Direction getDirection() const;
	int getSnakeLength() const;
	int getSnakeSpeed() const;
	std::shared_ptr<myLinkedList<MyDot>> getchildren() const;
	void draw_element(SDL_Renderer* myRenderer);
};

#endif
