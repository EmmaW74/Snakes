#ifndef IMYPRIZE_H
#define IMYPRIZE_H
#include "RenderableImage.h"
#include <string>

class ImyPrize:
	public RenderableImage
{
// Interface class - individual prize types are derived from this
public:
	ImyPrize() {};
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual const char* get_image() const = 0;
	virtual int get_width() const = 0;
	virtual int get_height() const = 0;
	virtual int get_points() const = 0;
	virtual std::string get_colour_key() const = 0;
	virtual void draw_element(SDL_Renderer* myRenderer) = 0;
	virtual ~ImyPrize() {}
}; 

#endif