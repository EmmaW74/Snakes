#include "myPrizePot.h"
#include "SDL.h"
#include <vector>



myPrizePot::myPrizePot() :
	prize_count{ 0 } {
	children = std::make_shared<std::vector<std::shared_ptr<ImyPrize>>>();
}

std::shared_ptr<std::vector<std::shared_ptr<ImyPrize>>> myPrizePot::getchildren() const {
	return children;
};

void myPrizePot::draw_element(SDL_Renderer* myRenderer) {
	if (prize_count > 0) {
		auto it = children->begin();
		while (it != children->end()) {
			(*it)->draw_element(myRenderer);
			it++;
		}
	}
}
int myPrizePot::get_prize_count() const {
	return prize_count;
}

void myPrizePot::add_prize(std::shared_ptr<ImyPrize> newPrize) {
	children->push_back(newPrize);
	prize_count++;
}
void myPrizePot::remove_prize(int index) {
	children->erase(children->begin() + index);
	prize_count--;
}
