#include "Ruby.h"
#include <iostream>

Ruby::Ruby(int x, int y):
	x{ x }, y{ y }, width{ 30 }, height{ 30 }{
	image = "Images/ruby.bmp";
	points = 50; 
}
const int Ruby::get_width() {
	return width;
}
const int Ruby::get_height() {
	return height;
}
const int Ruby::get_x() {
	return x;
}
const int Ruby::get_y() {
	return y;
}
const const char* Ruby::get_image() {
	return image;
}
const int Ruby::get_points() {
	return points;
}

//Ruby::~Ruby() {
//	std::cout << "Ruby destructor" << std::endl;
//}
