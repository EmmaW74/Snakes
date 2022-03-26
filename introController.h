#pragma once
#include "RenderableText.h"
#include "RenderableImage.h"
#include "myLinkedList.h"
#include "dimensions.h"

//Displays and updates text and options on Welcome screen
class introController :
    public RenderableText
{
private:
	
	int x;
	int y;
	bool border_choice;
	std::shared_ptr<myLinkedList<RenderableText>> intro_text;
	int font_size;
	std::shared_ptr<Dimensions> defaults;

public:
	//manage and draw introduction screen
	introController(bool border_choice, std::shared_ptr<Dimensions> gameDefaults);
	void update_border_choice();
	void draw_element(SDL_Renderer* myRenderer, std::shared_ptr<RenderableImage> background);
	
	//get methods
	bool get_border_choice() const;
	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	std::string get_font() const;
	int get_x() const;
	int get_y() const;

};

