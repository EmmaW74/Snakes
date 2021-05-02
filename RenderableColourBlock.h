#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableColourBlock :
    public IRenderable
{
private:
	int width;
	int height;
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	std::shared_ptr<myLinkedList<IRenderable>> children;

public:
	RenderableColourBlock();
	virtual int get_x() const;
	virtual int get_y() const;
	virtual int get_width() const;
	virtual int get_height() const;

	virtual uint8_t get_colour_red() const;
	virtual uint8_t get_colour_blue() const;
	virtual uint8_t get_colour_green() const;
	virtual std::shared_ptr<myLinkedList<IRenderable>> get_children() const;
	
	virtual void draw_element(SDL_Renderer* myRenderer) = 0;

	
};

