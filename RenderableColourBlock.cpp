#include "RenderableColourBlock.h"
#include "SDL.h"
#include "myLinkedList.h"

//class MyDot;

RenderableColourBlock::RenderableColourBlock() {};
/*
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

std::shared_ptr<myLinkedList<IRenderable>> RenderableColourBlock::get_children() const {
	return children;
}

void RenderableColourBlock::draw_element(SDL_Renderer* myRenderer) {
	SDL_Rect* temp = new SDL_Rect{ x,y,width,height };
	SDL_SetRenderDrawColor(myRenderer, colour_red, colour_green, colour_blue, 0xff);
	SDL_RenderFillRect(myRenderer, temp);
	delete temp;
}*/