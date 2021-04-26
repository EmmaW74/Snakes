#ifndef IMYPRIZE_H
#define IMYPRIZE_H
#include "IRenderable.h"
#include <string>

class ImyPrize:
	public IRenderable
{
// Interface class - individual prize types are derived from this
public:
	virtual const int get_x() = 0;
	virtual const int get_y() = 0;
	virtual const const char* get_image() = 0;
	virtual const int get_width() = 0;
	virtual const int get_height() = 0;
	virtual const int get_points() = 0;
	virtual ~ImyPrize() {}
}; 

#endif