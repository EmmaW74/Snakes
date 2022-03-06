#ifndef CAPP_H
#define CAPP_H
#include "SDL.h"
#include <SDL_image.h>
#include "mySnake.h"
#include "myPrizePot.h"
#include "IRenderable.h"
#include "Score_controller.h"
#include "RenderableImage.h"
#include "introController.h"

//Handles window creation and rendering
class myWindow
{	
private:
	SDL_Window* myAppWindow = NULL;
	SDL_Renderer* myRenderer = NULL;
	SDL_Texture* myTexture = NULL;
	std::shared_ptr<Dimensions> defaults;
	std::shared_ptr<RenderableColourBlock> banner = NULL;
	
public:

	myWindow(std::shared_ptr<Dimensions> measurements, std::shared_ptr<introController> intro, std::shared_ptr<RenderableImage> background, std::shared_ptr<Dimensions> defaults);
	void drawFrame(std::shared_ptr<mySnake> snake, std::shared_ptr <myPrizePot> current_prizes, std::shared_ptr<Score_controller> score, std::shared_ptr<RenderableImage> background);
	void publishTexture();
	void countdown(std::shared_ptr<RenderableImage> background);
	SDL_Renderer* get_myRenderer() const;
	std::shared_ptr<RenderableColourBlock> get_banner() const;
	~myWindow();
};

#endif
