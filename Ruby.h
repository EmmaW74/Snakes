#pragma once
#include "myPrize.h"
class Ruby :
    public myPrize
{
private:
	int width;
	int height;
	int x;
	int y;
	int points;
	std::string image;

public:
	Ruby();
	int get_width();
	int get_height();
	int get_x();
	int get_y();
	std::string get_image();
	int get_points();
	~Ruby();

};

