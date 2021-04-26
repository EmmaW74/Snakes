#ifndef MYDOT_H
#define MYDOT_H
#include "IRenderable.h"
#include <string>
#include <stdint.h>
#include<memory>
class myLinkedList;
class MyDot: public IRenderable {

	//The snake body is made up of MyDot objects.
private:
	const int width;
	const int height;
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	const char* image;
	std::string font;
	std::string colour_key;
	std::shared_ptr<myLinkedList> children;

public:
	MyDot(int x, int y, int width, int height);
	const int get_width();
	const int get_height();
	const int get_x();
	const int get_y();
	const uint8_t get_colour_red();
	const uint8_t get_colour_blue();
	const uint8_t get_colour_green();

	const const char* get_image();
	const std::string get_font();
	const std::string get_colour_key();
	const std::shared_ptr<myLinkedList> get_children();
	};

#endif
