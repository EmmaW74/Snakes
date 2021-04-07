#ifndef MYPRIZE_H
#define MYPRIZE_H
#include <string>

class myPrize
{

public:
	virtual int get_width() = 0;
	virtual int get_height() = 0;
	virtual int get_x() = 0;
	virtual int get_y() = 0;
	virtual const char* get_image() = 0;
	virtual int get_points() = 0;
}; 

#endif