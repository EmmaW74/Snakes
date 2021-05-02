#ifndef IRENDERABLE_H
#define IRENDERABLE_H
#include "myLinkedList.h"
#include<string>
#include<memory>
#include<vector>
class IRenderable
{
	//Interface class for rendering to window
	int x;
	int y;
	int width;
	int height;


public:
	
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual int get_width() const = 0;
	virtual int get_height() const = 0;

	/*
	virtual const const char* get_image() = 0;
	virtual const std::string get_font() = 0;
	virtual const std::string get_colour_key() = 0;
	virtual const uint8_t get_colour_red() = 0;
	virtual const uint8_t get_colour_blue() = 0;
	virtual const uint8_t get_colour_green() = 0;
	virtual const std::shared_ptr<myLinkedList> get_children() = 0;
	virtual ~IRenderable() {};
	*/
};

#endif