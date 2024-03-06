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

		int removeNode(int data_to_remove) {
			// Case 1) No list:
			if (list_ptr == nullptr) return 0;
			// Case 2) There is only one node and it holds the data:
			if (list_ptr->next == list_ptr && list_ptr->data == data_to_remove) {
				delete list_ptr;
				list_ptr = nullptr;
				return 1;
			}
			// Case 3) The node to remove is at the list_ptr and there are more nodes in the list. We need to traverse the list in order to delete it since there is no previous pointer
			if (list_ptr->data == data_to_remove) {
				node* curr = list_ptr->next;
				// Must traverse the list to delete the node	
				while (curr->next != list_ptr) {
					curr = curr->next;	
				}
				// curr->next == list_ptr so we can safely delete list_ptr:
				curr->next = list_ptr->next;
				delete list_ptr;
				list_ptr = curr;
				return 1;
			}
			// Case 4) The node to remove is the one after the list_ptr
			if (list_ptr->next->data == data_to_remove) {
				node* nodeToRemove = list_ptr->next;
				list_ptr->next = nodeToRemove->next;
				delete nodeToRemove;
				return 1;
			}
			// Case 5) The node to remove is in the middle somewhere:
			node* curr = list_ptr->next; 
			while(curr != list_ptr) { // Check if we reach the end of the list (circled back to list_ptr)
				if (curr->next->data == data_to_remove) {
					// Delete the node
					node* nodeToRemove = curr->next;
					curr->next = nodeToRemove->next; // Set current to the node after the one we are going to delete
					delete nodeToRemove;
					return 1;
				}
				curr = curr->next;
			}
			return 1;
		}
			
		node* removeNode(node* &curr, int data_to_remove) {
			if (curr == nullptr) return nullptr; // No list, nothing to remove 
			if(curr ->data == data_to_remove) { // We found the the node to remove
				node* nextLink = curr->next; // Hold the link to the next node
				delete curr; // Remove the node	
				return nextLink; // Return the node after the one that was deleted to keep the list connected
			}
			return removeNode(curr->next, data_to_remove);
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
