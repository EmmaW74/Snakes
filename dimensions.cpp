#include "dimensions.h"

Dimensions::Dimensions(int cell_size, int banner_height, int length, int speed) :
	cell_size{ cell_size }, SCREEN_WIDTH{ 640 }, SCREEN_HEIGHT{ 480 }, banner_height{ banner_height }, initial_snake_length{ length }, initial_snake_speed{ speed } {
	//game_font = "Font/Arial.ttf";
	game_font = "Font/Gilsanub.ttf";
	main_colour_red = 0xfc;
	main_colour_green = 0xe5;
	main_colour_blue = 0x12;
	h1_size = 70;
	h2_size = 40;
	h3_size = 20;

}

int Dimensions::get_cell_size() const {
	return cell_size;
}

int Dimensions::get_banner_height() const {
	return banner_height;
}

int Dimensions::get_screen_height() const {
	return SCREEN_HEIGHT;
}

int Dimensions::get_screen_width() const {
	return SCREEN_WIDTH;
}

int Dimensions::get_length() const {
	return initial_snake_length;
}

int Dimensions::get_speed() const {
	return initial_snake_speed;
}

int Dimensions::get_h1_size() const {
	return h1_size;
}

int Dimensions::get_h2_size() const {
	return h2_size;
}

int Dimensions::get_h3_size() const {
	return h3_size;
}

std::string Dimensions::get_game_font() const {
	return game_font;
}

uint8_t Dimensions::get_main_red() const {
	return main_colour_red;
}

uint8_t Dimensions::get_main_green() const {
	return main_colour_green;
}

uint8_t Dimensions::get_main_blue() const {
	return main_colour_blue;
}