#include "MyDot.h"
#include "myLinkedList.h"
#include <iostream>

MyDot::MyDot(int x, int y, int width, int height):
	x{ x }, y{ y }, width{ width }, height{ height } {
	colour_red = 0x02;
	colour_blue = 0x0b;
	colour_green = 0xf7;
	
	//std::cout << "MyDot constructor called" << std::endl;
}
/*
const int MyDot::get_width() {
	return width;
}
const int MyDot::get_height() {
	return height;
}
const int MyDot::get_x() {
	return x;
}
const int MyDot::get_y() {
	return y;
}
const uint8_t MyDot::get_colour_red() {
	return colour_red;
}
const uint8_t MyDot::get_colour_blue() {
	return colour_blue;
}
const uint8_t MyDot::get_colour_green() {
	return colour_green;
}

const const char* MyDot::get_image() {
	return image;
}
const std::string MyDot::get_font() {
	return font;
}
const std::string MyDot::get_colour_key() {
	return colour_key;
}
const std::shared_ptr<myLinkedList> MyDot::get_children() {
	return children;
}
*/

void MyDot::draw_element(SDL_Renderer* myRenderer) {
	SDL_Rect* temp = new SDL_Rect{ x,y,width,height };
	SDL_SetRenderDrawColor(myRenderer, colour_red, colour_green, colour_blue, 0xff);
	SDL_RenderFillRect(myRenderer, temp);
	delete temp;
}