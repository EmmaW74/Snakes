#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableColourBlock :
    public IRenderable
{
	// Stores details of a colour block object and draws on screen
private:
	
	int width;
	int height;
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	

public:
	RenderableColourBlock();
	RenderableColourBlock(int width, int height, int x, int y, uint8_t red, uint8_t blue, uint8_t green);
	int get_x() const;
	int get_y() const;
	int get_width() const;
	int get_height() const;

	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	//virtual std::shared_ptr<myLinkedList<IRenderable>> get_children() const = 0;
	
	void draw_element(SDL_Renderer* myRenderer);

	
};

