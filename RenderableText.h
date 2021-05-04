#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableText :
    public IRenderable
{
private:
	//const int width;
	//const int height;
	//int x;
	//int y;
	//uint8_t colour_red;
	//uint8_t colour_blue;
	//uint8_t colour_green;
	std::string font;

public:
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual int get_width() const = 0;
	virtual int get_height() const = 0;
	virtual std::string get_font() const = 0;

	virtual std::string get_colour_key() const = 0;
	virtual uint8_t get_colour_red() const = 0;
	virtual uint8_t get_colour_blue() const = 0;
	virtual uint8_t get_colour_green() const = 0;

	virtual void draw_element(SDL_Renderer* myRenderer);

};

