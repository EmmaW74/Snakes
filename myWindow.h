#ifndef CAPP_H
#define CAPP_H
#include "SDL.h"
#include <SDL_image.h>
#include "mySnake.h"
#include "myPrizePot.h"
#include "IRenderable.h"
#include "Score_controller.h"
#include "RenderableImage.h"

class myWindow
{
//This class handles window creation and rendering
private:
	
	SDL_Window* myAppWindow = NULL;
	SDL_Renderer* myRenderer = NULL;
	SDL_Texture* myTexture = NULL;
	
	RenderableColourBlock* banner = NULL;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	
public:

	myWindow(std::shared_ptr<Dimensions> measurements);
	void drawFrame(std::shared_ptr<mySnake> snake, std::shared_ptr <myPrizePot> current_prizes, std::shared_ptr<Score_controller> score, std::shared_ptr<RenderableImage> background);
	void publishTexture();
	void intro();
	void showGameOver();
	void countdown(std::shared_ptr<RenderableImage> background);
	void renderPrize(ImyPrize* prize); 
	void renderElement(std::shared_ptr<IRenderable> element);
	~myWindow();
};

#endif
