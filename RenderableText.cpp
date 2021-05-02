#include "RenderableText.h"

const int RenderableText::get_width() {
	return width;
}
const int RenderableText::get_height() {
	return height;
}
const int RenderableText::get_x() {
	return x;
}
const int RenderableText::get_y() {
	return y;
}
const uint8_t RenderableText::get_colour_red() {
	return colour_red;
}
const uint8_t RenderableText::get_colour_blue() {
	return colour_blue;
}
const uint8_t RenderableText::get_colour_green() {
	return colour_green;
}
const std::string RenderableText::get_font() {
	return font;
}

void RenderableText::draw_element(SDL_Renderer* myRenderer) {
	// code to add text
}