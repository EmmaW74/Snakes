#include "RenderableImage.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


void RenderableImage::draw_element(SDL_Renderer* myRenderer) {
	//creates a texture for the image and copies to myRenderer ready to publish
	SDL_Surface* tempSurface = IMG_Load(image);
	if (tempSurface == NULL)
	{
		std::cout << "RenderableImage: Unable to load image" << SDL_GetError() << std::endl;
	}
	else {
		//Color key image
		SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 0xFF, 0xFF, 0xFF));

		//Create texture from surface
		SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(myRenderer, tempSurface);
		if (tempTexture == NULL)
		{
			std::cout << "RenderableImage: Unable to create texture" << std::endl;
		}
		else
		{
			SDL_Rect renderQuad = { get_x(), get_y(), get_width(), get_height() };
			SDL_RenderCopy(myRenderer, tempTexture, NULL, &renderQuad);
		}

		//Get rid of old loaded surface and texture
		SDL_DestroyTexture(tempTexture);
		SDL_FreeSurface(tempSurface);
	}
}