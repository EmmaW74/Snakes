#pragma once
#include "RenderableText.h"
#include "SDL.h"

class Score_controller :
    public RenderableText
{
private:
    int score;
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	std::string font;
	std::string text;

public:
	Score_controller();
    Score_controller(int x, int y, uint8_t red, uint8_t blue, uint8_t green);
    void update_score(int addscore);
	int get_x() const;
	int get_y() const;
	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	std::string get_font() const;

	void update_text();
	void draw_element(SDL_Renderer* myRenderer);

};

