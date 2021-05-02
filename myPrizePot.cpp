#include "myPrizePot.h"
#include <vector>

myPrizePot::myPrizePot() :
	children{ NULL } {}

std::shared_ptr<myLinkedList<IRenderable>> myPrizePot::getchildren() const {
	return children;
};
void myPrizePot::draw_prizes(SDL_Renderer* myRenderer) {

}
void myPrizePot::add_prize() {
	
}
void myPrizePot::remove_prize() {

}