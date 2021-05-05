#include "Score_controller.h"
#include "SDL_ttf.h"
#include <string>

Score_controller::Score_controller() {};

Score_controller::Score_controller(int x, int y, uint8_t red, uint8_t blue, uint8_t green) :
	font{ "Font/Arial.ttf" }, text{ "Score: " }, x{ x }, y{ y }, colour_red{ red }, colour_blue{ blue }, colour_green{ green }, score{ 0 }{};

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

void Score_controller::draw_element(SDL_Renderer* myRenderer) {
	// code to add text
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", 20); //this opens a font style and sets a size
	SDL_Color color = { colour_red, colour_green, colour_blue };  // this is the text color in rgb format
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), color); //Create surface first
	SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Convert to texture
	

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 10;  //controls the rect's x coordinate 
	Message_rect.y = 10; // controls the rect's y coordinte
	Message_rect.w = surfaceMessage->w; // controls the width of the rect
	Message_rect.h = surfaceMessage->h; // controls the height of the rect

	SDL_RenderCopy(myRenderer, textureMessage, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(textureMessage);
}