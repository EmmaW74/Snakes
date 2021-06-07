#include "Score_controller.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <map>
#include <fstream>
#include <sstream>


Score_controller::Score_controller() {};

Score_controller::Score_controller(int x, int y, uint8_t red, uint8_t blue, uint8_t green) :
	font{ "Font/Arial.ttf" }, current_score_text{ "Score: " }, x{ x }, y{ y }, colour_red{ red }, colour_blue{ blue }, colour_green{ green }, score{ 0 }{
	update_score(score);
	name_x = 100;
	name_y = 250;
	read_high_scores_file();
};

void Score_controller::update_score(int addScore) {
	score += addScore;
	update_text();
}
int Score_controller::get_x() const {
	return x;
}
int Score_controller::get_y() const {
	return y;
}
uint8_t Score_controller::get_colour_red() const {
	return colour_red;
}
uint8_t Score_controller::get_colour_blue() const {
	return colour_blue;
}
uint8_t Score_controller::get_colour_green() const {
	return colour_green;
}
std::string Score_controller::get_font() const {
	return font;
}

void Score_controller::update_text() {
	current_score_text = "Score: " + std::to_string(score);
}

int Score_controller::get_name_x() const {
	return name_x;
}
int Score_controller::get_name_y() const {
	return name_y;
}

int Score_controller::get_score() const {
	return score;
}

int Score_controller::get_bottom_high_score() {
	std::multimap<int, std::string>::iterator it = high_score_list.end();
	it--;
	return it->first;
}

std::multimap<int, std::string, std::greater<int>> Score_controller::get_high_score_list() const {
	return high_score_list;
}

void Score_controller::draw_element(SDL_Renderer* myRenderer ) {
	// code to add text
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", 20); //this opens a font style and sets a size
	SDL_Color color = { colour_red, colour_green, colour_blue };  // this is the text color in rgb format
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, current_score_text.c_str(), color); //Create surface first
	SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Convert to texture
	

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = get_x();  //controls the rect's x coordinate 
	Message_rect.y = get_y(); // controls the rect's y coordinte
	Message_rect.w = surfaceMessage->w; // controls the width of the rect
	Message_rect.h = surfaceMessage->h; // controls the height of the rect

	SDL_RenderCopy(myRenderer, textureMessage, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(textureMessage);
}

/*
void Score_controller::draw_element(SDL_Renderer* myRenderer, SDL_Color colour, std::string mText, int font_size) const {
	// code to add text
	std::string temp = mText;
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Font/Arial.ttf", font_size); //this opens a font style and sets a size
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, temp.c_str(), colour); //Create surface first
	SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Convert to texture


	SDL_Rect Message_rect; //create a rect
	Message_rect.x = get_name_x();  //controls the rect's x coordinate 
	Message_rect.y = get_name_y(); // controls the rect's y coordinte
	Message_rect.w = surfaceMessage->w; // controls the width of the rect
	Message_rect.h = surfaceMessage->h; // controls the height of the rect

	SDL_RenderCopy(myRenderer, textureMessage, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(textureMessage);
}
*/


void Score_controller::enter_high_score_name(std::string user, int score) {
	//remove bottom score from multimap 
	std::multimap<int, std::string>::iterator it = high_score_list.begin();
	high_score_list.erase(it);

	//insert username into correct place
	it = high_score_list.begin(); //reset iterator
	while (it != high_score_list.end()) {
		if (score <= it->first) {
			high_score_list.insert(it, { score,user });
			break;
		}
		else {
			it++;
		}
	}
} 

void Score_controller::read_high_scores_file() {
	std::fstream in_file{ "Scores/highscores.txt" };
	if (in_file.is_open()) {
		std::string line;
		int score;
		std::string name{};
		while (std::getline(in_file, line)) {
			std::istringstream iss{ line };
			iss >> score >> name;
			high_score_list.insert({ score,name });

		}
	}
	else {
		std::cout << "highscores.txt could not be opened" << std::endl;
		high_score_list.insert({ 100,"Bob" });
		high_score_list.insert({ 300,"Frank" });
		high_score_list.insert({ 100,"Rita" });
		high_score_list.insert({ 500,"Jane" });
		high_score_list.insert({ 650,"Larry" });
	}
	in_file.close();
} 
void Score_controller::write_high_scores_file() {
	// Saves high scores to a text file to use again

	std::fstream out_file{ "Scores/highscores.txt", std::ios::out };
	if (!out_file) {
		std::cout << "highscores.txt could not be created" << std::endl;
	}

	auto it = high_score_list.begin();
	while (it != high_score_list.end()) {
		out_file << it->first << " " << it->second << std::endl;
		it++;
	}

	out_file.close();

}
