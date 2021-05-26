#include "Score_controller.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

Score_controller::Score_controller() {};

Score_controller::Score_controller(int x, int y, uint8_t red, uint8_t blue, uint8_t green) :
	font{ "Font/Arial.ttf" }, text{ "Score: " }, x{ x }, y{ y }, colour_red{ red }, colour_blue{ blue }, colour_green{ green }, score{ 0 }{
	update_score(score);
};

void Score_controller::update_score(int addScore) {
	score += addScore;
	update_text();
}
int Score_controller::get_x() const {
	return x;
}
int Score_controller::get_y() const {
	return y;
}
uint8_t Score_controller::get_colour_red() const {
	return colour_red;
}
uint8_t Score_controller::get_colour_blue() const {
	return colour_blue;
}
uint8_t Score_controller::get_colour_green() const {
	return colour_green;
}
std::string Score_controller::get_font() const {
	return font;
}

void Score_controller::update_text() {
	text = "Score: " + std::to_string(score);
}

int Score_controller::get_name_x() const {
	return name_x;
}
int Score_controller::get_name_y() const {
	return name_y;
}

void Score_controller::draw_element(SDL_Renderer* myRenderer) {
	// code to add text
	TTF_Init();
	
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", 20); //this opens a font style and sets a size
	SDL_Color color = { colour_red, colour_green, colour_blue };  // this is the text color in rgb format
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), color); //Create surface first
	SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Convert to texture
	

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = get_x();  //controls the rect's x coordinate 
	Message_rect.y = get_y(); // controls the rect's y coordinte
	Message_rect.w = surfaceMessage->w; // controls the width of the rect
	Message_rect.h = surfaceMessage->h; // controls the height of the rect

	SDL_RenderCopy(myRenderer, textureMessage, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(textureMessage);
}


/*
void Score_controller::enter_high_score_name(SDL_Renderer* myRenderer) {
	std::string username;

	//switch on key input
	SDL_StartTextInput();

	bool running = true;

	while (running) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_TEXTINPUT) {
				high_score_name += ev.text.text;
				//std::cout << high_score_name << std::endl;
				draw_element(myRenderer, high_score_name, name_x, name_y);
			}
			else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && high_score_name.size()) {
				high_score_name.pop_back();
				//std::cout << high_score_name << std::endl;
				draw_element(myRenderer, high_score_name, name_x, name_y);
			}
			else if (ev.type == SDLK_RETURN) {
				running = false;
			}
		}
	}


	SDL_StopTextInput();
}
*/