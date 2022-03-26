#include "myWindow.h"
#include "ImyPrize.h"
#include "SDL.h"
#include "SDL_image.h"
#include "myApp.h"
#include "myLinkedList.h"
#include "mySnake.h"
#include <iostream>
#include "SDL_ttf.h"
#include <string>
#include <sstream>

myWindow::myWindow(std::shared_ptr<Dimensions> measurements, std::shared_ptr<introController> intro, std::shared_ptr<RenderableImage> background, std::shared_ptr<Dimensions> defaults):
	defaults{ defaults } {
	
	//Initialisation flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Create window
		myAppWindow = SDL_CreateWindow("Snake game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, measurements->get_screen_width(), measurements->get_screen_height(), SDL_WINDOW_SHOWN);
		if (myAppWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//Create renderer
			myRenderer = SDL_CreateRenderer(myAppWindow, -1, SDL_RENDERER_ACCELERATED);
			if (myRenderer == NULL)
			{
				std::cout << "Renderer could not be created!" << SDL_GetError();
				success = false;
			}
			else
			{
				intro->draw_element(myRenderer,background);
				publishTexture();
			}
		}
		banner = std::make_shared<RenderableColourBlock>(measurements->get_screen_width(),measurements->get_banner_height(),0,0,0x12,0x4a,0x12);
	}
}
SDL_Renderer* myWindow::get_myRenderer() const {
	return myRenderer;
}

std::shared_ptr<RenderableColourBlock> myWindow::get_banner() const {
	return banner;
}

void myWindow::drawFrame(std::shared_ptr<mySnake> snake, std::shared_ptr < myPrizePot> current_prizes, std::shared_ptr<Score_controller> score, std::shared_ptr<RenderableImage> background) {
	// Draws header, score, snake and any prizes and adds a delay based on snake speed
	background->draw_element(myRenderer);
	snake->draw_element(myRenderer);
	banner->draw_element(myRenderer);
	if (current_prizes != NULL) {
		current_prizes->draw_element(myRenderer);
		score->draw_element(myRenderer);
		}
	publishTexture();
	SDL_Delay(snake->getSnakeSpeed());
}

void myWindow::publishTexture() {
	SDL_RenderPresent(myRenderer);
}

void myWindow::countdown(std::shared_ptr<RenderableImage> background) {
	//Draws countdown from 3
	TTF_Init();
	TTF_Font* font = TTF_OpenFont((defaults->get_game_font()).c_str(), 200); 

	SDL_Color color = { defaults->get_main_red(), defaults->get_main_green(), defaults->get_main_blue() };

	SDL_Rect Message_rect; 
	Message_rect.x = 280;  
	Message_rect.y = 150; 
	Message_rect.w = 100; 
	Message_rect.h = 200;  

	SDL_Surface* surfaceMessage = NULL;
	SDL_Texture* Message = NULL;
	std::stringstream s;

	for (int num = 3; num > 0; num--) {
		SDL_RenderClear(myRenderer);
		background->draw_element(myRenderer);

		s << num;
		surfaceMessage = TTF_RenderText_Solid(font, s.str().c_str(), color); // TTF_RenderText_Solid can only be used on SDL_Surface
		Message = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Surface then converted into a texture
		SDL_RenderCopy(myRenderer, Message, NULL, &Message_rect); // NULL is instead of crop size as no crop needed
		publishTexture();
		SDL_Delay(1000);
		
		publishTexture();
		s.str("");
	}

	//Free surface and texture
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

myWindow::~myWindow() {
	//Free loaded images
	if (myTexture != NULL) {
		SDL_DestroyTexture(myTexture);
		myTexture = NULL;
	}


	//Destroy window    
	SDL_DestroyRenderer(myRenderer);
	SDL_DestroyWindow(myAppWindow);
	myAppWindow = NULL;
	myRenderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

}