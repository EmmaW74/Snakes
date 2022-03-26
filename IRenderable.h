#ifndef IRENDERABLE_H
#define IRENDERABLE_H
#include "myLinkedList.h"
#include<string>
#include<memory>
#include<vector>

//Interface class for rendering to window
class IRenderable
{
	int x;
	int y;

public:
	
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual ~IRenderable() {};
};

#endif