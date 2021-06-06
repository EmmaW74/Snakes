#pragma once
#include <string>
#include "Score_controller.h"
#include "dimensions.h"
#include "SDL.h"
#include "mySnake.h"
#include "RenderableImage.h"
#include "myWindow.h"
#include "dimensions.h"

enum class Text_type {
	gradual,
	block
};

class myGameOver
{
private:
	std::shared_ptr<myWindow> gameWindow;
	std::shared_ptr<mySnake> gameSnake1;
	std::shared_ptr<Dimensions> gameDefaults;
	std::shared_ptr<RenderableImage> gameBackground;
	std::shared_ptr<Score_controller> gameScore;

	int line1_y;
	int line2_y;
	int line3_y;
	int line4_y;
	int line5_y;
	
	std::string enter_name_text;
	std::string game_over_text;
	SDL_Color main_colour;


public:
	myGameOver(myWindow* gameWindow,std::shared_ptr<mySnake> gameSnake1,std::shared_ptr<Dimensions> gameDefaults,std::shared_ptr<RenderableImage> gameBackground,std::shared_ptr<Score_controller> gameScore);
	void snake_flash();
	SDL_Texture* create_texture(std::string text, int size);
	int get_centre_align(SDL_Texture* texture);
	void draw_text(SDL_Texture* texture, int x_coord, int y_coord, Text_type type);
	std::string you_scored();
	void get_user_name();
	void draw_name_element(std::string username);
	void run_game_over();
	void draw_top_scores(std::multimap<int, std::string, std::greater<int>> top_scores);
	

};

