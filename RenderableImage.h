#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableImage :
    public IRenderable
{

private:
	const char* image;
	
public:
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual int get_width() const = 0;
	virtual int get_height() const = 0;
	//virtual std::shared_ptr<myLinkedList<IRenderable>> get_children() const = 0; // should this be elsewhere??

	virtual const char* get_image() const = 0;
	virtual std::string get_colour_key() const = 0;

	virtual void draw_element(SDL_Renderer* myRenderer) = 0;

};

