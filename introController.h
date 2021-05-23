#pragma once
#include "RenderableText.h"
#include "RenderableImage.h"
#include "myLinkedList.h"

class introController :
    public RenderableText
{
	//Displays and updates text and options on Welcome screen
private:
	
	int x;
	int y;
	bool border_choice;
	uint8_t colour_red;
	uint8_t colour_blue;
	uint8_t colour_green;
	std::shared_ptr<myLinkedList<RenderableText>> intro_text;
	std::string font;
	int font_size;
	

public:
	introController(bool border_choice);
	void update_border_choice();
	bool get_border_choice() const;
	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	std::string get_font() const;
	int get_x() const;
	int get_y() const;

	void draw_element(SDL_Renderer* myRenderer, std::shared_ptr<RenderableImage> background);

};

