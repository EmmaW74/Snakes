#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableImage :
    public IRenderable
{

private:
	const char* image;
	
public:
	virtual const int get_x() = 0;
	virtual const int get_y() = 0;
	virtual const int get_width() = 0;
	virtual const int get_height() = 0;
	virtual const std::shared_ptr<myLinkedList<IRenderable>> get_children() = 0; // should this be elsewhere??

	virtual const const char* get_image() = 0;
	virtual const std::string get_colour_key() = 0;

	void draw_element(SDL_Renderer* myRenderer);

};

