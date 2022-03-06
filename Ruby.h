#ifndef RUBY_H
#define RUBY_H
#include "ImyPrize.h"

//Stores details of prize type ruby and draws on screen
class Ruby :
    public ImyPrize
{
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
	
	Ruby(int x, int y, int width_height);
	void draw_element(SDL_Renderer* myRenderer);
	
	//get methods
	int get_x() const;
	int get_y() const;
	const char* get_image() const;
	int get_width() const;
	int get_height() const;
	int get_points() const;
	std::string get_colour_key() const;

};

#endif