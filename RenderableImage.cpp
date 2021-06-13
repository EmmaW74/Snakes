#include "RenderableImage.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

RenderableImage::RenderableImage() {}

RenderableImage::RenderableImage(int x, int y, const char* image):
	x{ x }, y{ y }, image{ image }{
	set_width_height();
}

RenderableImage::RenderableImage(int x, int y, const char* image, std::string colour_key):
	x{ x }, y{ y }, image{ image }, colour_key{ colour_key }{
	set_width_height(); 
}

int RenderableImage::get_x() const {
	return x;
}
int RenderableImage::get_y() const {
	return y;
}
int RenderableImage::get_width() const {
	return width;
}
int RenderableImage::get_height() const {
	return height;
}

void RenderableImage::set_width_height(){
	SDL_Surface* tempSurface = IMG_Load(image);
	if (tempSurface == NULL)
	{
		std::cout << "RenderableImage: Unable to load image" << SDL_GetError() << std::endl;
	}
	else {
		width = tempSurface->w;
		height = tempSurface->h;
	}

}

const char* RenderableImage::get_image() const {
	return image;
}
std::string RenderableImage::get_colour_key() const {
	return colour_key;
}

SDL_Texture* RenderableImage::get_image_texture(SDL_Renderer* myRenderer) {
	//loads image and returns a texture of the image
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
			SDL_FreeSurface(tempSurface);
			return tempTexture;
		}
	}
}

void RenderableImage::draw_element(SDL_Renderer* myRenderer) {
	//creates a texture for the image and copies to myRenderer ready to publish **IS THIS DUPLICATING THE ABOVE METHOD?**
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

		//Remove old loaded surface and texture
		SDL_DestroyTexture(tempTexture);
		SDL_FreeSurface(tempSurface);
	}
}
