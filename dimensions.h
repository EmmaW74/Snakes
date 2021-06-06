#pragma once
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
class Dimensions
{
private:
	
	int cell_size;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int banner_height;
	int initial_snake_length;
	int initial_snake_speed;
	

	std::string game_font; //"Font/Gilsanub.ttf"
	int h1_size; //70
	int h2_size; //40
	int h3_size; //20

	uint8_t main_colour_red; // 0xfc
	uint8_t main_colour_blue; // 0xe5 
	uint8_t main_colour_green; // 0x12

	uint8_t sec_colour_red;
	uint8_t sec_colour_blue;
	uint8_t sec_colour_green;
	

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
};

