#ifndef DIAMOND_H
#define DIAMOND_H
#include "ImyPrize.h"

class Diamond :
	public ImyPrize
{
	//Stores details of Diamond prize object and draws to screen
private:
	const int width;
	const int height;
	int x;
	int y;
	int points;
	const char* image;
	std::string font;
	std::string colour_key;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	

public:
	
	Diamond(int x, int y, int width_height);

	int get_x() const;
	int get_y() const;
	const char* get_image() const;
	int get_width() const;
	int get_height() const;
	int get_points() const;
	std::string get_colour_key() const;
	void draw_element(SDL_Renderer* myRenderer);
};

#endif