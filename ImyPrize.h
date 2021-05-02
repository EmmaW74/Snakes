#ifndef IMYPRIZE_H
#define IMYPRIZE_H
#include "IRenderable.h"
#include <string>

class ImyPrize:
	public IRenderable
{
// Interface class - individual prize types are derived from this
public:
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual const char* get_image() const = 0;
	virtual int get_width() const = 0;
	virtual int get_height() const = 0;
	virtual int get_points() const = 0;
	virtual ~ImyPrize() {}
}; 

#endif