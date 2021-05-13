#pragma once
#include "IRenderable.h"
#include "SDL.h"
class RenderableImage :
    public IRenderable
{
	// Stores details of an image object and draws on screen
private:
	const char* image;
	int x;
	int y;
	int width;
	int height;
	std::string colour_key;
	
public:

	RenderableImage();
	RenderableImage(int x, int y, const char* image);
	RenderableImage(int x, int y, const char* image, std::string colour_key);
	int get_x() const;
	int get_y() const;
	int get_width() const;
	int get_height() const;
	const char* get_image() const;
	std::string get_colour_key() const;
	void set_width_height();
	void draw_element(SDL_Renderer* myRenderer);

};

