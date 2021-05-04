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

myWindow::myWindow() {
	
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
		myAppWindow = SDL_CreateWindow("Snake game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
				intro();
			}
		}
		banner = new RenderableColourBlock{640,40,0,0,0x12,0x4a,0x12};
	}
}

void myWindow::setBackground() {
	//sets up myBackground texture
	SDL_Surface* temp = IMG_Load("Images/grass.jpg");
	myBackground = SDL_CreateTextureFromSurface(myRenderer, temp);
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	publishTexture();
	SDL_FreeSurface(temp);
}

void myWindow::drawFrame(std::shared_ptr<mySnake> snake, std::shared_ptr < myPrizePot> current_prizes, int score) {
	// Draws header, score, snake and any prizes and adds a delay based on snake speed
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	banner->draw_element(myRenderer);
	snake->draw_element(myRenderer);
	if (current_prizes != NULL) {
	current_prizes->draw_element(myRenderer);

}
	/*SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	drawHeader();
	drawScore(score);
	if (prizes.size() > 0) {
		for (int x = 0; x < prizes.size(); x++) {
			//drawPrize(prizes.at(x));
			renderElement(prizes.at(x));
		}
	}
	drawSnake(snake->getchildren());
	*/
	publishTexture();
	SDL_Delay(snake->getSnakeSpeed());
}

void myWindow::drawHeader() {
	//renders header bar
	//SDL_Rect* temp = new SDL_Rect{ 0,0,640,40 };
	//SDL_SetRenderDrawColor(myRenderer, 0x12, 0x4a, 0x12, 0x00);
	//SDL_RenderFillRect(myRenderer, temp);
	//delete temp;
}
/*
void myWindow::drawSnake(std::shared_ptr <myLinkedList> snake_children) {

	SDL_Rect* temp;
	int x;
	int y;

	node* temp_node = snake_children->get_head();
	int head_x;
	int head_y;

	do {
		x = temp_node->data->get_x();
		y = temp_node->data->get_y();
		SDL_SetRenderDrawColor(myRenderer, 0xF7, 0x02, 0x0b, 0xf7);
		temp = new SDL_Rect{ x + 1,y,8,10 };
		SDL_RenderFillRect(myRenderer, temp);
		delete temp;
		temp = new SDL_Rect{ x,y + 1,10,8 };
		SDL_RenderFillRect(myRenderer, temp);
		delete temp;
		temp_node = temp_node->next;

	} while (temp_node->next != nullptr);
}*/
/*
void myWindow::drawPrize(std::shared_ptr<ImyPrize> prize) {
	SDL_Surface* surface = IMG_Load(prize->get_image());
	if (surface == NULL) {
		std::cout << "Prize image not loaded" << std::endl;
	}
	else {
		SDL_Rect* temp;
		temp = new SDL_Rect{ prize->get_x(),prize->get_y(),prize->get_height(),prize->get_width() };
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
		myTexture = SDL_CreateTextureFromSurface(myRenderer, surface);
		SDL_RenderSetViewport(myRenderer, temp);
		SDL_RenderCopy(myRenderer, myTexture, NULL, NULL);
		SDL_FreeSurface(surface);
		SDL_RenderSetViewport(myRenderer, NULL);
		delete temp;
	}
}
*/
void myWindow::drawScore(int score) {
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", 200); //this opens a font style and sets a size
	SDL_Color color = { 255, 255, 255 };  // this is the text color in rgb format
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 10;  //controls the rect's x coordinate 
	Message_rect.y = 10; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 30; // controls the height of the rect
	std::string score_text = "";
	score_text = "Score: " + std::to_string(score);
	SDL_Surface* surfaceMessageScore = TTF_RenderText_Solid(font, score_text.c_str(), color); //Create surface first
	SDL_Texture* MessageScore = SDL_CreateTextureFromSurface(myRenderer, surfaceMessageScore); //Convert to texture
	SDL_RenderCopy(myRenderer, MessageScore, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessageScore);
	SDL_DestroyTexture(MessageScore);
}

