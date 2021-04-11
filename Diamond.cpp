#include "Diamond.h"
#include <iostream>

Diamond::Diamond(int x, int y) :
	x{ x }, y{ y },width{ 30 }, height{ 30 }{
	image = "Images/diamond.bmp";
	points = 100;
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

//Diamond::~Diamond() {
//	std::cout << "Diamond destructor" << std::endl;
//}
