#ifndef IRENDERABLE_H
#define IRENDERABLE_H
#include "myLinkedList.h"
#include<string>
#include<memory>
#include<vector>
class IRenderable
{
	//Interface class for rendering to window
	int x;
	int y;

public:
	
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual ~IRenderable() {};
};

#endif