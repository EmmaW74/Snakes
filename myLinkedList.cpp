#include "myLinkedList.h"

myLinkedList::myLinkedList(myDot* dot) {
	head = new node{ dot,nullptr };
	tail = head;
	
}
node* myLinkedList::get_head() {
	return head;
}
node* myLinkedList::get_tail() {
	return tail;
}

void myLinkedList::set_tail() {
	node* ptr = head;
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	tail = ptr;
	delete ptr;
}

void myLinkedList::add_node_tail(myDot* data) {
	node* temp = new node;
	temp->data = data;
	temp->next = nullptr;
	
	node* ptr = head;
	while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
	ptr->next = temp;
	tail = temp;
	
}

void myLinkedList::add_node_head(myDot* data) {
	node* temp = new node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void myLinkedList::remove_node_tail() {
	node* ptr2 = head;
	node* ptr1 = head->next;
	while (ptr1->next != nullptr) {
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;
	}
	ptr2->next = nullptr;
	tail = ptr2;
}
myLinkedList::~myLinkedList() {

}
