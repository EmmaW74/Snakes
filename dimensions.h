#pragma once
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"

//Dimensions, font and colours
class Dimensions
{
private:
	
	const int cell_size;
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	const int banner_height;
	const int initial_snake_length;
	const int initial_snake_speed;
	

	std::string game_font{ "Font/Gilsanub.ttf" }; 
	const int h1_size{ 70 };  
	const int h2_size{ 40 };  
	const int h3_size{ 20 };  

	const uint8_t main_colour_red{ 0xfc };  
	const uint8_t main_colour_blue{ 0x12 };  
	const uint8_t main_colour_green{ 0xe5 };  

	const uint8_t sec_colour_red{ 0xff };  
	const uint8_t sec_colour_blue{ 0xff };  
	const uint8_t sec_colour_green{ 0xff };  
	

public:
	Dimensions(int cell_size, int banner_height, int length, int speed);

	int get_cell_size() const;
	int get_banner_height() const;
	int get_screen_height() const;
	int get_screen_width() const;
	int get_length() const;
	int get_speed() const;
	int get_h1_size() const;
	int get_h2_size() const;
	int get_h3_size() const;
	std::string get_game_font() const;
	uint8_t get_main_red() const;
	uint8_t get_main_green() const;
	uint8_t get_main_blue() const;
	uint8_t get_sec_red() const;
	uint8_t get_sec_green() const;
	uint8_t get_sec_blue() const;
};

