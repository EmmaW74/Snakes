#ifndef RUBY_H
#define RUBY_H
#include "myPrize.h"
class Ruby :
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
	Ruby(int x, int y);
	int get_width();
	int get_height();
	int get_x();
	int get_y();
	const char* get_image();
	int get_points();
	//~Ruby();
};

#endif