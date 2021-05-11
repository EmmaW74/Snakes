#include "myPrizePot.h"
#include "SDL.h"
#include <vector>



myPrizePot::myPrizePot() :
	prize_count{ 0 } {
	children = std::make_shared<myLinkedList<ImyPrize>>();
}

//std::shared_ptr<std::vector<std::shared_ptr<ImyPrize>>> myPrizePot::getchildren() const {
std::shared_ptr<myLinkedList<ImyPrize>> myPrizePot::getchildren() const {
	return children;
};

void myPrizePot::draw_element(SDL_Renderer* myRenderer) { //MOVE THIS TO LINKED LIST?
	/*
	if (prize_count > 0) {
		auto it = children->begin();
		while (it != children->end()) {
			(*it)->draw_element(myRenderer);
			it++;
		}
	}*/
	if (prize_count > 0) {
		node<ImyPrize>* ptr = children->get_head();
		while (ptr->next != nullptr) {
			ptr->data->draw_element(myRenderer);
			ptr = ptr->next;
		}
		ptr->data->draw_element(myRenderer);
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
}
