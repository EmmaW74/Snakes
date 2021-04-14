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
	}
}
/*
SDL_Texture* myWindow::LoadImage(std::string path) {

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image!" << IMG_GetError() << std::endl;
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(myRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			std::cout << "Unable to create texture: " << path.c_str() << " - " << SDL_GetError() << std::endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;


}
*/
void myWindow::setBackground() {
	SDL_Surface* temp = IMG_Load("Images/grass.jpg");
	myBackground = SDL_CreateTextureFromSurface(myRenderer, temp);
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	publishTexture();
	SDL_FreeSurface(temp);
}

void myWindow::drawFrame(std::shared_ptr<mySnake> snake, std::vector <std::shared_ptr<ImyPrize>> prizes, int score) {
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	drawHeader();
	drawScore(score);
	if (prizes.size() > 0) {
		for (int x = 0; x < prizes.size(); x++) {
			drawPrize(prizes.at(x));
		}
	}
	drawSnake(snake->getBody());
	publishTexture();
	SDL_Delay(snake->getSnakeSpeed());
}

void myWindow::drawHeader() {
	//std::cout << "Draw header" << std::endl;
	SDL_Rect* temp = new SDL_Rect{ 0,0,640,40 };
	SDL_SetRenderDrawColor(myRenderer, 0x12, 0x4a, 0x12, 0x00);
	SDL_RenderFillRect(myRenderer, temp);
	delete temp;
}

void myWindow::drawSnake(std::shared_ptr <myLinkedList> snake_body) {

	SDL_Rect* temp;
	int x;
	int y;

	node* temp_node = snake_body->get_head();
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
}

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

	//need an int to char* here to do a countdown loop!! This works - need to do loop
	SDL_Surface* surfaceMessage = NULL;
	SDL_Texture* Message = NULL;
	std::stringstream s;

	for (int num = 3; num > 0; num--) {
		s << num;
		surfaceMessage = TTF_RenderText_Solid(font, s.str().c_str(), color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
		Message = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //now you can convert it into a texture
		SDL_RenderCopy(myRenderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
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

void myWindow::renderPrize(ImyPrize* prize) {
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
			//Get image dimensions

			SDL_Rect renderQuad = { 100, 100, 27, 40 };
			SDL_RenderCopy(myRenderer, newTexture, NULL, &renderQuad);

		}
		//Get rid of old loaded surface and texture
		SDL_FreeSurface(temp);
		SDL_DestroyTexture(newTexture);
	}
}

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