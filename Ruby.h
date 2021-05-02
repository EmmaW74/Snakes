#ifndef RUBY_H
#define RUBY_H
#include "ImyPrize.h"
#include "IRenderable.h"
class Ruby :
    public ImyPrize
{
	//Prize type ruby
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
	
	int get_x() const;
	int get_y() const;
	const char* get_image() const;
	int get_width() const;
	int get_height() const;
	int get_points() const;
	std::string get_font() const;
	std::string get_colour_key() const;
	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	

	//~Ruby();
};

#endif