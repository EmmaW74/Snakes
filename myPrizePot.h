#pragma once
#include "IMyPrize.h"
#include "myLinkedList.h"

class myPrizePot 
   // using vector at the moment until myLinkedList developed to remove from middle of list
{
private:
    std::shared_ptr<std::vector<std::shared_ptr<ImyPrize>>> children; //change this to linked list later
    int prize_count;

public:
    myPrizePot();
    std::shared_ptr<std::vector<std::shared_ptr<ImyPrize>>> getchildren() const;
    void draw_element(SDL_Renderer* myRenderer);
    int get_prize_count() const;
    void add_prize(std::shared_ptr<ImyPrize> newPrize);
    void remove_prize(int index);
};

