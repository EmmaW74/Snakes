#include "Diamond.h"
#include <iostream>

Diamond::Diamond(int x, int y) :
	x{ x }, y{ y },width{ 30 }, height{ 30 }{
	image = "Images/diamond.bmp";
	points = 100;
}
int Diamond::get_width() {
	return width;
}
int Diamond::get_height() {
	return height;
}
int Diamond::get_x() {
	return x;
}
int Diamond::get_y() {
	return y;
}
const char* Diamond::get_image() {
	return image;
}
int Diamond::get_points() {
	return points;
}
