#ifndef CAPP_H
#define CAPP_H
#include "SDL.h"
#include <SDL_image.h>
#include "mySnake.h"
#include "ImyPrize.h"


class myWindow
{
//This class handles window creation and rendering
private:
	SDL_Window* myAppWindow = NULL;
	SDL_Renderer* myRenderer = NULL;
	SDL_Texture* myTexture = NULL;
	SDL_Texture* myBackground = NULL;
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	
public:

	myWindow();
	//SDL_Texture* LoadImage(std::string path);
	void setBackground(); //Create a background surface to be reused
	void drawFrame(std::shared_ptr<mySnake> snake, std::vector<std::shared_ptr<ImyPrize>> prizes, int score);
	void drawHeader();
	void drawSnake(std::shared_ptr<mySnake> snake); 
	void drawPrize(std::shared_ptr<ImyPrize> prize);
	void drawScore(int score);
	void publishTexture(); //Publish my texture to window
	void intro();
	void showGameOver();
	void countdown();
	void renderPrize(ImyPrize* prize); //load prize image and update renderer
	~myWindow();
};

#endif
