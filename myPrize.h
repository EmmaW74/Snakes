#pragma once
#include <string>

class myPrize
{

public:
	virtual int get_width() = 0;
	virtual int get_height() = 0;
	virtual int get_x() = 0;
	virtual int get_y() = 0;
	virtual std::string get_image() = 0;
	virtual int get_points() = 0;
}; 

