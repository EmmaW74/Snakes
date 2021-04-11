#ifndef MYDOT_H
#define MYDOT_H

class myDot
{
	//The snake body is made up of myDot objects.
private:
	const int width;
	const int height;
	int x;
	int y;

public:
	myDot(int x, int y, int width, int height);
	const int get_width();
	const int get_height();
	const int get_x();
	const int get_y();
	};

#endif
