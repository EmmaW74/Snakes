#include "MyDot.h"
#include "myLinkedList.h"
#include <iostream>

MyDot::MyDot(int x, int y, int width, int height):
	x{ x }, y{ y }, width{ width }, height{ height } {
	colour_red = 0xff;
	colour_blue = 0x00;
	colour_green = 0x00;
}

int MyDot::get_width() const {
	return width;
}
int MyDot::get_height() const {
	return height;
}
int MyDot::get_x() const {
	return x;
}
int MyDot::get_y() const {
	return y;
}
uint8_t MyDot::get_colour_red() const {
	return colour_red;
}
uint8_t MyDot::get_colour_blue() const {
	return colour_blue;
}
uint8_t MyDot::get_colour_green() const {
	return colour_green;
}

void MyDot::draw_element(SDL_Renderer* myRenderer) {
	//Draw a square to renderer
	SDL_Rect* temp = new SDL_Rect{ x,y,width,height };
	SDL_SetRenderDrawColor(myRenderer, colour_red, colour_blue, colour_green, 0x00);
	SDL_RenderFillRect(myRenderer, temp);
	delete temp;
}

void MyDot::change_colour(uint8_t new_colour_red, uint8_t new_colour_green, uint8_t new_colour_blue) {
	colour_red = new_colour_red;
	colour_green = new_colour_green;
	colour_blue = new_colour_blue;
}

