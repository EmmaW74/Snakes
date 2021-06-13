#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include<iostream>
template <typename T>
struct node {
	T* data;
	node* next;
	node* prev;
};
class myIterator;

template<typename T>
class myLinkedList {
	//User defined double linked list - used in snake and prize pot
private:
	node<T>* head;
	node<T>* tail;
	int size;

public:

	template<typename T> class myIterator;
	typedef myIterator<T> iterator;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef node<T> value_type;
	typedef node<T>* pointer;
	typedef node<T>& reference;

	template<typename T>
	class myIterator {
		//user defined iterator to use with linked list
		friend class myLinkedList;
	protected:
		pointer it_ptr;
		myLinkedList<T>& list;
	public:

		myIterator<T>(myLinkedList<T>& list, pointer it_ptr) :
			it_ptr{ it_ptr }, list{ list } {}

		reference operator*() const { return *it_ptr; }
		pointer operator->() { return it_ptr; }

		// Prefix increment
		iterator& operator++() { it_ptr = it_ptr->next; return *this; }

		// Postfix increment
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator== (const iterator& a, const iterator& b) { return a.it_ptr == b.it_ptr; };
		friend bool operator!= (const iterator& a, const iterator& b) { return a.it_ptr != b.it_ptr; };

	};

	myLinkedList() {
		head = nullptr;
		tail = NULL;
		size = 0;
	}

	myLinkedList(T* object) {
		head = new node<T>{ object,nullptr,nullptr };
		tail = head;
		head->prev = nullptr;
		size = 1;
	}

	node<T>* get_head() const {
		return head;
	}
	node<T>* get_tail() const {
		return tail;
	}

	int get_size() const {
		return size;
	}

	T* get_element(int x) const {
		node<T>* ptr = head;

		for (int i = 0; i <= x; i++) {
			if (x == 0) {
				return ptr->data;
			}

			if (i == x) {
				return ptr->data;
				
			}
			else {
				if (ptr->next == nullptr) {
					return nullptr;
					
				} else {
					ptr = ptr->next;
				}
				
			}
			
		}
		return nullptr;
				
	}

	void set_tail() {
		node<T>* ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		tail = ptr;
	}

	void add_node_tail(T* data) {

		node<T>* temp = new node<T>;
		temp->data = data;
		temp->next = nullptr;
		temp->prev = tail;

		if (head == nullptr) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
		node<T>* ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = temp;
		tail = temp;
		size++;
		}
	}

	void add_node_head(T* data) {
	
		node<T>* temp = new node<T>;
		temp->data = data;
		temp->next = head;
		temp->prev = nullptr;
		head = temp;
		size++;
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
		size--;
	}

	void remove_a_node(T* object) {
		node<T>* ptr2 = head;
		node<T>* ptr1 = head->next;

		if (ptr2->data == object) {
			if (ptr1 != nullptr) {
				ptr1->prev = head;
			}
			head = head->next;
			delete ptr2;
		}
		else {
			while (ptr1->data != object) {
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			if (ptr1->data == object) {
				if (ptr1->next != nullptr) {
					ptr1->next->prev = ptr1->prev;
				}
				else {
					tail = ptr1->prev;
				}
				ptr2->next = ptr1->next;
				delete ptr1;
			}
			else {
				std::cout << "Object not found" << std::endl;
			}
		}
		size--;
	};

	iterator begin() {
		return iterator{ *this, head };

	}
	iterator end() {
		return iterator{ *this, tail->next };
	}

	~myLinkedList() {
		while (head != nullptr) {
			remove_node_tail();
		}
	}
};

#endif
