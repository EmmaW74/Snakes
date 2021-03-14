#ifndef CAPP_H
#define CAPP_H
#include "SDL.h"
#include <SDL_image.h>
#include "mySnake.h"


class myWindow
{
private:
	SDL_Window* myAppWindow = NULL;
	SDL_Renderer* myRenderer = NULL;
	SDL_Texture* myTexture = NULL;
	SDL_Texture* myBackground;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	
public:

	myWindow();

	//SDL_Texture* LoadImage(std::string path);
	SDL_Texture* LoadImage(std::string path);
	void setBackground(); //Create a background surface to be reused
	void drawSnake(mySnake snake); //Draw snake to my texture
	void publishTexture(); //Publish my texture to window
	void intro();
	void showGameOver();
	void countdown();
	~myWindow();
};

#endif
