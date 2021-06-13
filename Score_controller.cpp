#include "Score_controller.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <map>
#include <fstream>
#include <sstream>

Score_controller::Score_controller(std::shared_ptr<Dimensions> defaults,int x, int y) :
	score_font{ defaults->get_game_font() }, current_score_text{ "Score: " }, x{ x }, y{ y }, score{ 0 }{
	colour_red = defaults->get_sec_red();
	colour_blue = defaults->get_sec_blue();
	colour_green = defaults->get_sec_green();
	update_score(score);
	name_x = 100;
	name_y = 250;
	read_high_scores_file();
};

void Score_controller::reset_score() {
	score = 0;
}

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
	return score_font;
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
	// Creates texture for text and copies to renderer ready to publish
	TTF_Init();
	TTF_Font* font = TTF_OpenFont(score_font.c_str(), 20); //this opens a font style and sets a size
	SDL_Color color = { colour_red, colour_green, colour_blue }; 
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, current_score_text.c_str(), color); //Create surface first
	SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(myRenderer, surfaceMessage); //Convert to texture

	SDL_Rect Message_rect;  
	Message_rect.x = get_x();   
	Message_rect.y = get_y(); 
	Message_rect.w = surfaceMessage->w; 
	Message_rect.h = surfaceMessage->h; 

	SDL_RenderCopy(myRenderer, textureMessage, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(textureMessage);
}
 
void Score_controller::enter_high_score_name(std::string user, int score) {
	//remove bottom score from multimap 
	std::multimap<int, std::string>::iterator it = high_score_list.begin();
	high_score_list.erase(it);

	//insert username into correct place
	int inserted = 0;
	it = high_score_list.begin(); 
	while (it != high_score_list.end() && inserted == 0) {
		if (score <= it->first) {
			high_score_list.insert(it, { score,user });
			inserted = 1;
		}
		else {
			it++;
		}
	}
	if (inserted == 0) {
		high_score_list.insert(it, { score,user });
	}
} 

void Score_controller::read_high_scores_file() {
//builds high score list based on txt file if it exists, or creates new list if not
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
