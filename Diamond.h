#ifndef DIAMOND_H
#define DIAMOND_H
#include "myPrize.h"
class Diamond :
    public myPrize
{
private:
	const int width;
	const int height;
	int x;
	int y;
	int points;
	const char* image;

public:
	
	Diamond(int x, int y);
	int get_width();
	int get_height();
	int get_x();
	int get_y();
	const char* get_image();
	int get_points();
};

#endif