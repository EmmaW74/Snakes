#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
template <typename T>
struct node {
	T* data;
	node* next;
};

template<typename T>
class myLinkedList {
private:
	node<T>* head;
	node<T>* tail;

public:
	
	myLinkedList(T* object) {
		head = new node<T>{ object,nullptr };
		tail = head;
	}

	node<T>* get_head() const {
		return head;
	}
	node<T>* get_tail() const {
		return tail;
	}
	void set_tail() {
		node<T>* ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		tail = ptr;
		delete ptr;
	}

	void add_node_tail(T* data) {
		node<T>* temp = new node<T>;
		temp->data = data;
		temp->next = nullptr;

		node<T>* ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = temp;
		tail = temp;

	}

	void add_node_head(T* data) {
		node<T>* temp = new node<T>;
		temp->data = data;
		temp->next = head;
		head = temp;
	}

	void remove_node_tail() {
		//Removes last node from linked list, deletes node and related MyDot, updates tail pointer
		node<T>* ptr2 = head;
		node<T>* ptr1 = head->next;
		if (ptr1 == nullptr) {
			head = nullptr;
			delete ptr2->data;
			delete ptr2;
		}
		else {
			while (ptr1->next != nullptr) {
				ptr2 = ptr2->next;
				ptr1 = ptr1->next;
			}
			ptr2->next = nullptr;
			tail = ptr2;
			delete ptr1->data;
			delete ptr1;
		}
	}
	~myLinkedList() {
		while (head != nullptr) {
			remove_node_tail();
		}
	}
};

#endif
