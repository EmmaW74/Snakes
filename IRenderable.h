#ifndef IRENDERABLE_H
#define IRENDERABLE_H
#include "myLinkedList.h"
#include<string>
#include<memory>
class IRenderable
{
	//Interface class for rendering to window

public:
	
	virtual const int get_x() = 0;
	virtual const int get_y() = 0;
	virtual const const char* get_image() = 0;
	virtual const int get_width() = 0;
	virtual const int get_height() = 0;
	virtual const std::string get_font() = 0;
	virtual const std::string get_colour_key() = 0;
	virtual const uint8_t get_colour_red() = 0;
	virtual const uint8_t get_colour_blue() = 0;
	virtual const uint8_t get_colour_green() = 0;
	virtual const std::shared_ptr<myLinkedList> get_children() = 0;
	virtual ~IRenderable() {};
};

#endif