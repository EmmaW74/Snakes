#include "Diamond.h"
#include <iostream>

Diamond::Diamond(int x, int y, int width_height) :
	x{ x }, y{ y }, width{ width_height }, height{ width_height }{
	image = "Images/diamond.bmp";
	points = 100;
	font = "";
	colour_key = "";
	children = NULL;
	colour_blue = NULL;
	colour_green = NULL;
	colour_red = NULL;
}
const int Diamond::get_width() {
	return width;
}
const int Diamond::get_height() {
	return height;
}
const int Diamond::get_x() {
	return x;
}
const int Diamond::get_y() {
	return y;
}
const const char* Diamond::get_image() {
	return image;
}
const int Diamond::get_points() {
	return points;
}

const std::string Diamond::get_font() {
	return font;
}
const std::string Diamond::get_colour_key() {
return colour_key;
}
const uint8_t Diamond::get_colour_red() {
	return colour_red;
}
const uint8_t Diamond::get_colour_blue() {
	return colour_blue;
}
const uint8_t Diamond::get_colour_green() {
return colour_green; 
}

const std::shared_ptr<myLinkedList> Diamond::get_children() {
	return children;
}

//Diamond::~Diamond() {
//	std::cout << "Diamond destructor" << std::endl;
//}
