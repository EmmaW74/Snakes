#ifndef MYDOT_H
#define MYDOT_H
#include <string>
#include <stdint.h>
#include "RenderableColourBlock.h"
#include<memory>
#include<vector>


class MyDot: public RenderableColourBlock {

	//The snake body is made up of MyDot objects.
private:
	const int width;
	const int height;
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	

public:
	MyDot(int x, int y, int width, int height);
	void draw_element(SDL_Renderer* myRenderer);
	
	int get_width() const;
	int get_height() const;
	int get_x() const;
	int get_y() const;
	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	//const std::shared_ptr<myLinkedList> get_children();
	};

#endif
