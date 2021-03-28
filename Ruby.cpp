#include "Ruby.h"

Ruby::Ruby(){
	width = 27;
	height = 40;
	x = 100; // this needs to be random
	y = 100; // this needs to be random
	image = "Images/ruby.bmp";
	points = 50; // this could be random??
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
std::string Ruby::get_image() {
	return image;
}
int Ruby::get_points() {
	return points;
}
Ruby::~Ruby() {

}