#include "RenderableColourBlock.h"
#include "SDL.h"
#include "myLinkedList.h"

//class MyDot;

RenderableColourBlock::RenderableColourBlock() {};

RenderableColourBlock::RenderableColourBlock(int width, int height, int x, int y, uint8_t red, uint8_t blue, uint8_t green):
	width{ width }, height{ height }, x{ x }, y{ y }, colour_red{ red }, colour_blue{ blue }, colour_green{ green }{};

int RenderableColourBlock::get_width() const {
	return width;
}
int RenderableColourBlock::get_height() const {
	return height;
}
int RenderableColourBlock::get_x() const {
	return x;
}
int RenderableColourBlock::get_y() const {
	return y;
}
uint8_t RenderableColourBlock::get_colour_red() const {
	return colour_red;
}
uint8_t RenderableColourBlock::get_colour_blue() const {
	return colour_blue;
}
 uint8_t RenderableColourBlock::get_colour_green() const {
	return colour_green;
}

void RenderableColourBlock::draw_element(SDL_Renderer* myRenderer) {
	SDL_Rect* temp = new SDL_Rect{ x,y,width,height };
	SDL_SetRenderDrawColor(myRenderer, colour_red, colour_blue, colour_green, 0xff);
	SDL_RenderFillRect(myRenderer, temp);
	delete temp;
}