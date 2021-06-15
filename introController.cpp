#include "introController.h"
#include "RenderableImage.h"
#include "SDL_ttf.h"
#include <string>
#include "dimensions.h"

introController::introController(bool border_choice, std::shared_ptr<Dimensions> gameDefaults) :
	border_choice{ border_choice }, defaults{gameDefaults}, x{ 100 }, y{ 150 } {
	font_size = 45;
	intro_text= std::make_shared<myLinkedList<RenderableText>>();
	intro_text->add_node_tail(new RenderableText(30, 100, defaults->get_game_font(), "WELCOME TO SNAKES", defaults->get_main_red(), defaults->get_main_blue(), defaults->get_main_green()));
	intro_text->add_node_tail(new RenderableText(50, 180, defaults->get_game_font(), "- TO START, PRESS ENTER", defaults->get_main_red(), defaults->get_main_blue(), defaults->get_main_green()));
	intro_text->add_node_tail(new RenderableText(50, 210, defaults->get_game_font(), "- CONTROL SNAKE WITH ARROW KEYS", defaults->get_main_red(), defaults->get_main_blue(), defaults->get_main_green()));
	intro_text->add_node_tail(new RenderableText(50, 240, defaults->get_game_font(), "- TO PAUSE, PRESS SPACE", defaults->get_main_red(), defaults->get_main_blue(), defaults->get_main_green()));

	if (border_choice) {
		intro_text->add_node_tail(new RenderableText(50, 270, defaults->get_game_font(), "- BORDER COLLISION, PRESS B: ON", defaults->get_main_red(), defaults->get_main_blue(), defaults->get_main_green()));
	}
	else {
		intro_text->add_node_tail(new RenderableText(50, 270, defaults->get_game_font(), "- BORDER COLLISION, PRESS B: OFF", defaults->get_main_red(), defaults->get_main_blue(), defaults->get_main_green()));
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
		SDL_Color color = { defaults->get_main_red(), defaults->get_main_green(), defaults->get_main_blue() };
		int tempfont = font_size;
		for (auto& i : *intro_text) {
			TTF_Font* myFont = TTF_OpenFont(defaults->get_game_font().c_str(), tempfont); 
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