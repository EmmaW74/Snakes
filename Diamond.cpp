#include "Diamond.h"
#include <iostream>

Diamond::Diamond(int x, int y, int width_height) :
	x{ x }, y{ y }, width{ width_height }, height{ width_height }{
	image = "Images/diamond.bmp";
	points = 100;
	font = "";
	colour_key = "";
	
	colour_blue = NULL;
	colour_green = NULL;
	colour_red = NULL;
}
int Diamond::get_width() const {
	return width;
}
int Diamond::get_height() const {
	return height;
}
int Diamond::get_x() const {
	return x;
}
int Diamond::get_y() const {
	return y;
}
const char* Diamond::get_image() const {
	return image;
}
int Diamond::get_points() const {
	return points;
}

std::string Diamond::get_font() const {
	return font;
}
std::string Diamond::get_colour_key() const {
return colour_key;
}
uint8_t Diamond::get_colour_red() const {
	return colour_red;
}
uint8_t Diamond::get_colour_blue() const {
	return colour_blue;
}
uint8_t Diamond::get_colour_green() const {
return colour_green; 
}



//Diamond::~Diamond() {
//	std::cout << "Diamond destructor" << std::endl;
//}
