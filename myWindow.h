#ifndef CAPP_H
#define CAPP_H
#include "SDL.h"
#include <SDL_image.h>
#include "mySnake.h"
//#include "ImyPrize.h"
#include "myPrizePot.h"
#include "IRenderable.h"

class myWindow
{
//This class handles window creation and rendering
private:
	SDL_Window* myAppWindow = NULL;
	SDL_Renderer* myRenderer = NULL;
	SDL_Texture* myTexture = NULL;
	SDL_Texture* myBackground = NULL;
	RenderableColourBlock* banner = NULL;
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	
public:

	myWindow();
	void setBackground(); //Create a background surface to be reused
	void drawFrame(std::shared_ptr<mySnake> snake, std::shared_ptr <myPrizePot> current_prizes, int score);
	void drawHeader();
	//void drawSnake(std::shared_ptr <myLinkedList> snake_children);
	void drawPrize(std::shared_ptr<ImyPrize> prize);
	void drawScore(int score);
	void publishTexture(); //Publish my texture to window
	void intro();
	void showGameOver();
	void countdown();
	void renderPrize(ImyPrize* prize); //load prize image and update renderer
	void renderElement(std::shared_ptr<IRenderable> element);
	~myWindow();
};

#endif
