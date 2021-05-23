#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableText :
    public IRenderable
{
	// Stores details of a text object and draws on screen
private:
	
	int x;
	int y;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	std::string font;
	std::string text;

public:

	RenderableText();
	RenderableText(int x, int y, std::string font, std::string text, uint8_t red, uint8_t blue, uint8_t green);
	int get_x() const;
	int get_y() const;
	std::string get_font() const;
	std::string get_text() const;
	void update_text(std::string newtext);

	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;

	void draw_element(SDL_Renderer* myRenderer);

};

