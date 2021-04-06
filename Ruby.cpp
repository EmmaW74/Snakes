#include "Ruby.h"
#include <iostream>

Ruby::Ruby(int x, int y):
	x{ x }, y{ y }{
	width = 30;
	height = 30;
	image = "Images/ruby.bmp";
	points = 50; // this could be random??
	std::cout << "Ruby constructor called" << std::endl;
}
int Ruby::get_width() {
	return width;
}
int Ruby::get_height() {
	return height;
}
int Ruby::get_x() {
	return x;
}
int Ruby::get_y() {
	return y;
}
const char* Ruby::get_image() {
	return image;
}
int Ruby::get_points() {
	return points;
}
Ruby::~Ruby() {
	std::cout << "Ruby destructor called" << std::endl;
}