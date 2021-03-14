#pragma once
#include <string>
class myDot
{
private:
	int width;
	int height;
	int x;
	int y;
	// std::string red;
	// std::string blue;
	// std::string green;

public:
	myDot();
	myDot(int x, int y, int width, int height);
	int get_width();
	int get_height();
	int get_x();
	int get_y();
	// std::string get_red();
	// std::string get_blue();
	// std::string get_green();
	~myDot();
};

