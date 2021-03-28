#ifndef MYSNAKE_H
#define MYSNAKE_H
#include "SDL.h"
#include "myDot.h"
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
private:
	std::vector<std::shared_ptr<myDot>> body; // Snake is a vector of smart pointers to dots - front of snake is back of vector
	Direction current_direction;
	int snakeLength;

public:
	mySnake();
	Direction getDirection();
	void changeDirection(Direction new_direction);
	int getSnakeLength();
	void increaseLength();
	void moveSnake();
	bool checkTailCollision();
	std::vector<std::shared_ptr<myDot>> getBody();
	~mySnake();
};

#endif
