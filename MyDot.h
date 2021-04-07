#ifndef MYDOT_H
#define MYDOT_H

class myDot
{
private:
	const int width;
	const int height;
	int x;
	int y;

public:
	myDot(int x, int y, int width, int height);
	int get_width();
	int get_height();
	int get_x();
	int get_y();
	
};

#endif
