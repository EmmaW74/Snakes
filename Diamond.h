#ifndef DIAMOND_H
#define DIAMOND_H
#include "ImyPrize.h"
class Diamond :
    public ImyPrize
{
	//Prize type diamond
private:
	const int width;
	const int height;
	int x;
	int y;
	int points;
	const char* image;

public:
	
	Diamond(int x, int y);
	const int get_width();
	const int get_height();
	const int get_x();
	const int get_y();
	const const char* get_image();
	const int get_points();
	//~Diamond();
};

#endif