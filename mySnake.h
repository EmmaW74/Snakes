#ifndef MYSNAKE_H
#define MYSNAKE_H
#include "SDL.h"
#include "myDot.h"
#include "ImyPrize.h"
#include <SDL_image.h>
#include <vector>
#include<memory>
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
	std::vector<std::shared_ptr<myDot>> body; // Snake is a vector of smart pointers to dots - front of snake is back of vector
	Direction current_direction;
	int snakeLength;
	int snakeSpeed;

public:
	mySnake();

	void changeDirection(Direction new_direction);
	void increaseSnakeSpeed();
	void increaseLength();
	void moveSnake();
	bool checkTailCollision();
	bool checkPrizeCollision(std::shared_ptr<ImyPrize> prize);
		
	const Direction getDirection();
	const int getSnakeLength();
	const int getSnakeSpeed();
	const std::vector<std::shared_ptr<myDot>> getBody();

};

#endif
