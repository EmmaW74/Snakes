#include "introController.h"
#include "RenderableImage.h"
#include "SDL_ttf.h"
#include <string>

introController::introController(bool border_choice) :
	border_choice{ border_choice }, colour_red{ 0xfc }, colour_blue{ 0x12 }, colour_green{ 0xe5 }, x{ 100 }, y{ 150 } {
	font = "Font/Gilsanub.ttf";
	font_size = 45;
	intro_text= std::make_shared<myLinkedList<RenderableText>>();
	intro_text->add_node_tail(new RenderableText(30, 100, font, "WELCOME TO SNAKES", colour_red, colour_blue, colour_green));
	intro_text->add_node_tail(new RenderableText(50, 180, font, "- TO START, PRESS ENTER", colour_red, colour_blue, colour_green));
	intro_text->add_node_tail(new RenderableText(50, 210, font, "- CONTROL SNAKE WITH ARROW KEYS", colour_red, colour_blue, colour_green));
	intro_text->add_node_tail(new RenderableText(50, 240, font, "- TO PAUSE, PRESS SPACE", colour_red, colour_blue, colour_green));

	if (border_choice) {
		intro_text->add_node_tail(new RenderableText(50, 270, font, "- BORDER COLLISION, PRESS B: ON", colour_red, colour_blue, colour_green));
	}
	else {
		intro_text->add_node_tail(new RenderableText(50, 270, font, "- BORDER COLLISION, PRESS B: OFF", colour_red, colour_blue, colour_green));
	}

}

	void introController::update_border_choice() {
		//updates border choice and changes chice displayed on screen
		border_choice = !border_choice;
		if (border_choice) {
			intro_text->get_tail()->data->update_text("- BORDER COLLISION, PRESS B: ON");
		}
		else {
			intro_text->get_tail()->data->update_text("- BORDER COLLISION, PRESS B: OFF");
		}
	}
	bool introController::get_border_choice() const {
		return border_choice;
	}
	uint8_t introController::get_colour_red() const {
		return colour_red;
	}
	uint8_t introController::get_colour_blue() const {
		return colour_blue;
	}
	uint8_t introController::get_colour_green() const {
		return colour_green;
	}
	std::string introController::get_font() const {
		return font;
	}
	int introController::get_x() const {
		return x;
	}
	int introController::get_y() const {
		return y;
	}

	void introController::draw_element(SDL_Renderer* myRenderer, std::shared_ptr<RenderableImage> background) {
		// Creates welcome text texture and copies to renderer ready to publish 
		background->draw_element(myRenderer);
		TTF_Init();
		SDL_Color color = { colour_red, colour_green, colour_blue };  
		int tempfont = font_size;
		for (auto& i : *intro_text) {
			TTF_Font* myFont = TTF_OpenFont(font.c_str(), tempfont); 
			SDL_Rect Message_rect;
			Message_rect.x = i.data->get_x();  
			Message_rect.y = i.data->get_y(); 
			
			SDL_Surface* surfaceMessage = TTF_RenderText_Solid(myFont, i.data->get_text().c_str(), color); //Create surface first
			SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Convert to texture

			Message_rect.w = surfaceMessage->w; 
			Message_rect.h = surfaceMessage->h; 

			SDL_RenderCopy(myRenderer, textureMessage, NULL, &Message_rect);
			
			SDL_FreeSurface(surfaceMessage);
			SDL_DestroyTexture(textureMessage);
			if (tempfont >= 45) {
				tempfont = 25;
			}
		}
	}