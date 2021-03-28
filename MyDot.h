#ifndef MYDOT_H
#define MYDOT_H
#include <string>
class myDot
{
private:
	int width;
	int height;
	int x;
	int y;

public:
	//myDot();
	myDot(int x, int y, int width, int height);
	int get_width();
	int get_height();
	int get_x();
	int get_y();
	~myDot();
};

#endif
