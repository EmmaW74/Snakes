#include "myWindow.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "SDL_ttf.h"

myWindow::myWindow() {
	
	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;
	//Initialisation flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Create window
		
		myAppWindow = SDL_CreateWindow("Snake game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (myAppWindow == NULL)
		{
			//printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//Get window surface
			myRenderer = SDL_CreateRenderer(myAppWindow, -1, SDL_RENDERER_ACCELERATED);
			if (myRenderer == NULL)
			{
				std::cout << "Renderer could not be created!" << SDL_GetError();
				success = false;
			}
			else
			{
				//Initialize renderer color
				/*SDL_SetRenderDrawColor(myRenderer, 0x2F, 0x3A, 0xCE, 0x2F);
				SDL_RenderClear(myRenderer); // Fill render with color
				SDL_RenderPresent(myRenderer); // Show render on window */

				//TEST//
				setBackground();
				SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
				publishTexture();
				//intro();
				countdown();
				
				
			}
		}

	}
	
}
void myWindow::setBackground() {
	SDL_Surface* temp = IMG_Load("Images/grass.jpg");
	myBackground = SDL_CreateTextureFromSurface(myRenderer, temp);
}

void myWindow::drawSnake(mySnake snake) {
	std::cout << "Draw snake" << std::endl;
	SDL_Rect* temp;
	int x;
	int y;
	//SDL_SetRenderDrawColor(myRenderer, 0x2F, 0x3A, 0xCE, 0x2F);
	//SDL_RenderClear(myRenderer);
	//TEST
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	publishTexture();
	//TEST
	for (int i = 0; i < snake.getSnakeLength(); i++) {
		x = snake.getBody().at(i)->get_x();
		y = snake.getBody().at(i)->get_y();
		SDL_SetRenderDrawColor(myRenderer, 0xF7, 0x02, 0x0b, 0xf7);
		temp = new SDL_Rect{ x+1,y,8,10 };  //Make this a current position variable
		SDL_RenderFillRect(myRenderer, temp);

		//SDL_SetRenderDrawColor(myRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		temp = new SDL_Rect{ x,y+1,10,8 };
		SDL_RenderFillRect(myRenderer, temp);
	}
	publishTexture();
	SDL_Delay(150);
} 
void myWindow::publishTexture() {
	std::cout << "Publish" << std::endl;
	SDL_RenderPresent(myRenderer);
} //Publish my texture to window

myWindow::~myWindow() {
	//Free loaded image
	SDL_DestroyTexture(myTexture);
	myTexture = NULL;

	//Destroy window    
	SDL_DestroyRenderer(myRenderer);
	SDL_DestroyWindow(myAppWindow);
	myAppWindow = NULL;
	myRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

	std::cout << "myWindow destructor called" << std::endl;
}
void myWindow::intro() {

	//THIS ISN'T WORKING
	TTF_Init();
	//load a font - name and size in points
	TTF_Font* temp_font = TTF_OpenFont("arial.ttf", 25);
	if (temp_font == NULL) {
		std::cout << " Unable to load font" << std::endl;
		
	}
	else {

		//render text to a surface
		SDL_Color temp_color = { 255, 255, 255 };
		SDL_Surface* temp_surface = TTF_RenderText_Solid(temp_font, "Welcome to Snakes", temp_color);

		//Create a texture from the surface
		SDL_Texture* temp_texture = SDL_CreateTextureFromSurface(myRenderer, temp_surface);

		// create rectangle
		SDL_Rect Message_rect; //create a rect
		Message_rect.x = 0;  //controls the rect's x coordinate 
		Message_rect.y = 0; // controls the rect's y coordinte
		Message_rect.w = 100; // controls the width of the rect
		Message_rect.h = 100; // controls the height of the rect

		//Free resources
		SDL_DestroyTexture(temp_texture);
		SDL_FreeSurface(temp_surface);

		// Publish
		SDL_RenderClear(myRenderer);
		SDL_RenderCopy(myRenderer, temp_texture, NULL, &Message_rect);
		publishTexture();
	}

	TTF_CloseFont(temp_font);
	SDL_Delay(3000);
}

void myWindow::showGameOver() {
	std::cout << "Game over called" << std::endl;
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

void myWindow::countdown() {
	// This needs a loop and extra reusable functions
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", 200); //this opens a font style and sets a size

	SDL_Color color = { 255, 242, 0 };  // this is the text color in rgb format
	

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 280;  //controls the rect's x coordinate 
	Message_rect.y = 150; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 200; // controls the height of the rect

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "3", color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	SDL_Texture* Message = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //now you can convert it into a texture
	SDL_RenderCopy(myRenderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
	publishTexture();
	SDL_Delay(1000);
	SDL_RenderClear(myRenderer);
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	publishTexture();

	surfaceMessage = TTF_RenderText_Solid(font, "2", color); 
	Message = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); 
	SDL_RenderCopy(myRenderer, Message, NULL, &Message_rect);
	publishTexture();
	SDL_Delay(1000);
	SDL_RenderClear(myRenderer);
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	publishTexture();

	surfaceMessage = TTF_RenderText_Solid(font, "1", color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	Message = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //now you can convert it into a texture
	SDL_RenderCopy(myRenderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
	publishTexture();
	SDL_Delay(1000);
	SDL_RenderClear(myRenderer);
	SDL_RenderCopy(myRenderer, myBackground, NULL, NULL);
	publishTexture();

	//Don't forget to free your surface and texture
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}