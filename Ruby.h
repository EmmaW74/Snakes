#ifndef RUBY_H
#define RUBY_H
#include "ImyPrize.h"
class Ruby :
    public ImyPrize
{
	//Prize type ruby
private:
	const int width;
	const int height;
	int x;
	int y;
	int points;
	const char* image;

public:
	Ruby(int x, int y);
	const int get_width();
	const int get_height();
	const int get_x();
	const int get_y();
	const const char* get_image();
	const int get_points();
	//~Ruby();
};

#endif