void myWindow::publishTexture() {
	//std::cout << "Publish" << std::endl;
	SDL_RenderPresent(myRenderer);
}

void myWindow::intro() {
	//Load welcome screen
	SDL_Surface* temp = IMG_Load("Images/Welcome1.jpg");
	SDL_Texture* intro_page = SDL_CreateTextureFromSurface(myRenderer, temp);
	SDL_RenderCopy(myRenderer, intro_page, NULL, NULL);
	publishTexture();
	SDL_DestroyTexture(intro_page);
	SDL_FreeSurface(temp);
}

void myWindow::showGameOver() {
	//std::cout << "Game over called" << std::endl;
	for (int x = 0; x < 3; x++) {
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
	publishTexture();

}

void myWindow::countdown() {
	
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
		s << num;
		surfaceMessage = TTF_RenderText_Solid(font, s.str().c_str(), color); // TTF_RenderText_Solid can only be used on SDL_Surface
		Message = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Surface then converted into a texture
		SDL_RenderCopy(myRenderer, Message, NULL, &Message_rect); // NULL is instead of crop size as no crop needed
		publishTexture();
		SDL_Delay(1000);
		SDL_RenderClear(myRenderer);
		SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
		publishTexture();
		s.str("");
	}

	//Free your surface and texture
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}
/*
void myWindow::renderPrize(ImyPrize* prize) {
	//creates a texture for the prize image and copies to myRenderer ready to publish
	SDL_Surface* temp = IMG_Load("Images/ruby.bmp");
	if (temp == NULL)
	{
		std::cout << "loadPrize: Unable to load image" << SDL_GetError() << std::endl;
	}
	else
	{
		//Color key image
		SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 0xFF, 0xFF, 0xFF));

		//Create texture from surface pixels
		SDL_Texture* newTexture = SDL_CreateTextureFromSurface(myRenderer, temp);
		if (newTexture == NULL)
		{
			std::cout << "Unable to create texture" << std::endl;

		}
		else
		{
			//Need to get image dimensions without constants here

			SDL_Rect renderQuad = { 100, 100, 27, 40 };
			SDL_RenderCopy(myRenderer, newTexture, NULL, &renderQuad);

		}
		//Get rid of old loaded surface and texture
		SDL_FreeSurface(temp);
		SDL_DestroyTexture(newTexture);
	}
}

void myWindow::renderElement(std::shared_ptr<IRenderable> element) {
	if (element->get_image() != NULL) {
		//do something to upload image to myRenderer
		SDL_Surface* surface = IMG_Load(element->get_image());
		if (surface == NULL) {
			std::cout << "Element image not loaded" << std::endl;
		}
		else {
			SDL_Rect* temp;
			temp = new SDL_Rect{ element->get_x(),element->get_y(),element->get_height(),element->get_width() };
			SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
			myTexture = SDL_CreateTextureFromSurface(myRenderer, surface);
			SDL_RenderSetViewport(myRenderer, temp);
			SDL_RenderCopy(myRenderer, myTexture, NULL, NULL);
			SDL_FreeSurface(surface);
			SDL_RenderSetViewport(myRenderer, NULL);
			delete temp;
		}
	}
	else if (element->get_font() != "") {
		//do something to put text on page
	}
	else {
		//draw element based on measurements/colours
		SDL_Rect* temp;
		int x = element->get_x();
		int y = element->get_y();
		int w = element->get_width();
		int h = element->get_height();

		//SDL_SetRenderDrawColor(myRenderer, 0xF7, 0x02, 0x0b, 0xf7);
		SDL_SetRenderDrawColor(myRenderer, element->get_colour_red(), element->get_colour_green(), element->get_colour_blue(), 0xf7);
		temp = new SDL_Rect{ x,y,w,h };
		SDL_RenderFillRect(myRenderer, temp);
		delete temp;
	}
}
*/



myWindow::~myWindow() {
	//Free loaded images
	SDL_DestroyTexture(myTexture);
	myTexture = NULL;
	SDL_DestroyTexture(myBackground);
	myBackground = NULL;

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