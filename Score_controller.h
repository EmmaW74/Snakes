#pragma once
#include "RenderableText.h"
#include "SDL.h"
#include <SDL_ttf.h>
#include <map>
#include "dimensions.h"


//Keeps score and draws it on screen
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
	std::string score_font;
	std::string current_score_text;
	std::string high_score_name;
	int name_x;
	int name_y;
	std::multimap<int,std::string,std::greater<int>> high_score_list;


public:
	
    Score_controller(std::shared_ptr<Dimensions> defaults, int x, int y);
    void update_score(int addscore);
	int get_x() const;
	int get_y() const;
	int get_name_x() const;
	int get_name_y() const;
	uint8_t get_colour_red() const;
	uint8_t get_colour_blue() const;
	uint8_t get_colour_green() const;
	std::string get_font() const;
	int get_score() const;
	int get_bottom_high_score();
	std::multimap<int, std::string, std::greater<int>> get_high_score_list () const;

	void update_text();
	void draw_element(SDL_Renderer* myRenderer);
	void enter_high_score_name(std::string user, int score);
	void read_high_scores_file();
	void write_high_scores_file();
	void reset_score();
};

