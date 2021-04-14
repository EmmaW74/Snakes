#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include "MyDot.h"

struct node {
	myDot* data;
	node* next;
};


class myLinkedList
    //Linked list used for snake body sections
{
private:
    node* head; 
    node* tail; 
    
public:
    myLinkedList(myDot* dot);
    node* get_head();//can't add const as this stops it being used elsewhere
    node* get_tail(); //can't add const as this stops it being used elsewhere
    void set_tail();
    void add_node_tail(myDot* data);
    void add_node_head(myDot* data);
    void remove_node_tail();
    ~myLinkedList();
};



#endif