#include "myDot.h"
#include <iostream>

myDot::myDot() {
	x = 0;
	y = 0;
	width = 1;
	height = 1;
	//std::cout << "Dot empty constructor" << std::endl;
}
myDot::myDot(int x, int y, int width, int height):
	x{ x }, y{ y }, width{ width }, height{ height } {
	//std::cout << "Dot constructor" << std::endl;
}

int myDot::get_width() {
	return width;
}
int myDot::get_height() {
	return height;
}
int myDot::get_x() {
	return x;
}
int myDot::get_y() {
	return y;
}

myDot::~myDot() {
	//std::cout << "Dot destructor" << std::endl;
};