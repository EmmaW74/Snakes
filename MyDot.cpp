#include "myDot.h"
#include <iostream>

myDot::myDot(int x, int y, int width, int height):
	x{ x }, y{ y }, width{ width }, height{ height } {
	//std::cout << "myDot constructor called" << std::endl;
}
const int myDot::get_width() {
	return width;
}
const int myDot::get_height() {
	return height;
}
const int myDot::get_x() {
	return x;
}
const int myDot::get_y() {
	return y;
}

