#include "Ruby.h"
#include <iostream>

Ruby::Ruby(int x, int y, int width_height):
	x{ x }, y{ y }, width{ width_height }, height{ width_height }{
	image = "Images/ruby.bmp";
	points = 50; 
	font = "";
	colour_key = "";
	children = NULL;
	colour_blue = NULL;
	colour_green = NULL;
	colour_red = NULL;
	
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

const std::string Ruby::get_font() {
	return font;
}
const std::string Ruby::get_colour_key() {
	return colour_key;
}
const uint8_t Ruby::get_colour_red() {
	return colour_red;
}
const uint8_t Ruby::get_colour_blue() {
	return colour_blue;
}
const uint8_t Ruby::get_colour_green() {
	return colour_green;
}

const std::shared_ptr<myLinkedList> Ruby::get_children(){
	return children;
}
//Ruby::~Ruby() {
//	std::cout << "Ruby destructor" << std::endl;
//}
