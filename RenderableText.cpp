#include "RenderableText.h"
#include "SDL_ttf.h"

RenderableText::RenderableText() {}

RenderableText::RenderableText(int x, int y, std::string font, std::string text, uint8_t red, uint8_t blue, uint8_t green):
	font{ font }, text{ text }, x{ x }, y{ y }, colour_red{ red }, colour_blue{ blue }, colour_green{ green }{};

int RenderableText::get_x() const {
	return x;
}
int RenderableText::get_y() const {
	return y;
}
uint8_t RenderableText::get_colour_red() const {
	return colour_red;
}
uint8_t RenderableText::get_colour_blue() const {
	return colour_blue;
}
uint8_t RenderableText::get_colour_green() const {
	return colour_green;
}
std::string RenderableText::get_font() const {
	return font;
}

void RenderableText::update_text(std::string newtext) {
	text = newtext;
}

void RenderableText::draw_element(SDL_Renderer* myRenderer) {
	// code to add text
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", 200); //this opens a font style and sets a size
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
