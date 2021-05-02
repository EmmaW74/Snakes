#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableText :
    public IRenderable
{
private:
	const int width;
	const int height;
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	std::string font;

public:
	virtual const int get_x() = 0;
	virtual const int get_y() = 0;
	virtual const int get_width() = 0;
	virtual const int get_height() = 0;
	virtual const std::string get_font() = 0;

	virtual const std::string get_colour_key() = 0;
	virtual const uint8_t get_colour_red() = 0;
	virtual const uint8_t get_colour_blue() = 0;
	virtual const uint8_t get_colour_green() = 0;

	void draw_element(SDL_Renderer* myRenderer);

};

