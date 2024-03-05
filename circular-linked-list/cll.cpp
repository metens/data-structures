#include "node.cpp"
#include <iostream>

class cll {
	public:
		// The list pointer is not necessarily a head, nor a tail, it points to the last element, but has access to the first
		node* list_ptr; 

		cll() {
			this->list_ptr = nullptr;	
		} 
		~cll() {
			if (this->list_ptr != nullptr) { // There is a list to delete
				removeList(this->list_ptr->next);
			}
		}

		void removeList(node* &currentNode) {
			if (currentNode == this->list_ptr) { // We circled the entire list
				delete currentNode;
				this->list_ptr = nullptr; // Delete the last node and set the list_ptr back to null
				return;
			}
			node* nodeToRemove = currentNode; // Set each node in the list to a delete pointer
			currentNode = currentNode->next; // Increment to the next node
			delete nodeToRemove;
			removeList(currentNode);
		}

		int addNode(int data) {
			if (this->list_ptr == nullptr) { // There is no list, make the first node
				this->list_ptr = new node(data);
				this->list_ptr->next = this->list_ptr; // Point the next link to ourselves
				return 1;
			}
			node* newNode = new node(data); // Create a new node for the list 
			newNode->next = this->list_ptr->next; // Link the new node to the lists front
			this->list_ptr->next = newNode; // Connect the list_ptr's next to the new node
			this->list_ptr = newNode; // Move the list_ptr to the new node
			return 1;
		}

		int printList(node* currentNode) {
			std::cout << currentNode->data << " "; // Print the data
			if (currentNode == this->list_ptr) return 0; // Circled back to the head
			return printList(currentNode->next);
		}
		int printList() {
			if (list_ptr == nullptr) return 0; // No list
			return printList(list_ptr->next); // Then pass the next node to recursive method
		}
};
