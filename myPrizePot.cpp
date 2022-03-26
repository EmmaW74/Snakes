#include "myPrizePot.h"
#include "SDL.h"
#include <vector>

myPrizePot::myPrizePot() :
	prize_count{ 0 } {
	children = std::make_shared<myLinkedList<ImyPrize>>();
}

void myPrizePot::reset_prize_pot() {
	// Remove existing prizes when restaring game
	if (prize_count > 0) {
		children->remove_node_tail();
		prize_count--;
	}
}

std::shared_ptr<myLinkedList<ImyPrize>> myPrizePot::getchildren() const {
	return children;
};

void myPrizePot::draw_element(SDL_Renderer* myRenderer) const { 
	//calls draw element for each prize node
	if (prize_count > 0) {

		myLinkedList<ImyPrize>::myIterator<ImyPrize> it = children->begin();
		while (it->next != nullptr) {
			it->data->draw_element(myRenderer);
			it++;
		}
		it->data->draw_element(myRenderer);
	}
}
int myPrizePot::get_prize_count() const {
	return prize_count;
}

void myPrizePot::add_prize(ImyPrize* newPrize) {
	children->add_node_tail(newPrize);
	prize_count++;
}
void myPrizePot::remove_prize(ImyPrize* object) {
	children->remove_a_node(object);
	prize_count--;
	delete object;
}
