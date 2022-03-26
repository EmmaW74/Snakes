#pragma once
#include "IMyPrize.h"
#include "myLinkedList.h"

//Manages the current prizes available in the game
class myPrizePot 
{
private:
    std::shared_ptr<myLinkedList<ImyPrize>> children;
    int prize_count;

public:
    myPrizePot();

    //methods to add, remove and draw the prizes
    void draw_element(SDL_Renderer* myRenderer) const;
    void add_prize(ImyPrize* newPrize);
    void remove_prize(ImyPrize* object);
    void reset_prize_pot();

    //get methods
    std::shared_ptr<myLinkedList<ImyPrize>> getchildren() const;
    int get_prize_count() const;
};

