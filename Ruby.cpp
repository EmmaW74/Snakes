#include "Ruby.h"
#include <iostream>

Ruby::Ruby(int x, int y, int width_height):
	x{ x }, y{ y }, width{ width_height }, height{ width_height }{
	image = "Images/ruby.bmp";
	points = 50; 
	font = "";
	colour_key = "";
	colour_blue = NULL;
	colour_green = NULL;
	colour_red = NULL;
	
}
int Ruby::get_width() const {
	return width;
}
int Ruby::get_height() const {
	return height;
}
int Ruby::get_x() const {
	return x;
}
int Ruby::get_y() const {
	return y;
}
const char* Ruby::get_image() const {
	return image;
}
int Ruby::get_points() const {
	return points;
}

std::string Ruby::get_font() const {
	return font;
}
std::string Ruby::get_colour_key() const {
	return colour_key;
}
uint8_t Ruby::get_colour_red() const {
	return colour_red;
}
uint8_t Ruby::get_colour_blue() const {
	return colour_blue;
}
uint8_t Ruby::get_colour_green() const {
	return colour_green;
}

//Ruby::~Ruby() {
//	std::cout << "Ruby destructor" << std::endl;
//}
