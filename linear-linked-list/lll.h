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

		int count_items(node* head);
		int sum_list(node* head);
		int order_list(node* &head); // order list from smallest to largest

	public:
		// These are public wrapper functions that call the private methods:
		lll() : head (nullptr) {} // default constructor setting head = nullptr
		~lll(); // destructor to free all nodes
		int add_at_end(int data_to_add); // wrapper function
		void print(); // wrapper for print
		void print_in_reverse(); // wrapper for print_in_reverse

		int count_items();
		int sum_list();
		int order_list(); // wrapper function
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

int lll::count_items() { return count_items(head); }
int lll::count_items(node* head) {
	if (head == nullptr) {return 0; } // no more nodes in the list
	return count_items(head -> next) + 1; // add one until we reach the end of the list
}

int lll::sum_list() { return sum_list(head); }
int lll::sum_list(node* head) { 
	if (head == nullptr) return 0; // either no list, or reached the end
	return sum_list(head->next) + head -> data; // adding each node's data
}

int lll::order_list() { // wrapper function
	int count = count_items(head);
	for (int i=0; i < count; i++) { // for every item in the list, the list is ordered
		order_list(head);
	}
	return 1;
}
int lll::order_list(node* &head) {
	if (head == nullptr) return 0; // no list, no swaps
	if (head -> next == nullptr) return 0; 
	if ((head -> data) > (head -> next -> data)) { // the current node is bigger than the next
		node* temp = head -> next; // hold on to the next node (the one with a bigger int)
	// perform a swapping of nodes as in bubble sort
		head-> next = temp -> next; 
		temp -> next = head;
		head = temp;
	}	
	return order_list(head -> next);
}
