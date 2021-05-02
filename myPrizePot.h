#pragma once
#include "RenderableImage.h"
#include "myLinkedList.h"
class myPrizePot :
    public RenderableImage
{
private:
    std::shared_ptr<myLinkedList<IRenderable>> children; //change this to linked list later

public:
    myPrizePot();
    std::shared_ptr<myLinkedList<IRenderable>> getchildren() const;
    void draw_prizes(SDL_Renderer* myRenderer);
    void add_prize();
    void remove_prize();
};

