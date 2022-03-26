#ifndef MYDOT_H
#define MYDOT_H
#include <string>
#include <stdint.h>
#include "RenderableColourBlock.h"
#include<memory>
#include<vector>

//The snake body is made up of MyDot objects. **THIS MAY NOT BE NEEDED - DOESN'T ADD ANYTHING TO RENDERABLECOLOURBLOCK**
class MyDot: public RenderableColourBlock {

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
	void change_colour(uint8_t new_colour_red, uint8_t new_colour_green, uint8_t new_colour_blue);

	};

#endif
