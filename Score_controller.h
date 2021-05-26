#pragma once
#include "RenderableText.h"
#include "SDL.h"
#include <SDL_ttf.h>

class Score_controller :
    public RenderableText
{
	//Keeps score and draws it on screen
private:
    int score;
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	std::string font;
	std::string text;
	std::string high_score_name;
	int name_x;
	int name_y;

public:
	Score_controller();
    Score_controller(int x, int y, uint8_t red, uint8_t blue, uint8_t green);
    void update_score(int addscore);
	int get_x() const;
	int get_y() const;
	int get_name_x() const;
	int get_name_y() const;
	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	std::string get_font() const;

	void update_text();
	void draw_element(SDL_Renderer* myRenderer);

	//void enter_high_score_name(SDL_Renderer* myRenderer);

};

