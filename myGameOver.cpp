#include "myGameOver.h"
#include "myWindow.h"
#include "dimensions.h"

myGameOver::myGameOver(myWindow* gameWindow, std::shared_ptr<mySnake> gameSnake1, std::shared_ptr<Dimensions> gameDefaults, std::shared_ptr<RenderableImage> gameBackground, std::shared_ptr<Score_controller> gameScore) :
	gameWindow{gameWindow},gameSnake1{gameSnake1},gameDefaults{gameDefaults},gameBackground{gameBackground},gameScore{gameScore} {
	game_over_text = "GAME OVER";
	enter_name_text = "Enter your name:";
	main_colour.r = gameDefaults->get_main_red();
	main_colour.g = gameDefaults->get_main_green();
	main_colour.b = gameDefaults->get_main_blue();
	
	line1_y = (gameDefaults->get_screen_height() / 10) * 1;
	line2_y = (gameDefaults->get_screen_height() / 10) * 2.5;
	line3_y = (gameDefaults->get_screen_height() / 10) * 5;
	line4_y = (gameDefaults->get_screen_height() / 10) * 6;
	line5_y = (gameDefaults->get_screen_height() / 10) * 8;
}
SDL_Texture* myGameOver::create_texture(std::string text, int size) {
	//Creates a texture based on text and size parameters
	TTF_Init();
	SDL_Color color = { gameDefaults->get_main_red(),gameDefaults->get_main_green(),gameDefaults->get_main_blue() };
	TTF_Font* myFont = TTF_OpenFont((gameDefaults->get_game_font()).c_str(), size);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(myFont, text.c_str(), color); //Create surface first
	SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(gameWindow->get_myRenderer(), surfaceMessage); //Convert to texture
	SDL_FreeSurface(surfaceMessage);
	return textureMessage;
}

int myGameOver::get_centre_align(SDL_Texture* texture) {
	//Returns y co-ordinate needed to centre the texture when rendered
	int w;
	SDL_QueryTexture(texture, NULL, NULL, &w, NULL);
	return ((gameDefaults->get_screen_width() - w) / 2);
}


void myGameOver::run_game_over() {
	//Controls the order the text appears on the game over screen
	snake_flash();
	SDL_RenderClear(gameWindow->get_myRenderer());
	gameBackground->draw_element(gameWindow->get_myRenderer());

	int game_over_texture_y_align = line1_y;
	SDL_Texture* game_over_texture = create_texture(game_over_text, gameDefaults->get_h1_size());
	int game_over_texture_x_align = get_centre_align(game_over_texture);
	draw_text(game_over_texture, game_over_texture_x_align, game_over_texture_y_align, Text_type::gradual);

	int you_scored_texture_y_align = line2_y;
	SDL_Texture* you_scored_texture = create_texture(you_scored(), gameDefaults->get_h2_size());
	int you_scored_texture_x_align = get_centre_align(you_scored_texture);
	draw_text(you_scored_texture, you_scored_texture_x_align, you_scored_texture_y_align, Text_type::gradual);

	//If score > 5th highest score then get username to add to high score list
	if (gameScore->get_score() > gameScore->get_bottom_high_score()) {
		int enter_name_texture_y_align = line3_y;
		SDL_Texture* enter_name_texture = create_texture(enter_name_text, gameDefaults->get_h2_size());
		int enter_name_texture_x_align = get_centre_align(enter_name_texture);
		draw_text(enter_name_texture, enter_name_texture_x_align, enter_name_texture_y_align, Text_type::gradual);
		get_user_name();
	}

	//Then show high scores
	SDL_RenderClear(gameWindow->get_myRenderer());
	gameBackground->draw_element(gameWindow->get_myRenderer());
	draw_text(game_over_texture, game_over_texture_x_align, game_over_texture_y_align, Text_type::block);
	draw_text(you_scored_texture, you_scored_texture_x_align, you_scored_texture_y_align, Text_type::block);
	draw_top_scores(gameScore->get_high_score_list());

} 


void myGameOver::draw_text(SDL_Texture* texture, int x_coord, int y_coord, Text_type type) {
	//Draws texture on screen based on co-ordinate parameters and type (gradual or block)

	int w;
	int h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	int left_margin = get_centre_align(texture);
	SDL_Rect Destination_rect{ x_coord,y_coord,w,h };
	SDL_Rect Source_rect{ 0,0,Destination_rect.w,h };

	if (type == Text_type::gradual){
		Destination_rect.h = 0;
		Source_rect.h = 0;
		do {
			SDL_RenderCopy(gameWindow->get_myRenderer(), texture, &Source_rect, &Destination_rect);
			gameWindow->publishTexture();
			Source_rect.h++;
			Destination_rect.h++;
			SDL_Delay(15);
		} while (Source_rect.h < h);
	}
	else {

		SDL_RenderCopy(gameWindow->get_myRenderer(), texture, &Source_rect, &Destination_rect);
		gameWindow->publishTexture();
	}
}

