#include "myDot.h"
#include <iostream>

myDot::myDot(int x, int y, int width, int height):
	x{ x }, y{ y }, width{ width }, height{ height } {
	//std::cout << "myDot constructor called" << std::endl;
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
	//std::cout << "myDot destructor called" << std::endl;
};