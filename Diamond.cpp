#include "Diamond.h"
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

Diamond::Diamond(int x, int y, int width_height) :
	x{ x }, y{ y }, width{ width_height }, height{ width_height }{
	image = "Images/diamond.bmp";
	points = 100;
	font = "";
	colour_key = "";
	
	colour_blue = NULL;
	colour_green = NULL;
	colour_red = NULL;
}
int Diamond::get_width() const {
	return width;
}
int Diamond::get_height() const {
	return height;
}
int Diamond::get_x() const {
	return x;
}
int Diamond::get_y() const {
	return y;
}
const char* Diamond::get_image() const {
	return image;
}
int Diamond::get_points() const {
	return points;
}


std::string Diamond::get_colour_key() const {
return colour_key;
}


void Diamond::draw_element(SDL_Renderer* myRenderer) {
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

//Diamond::~Diamond() {
//	std::cout << "Diamond destructor" << std::endl;
//}
