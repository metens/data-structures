// This file contains the class "lll" which has a 
// head pointer to a node. The class  has methods to
// add data to the list, remove data, print the data,
// and so forth.

#include "node.h"
#include <iostream>

class lll {
	private:
		node* head;
		
		// These are the functions that deal with the private data:
		int add_at_end(node* &head, int data_to_add);
		void print(node* head); // pass by value bc we aren't changing the list
		void print_in_reverse(node* head);
		int delete_list(node* &head); // deletes all nodes in the list
	public:
		// These are public wrapper functions that call the private methods:
		lll() : head (nullptr) {} // default constructor setting head = nullptr
		~lll(); // destructor to free all nodes
		int add_at_end(int data_to_add); // wrapper function
		void print(); // wrapper for print
		void print_in_reverse(); // wrapper for print_in_reverse
};

lll::~lll() {
	delete_list(head); // calls the delete function
}
int lll::delete_list(node* &head) {
	if (head == nullptr) return 0;
	node* temp = head->next; // save the next node
	delete head;
	head = temp;
	return delete_list(head);
}

int lll::add_at_end(int data_to_add) { return add_at_end(head, data_to_add); }
int lll::add_at_end(node* &head, int data_to_add) {
	if (head == nullptr) { // base case: no list, or reached the end of list
		head = new node;
		head -> data = data_to_add;
		head -> next = nullptr;
		return 1;
	}
	return add_at_end(head -> next, data_to_add);
}

void lll::print() { print(head); }
void lll::print(node* head) {
	if (head == nullptr) { // either no list, or we reached the end
		return;
	}
	std::cout << head -> data << " ";
	print(head -> next);
}

void lll::print_in_reverse() { print_in_reverse(head); }
void lll::print_in_reverse(node* head) {
	if (head == nullptr) {
		return;
	}
	print_in_reverse(head -> next);
	std::cout << head -> data << " ";
	return;
}