std::string myGameOver::you_scored() {
	//Builds string to display user's end score
	return "You scored " + std::to_string(gameScore->get_score()) + " points.";
}

void myGameOver::snake_flash() {
	// Makes snake flash black and white 
	for (int x = 0; x < 3; x++) {
		gameSnake1->changeSnakeColour(0xff, 0xff, 0xff);
		gameSnake1->draw_element(gameWindow->get_myRenderer());
		gameWindow->get_banner()->draw_element(gameWindow->get_myRenderer());
		SDL_RenderPresent(gameWindow->get_myRenderer());
		SDL_Delay(200);
		gameSnake1->changeSnakeColour(0x00, 0x00, 0x00);
		gameSnake1->draw_element(gameWindow->get_myRenderer());
		gameWindow->get_banner()->draw_element(gameWindow->get_myRenderer());
		SDL_RenderPresent(gameWindow->get_myRenderer());
		SDL_Delay(200);
	}
}

void myGameOver::get_user_name() {
	//gets user name and passes it to score controller to update top score list 

	//NEED TO ADD MIN AND MAX CHARACTERS FOR USERNAME ENTERED
	
	std::string high_score_name;
	bool tempRunning = true;

	while (tempRunning) {
		SDL_StartTextInput();
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_TEXTINPUT) {
				high_score_name += ev.text.text;
				draw_name_element(high_score_name);
				SDL_RenderPresent(gameWindow->get_myRenderer());
			}
			else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && high_score_name.size()) {
				
				high_score_name.pop_back();
				draw_name_element(high_score_name);
				SDL_RenderPresent(gameWindow->get_myRenderer());
			}
			else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RETURN) {
				tempRunning = false;
				SDL_StopTextInput();
				gameScore->enter_high_score_name(high_score_name,gameScore->get_score());

			}
			gameWindow->publishTexture();
		}
	}
} 

void myGameOver::draw_top_scores(std::multimap<int, std::string, std::greater<int>> top_scores) {
	// Draws list of top scores
	std::string top_score_title = "Top scores";
	SDL_Texture* top_score_texture = create_texture(top_score_title, gameDefaults->get_h2_size());
	draw_text(top_score_texture, get_centre_align(top_score_texture), line3_y, Text_type::gradual);
	line3_y = line3_y + gameDefaults->get_h1_size();

	std::multimap<int, std::string>::iterator it = top_scores.begin();
	std::string temp = it->second + " - " + std::to_string(it->first);
	SDL_Texture* temp_texture;
	while (it != top_scores.end()) {
		std::string temp = it->second + " - " + std::to_string(it->first);
		temp_texture = create_texture(temp, gameDefaults->get_h3_size());
		draw_text(temp_texture, get_centre_align(temp_texture), line3_y, Text_type::gradual);
		line3_y = line3_y + gameDefaults->get_h3_size();
		it++;
	}
}

void myGameOver::draw_name_element(std::string username) {
	
	SDL_Texture* username_texture = create_texture(username, gameDefaults->get_h2_size());
	int w;
	int h;
	SDL_QueryTexture(username_texture, NULL, NULL, &w, &h);
	//Refresh background section
	SDL_Rect Background_rect{0,line4_y,gameDefaults->get_screen_width(),(gameDefaults->get_screen_height()-line4_y)};
	SDL_Rect Destination_rect{ 0,line4_y,gameDefaults->get_screen_width(),(gameDefaults->get_screen_height() - line4_y) };
	SDL_RenderCopy(gameWindow->get_myRenderer(), gameBackground->get_image_texture(gameWindow->get_myRenderer()), &Background_rect, &Destination_rect);

	//Reset rectangle dimensions
	Destination_rect.x = get_centre_align(username_texture);
	Destination_rect.w = w;
	Destination_rect.h = h;

	SDL_Rect Source_rect;
	Source_rect.x = 0;
	Source_rect.y = 0;
	Source_rect.w = Destination_rect.w;
	Source_rect.h = Destination_rect.h;
	
	SDL_RenderCopy(gameWindow->get_myRenderer(), username_texture,&Source_rect,&Destination_rect);
	//gameWindow->publishTexture();
	
}


