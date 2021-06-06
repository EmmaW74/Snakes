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

myWindow::myWindow(std::shared_ptr<Dimensions> measurements, std::shared_ptr<introController> intro, std::shared_ptr<RenderableImage> background) {
	
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
				//intro()
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
	//std::cout << "Publish" << std::endl;
	SDL_RenderPresent(myRenderer);
}


void myWindow::showGameOver(std::shared_ptr<mySnake> snake, std::shared_ptr<RenderableImage> background) {
	//std::cout << "Game over called" << std::endl;
		
	for (int x = 0; x < 3; x++) {
		snake->changeSnakeColour(0xff, 0xff, 0xff);
		snake->draw_element(myRenderer);
		banner->draw_element(myRenderer);
		SDL_RenderPresent(myRenderer);
		SDL_Delay(200);
		snake->changeSnakeColour(0x00, 0x00, 0x00);
		snake->draw_element(myRenderer);
		banner->draw_element(myRenderer);
		SDL_RenderPresent(myRenderer);
		SDL_Delay(200);

		/*
		SDL_SetRenderDrawColor(myRenderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderClear(myRenderer); // Fill render with color
		SDL_RenderPresent(myRenderer); // Show render on window
		SDL_Delay(200);
		SDL_SetRenderDrawColor(myRenderer, 0x2F, 0x3A, 0xCE, 0x2F);
		SDL_RenderClear(myRenderer); // Fill render with color
		SDL_RenderPresent(myRenderer); // Show render on window
		SDL_Delay(200);

	}

	SDL_Surface* surface = IMG_Load("Images/GameOver.jpg");
	if (surface == NULL) {
		std::cout << "Game over not loaded" << std::endl;
	}
	myTexture = SDL_CreateTextureFromSurface(myRenderer, surface);
	SDL_RenderCopy(myRenderer, myTexture, NULL, NULL);
	SDL_FreeSurface(surface);
	publishTexture(); */
	}

	background->draw_element(myRenderer);
	TTF_Init();
	uint8_t red = 0xfc;
	uint8_t green = 0xe5;
	uint8_t blue = 0x12;
	SDL_Color color = { red, green, blue };
	int tempfont = 70;
		TTF_Font* myFont = TTF_OpenFont("Font/Gilsanub.ttf", tempfont);
		SDL_Rect Destination_rect;
		Destination_rect.x = 50;
		Destination_rect.y = 150;
		std::string text = "GAME OVER";
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(myFont, text.c_str(), color); //Create surface first
		SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Convert to texture

		Destination_rect.w = surfaceMessage->w;
		Destination_rect.h = 20;
		SDL_Rect Source_rect;
		Source_rect.x = 0;
		Source_rect.y = 0;
		Source_rect.w = Destination_rect.w;
		Source_rect.h = 20;
		do {
			SDL_RenderClear(myRenderer);
			background->draw_element(myRenderer);
			SDL_RenderCopy(myRenderer, textureMessage, &Source_rect, &Destination_rect);
			publishTexture();
			Source_rect.h++;
			Destination_rect.h++;
			SDL_Delay(10);
		} while (Source_rect.h < surfaceMessage->h);
		//SDL_RenderCopy(myRenderer, textureMessage, &Source_rect, &Destination_rect);
		//publishTexture();
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(textureMessage);
		
}

void myWindow::countdown(std::shared_ptr<RenderableImage> background) {
	
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", 200); //this opens a font style and sets a size

	SDL_Color color = { 255, 242, 0 };  // this is the text color in rgb format


	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 280;  //controls the rect's x coordinate 
	Message_rect.y = 150; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 200; // controls the height of the rect

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

	//Free your surface and texture
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