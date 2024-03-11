// This is a binary tree class. Each node can have a maximum of two children.
// The data is ordered from smallest to the left, and largest to the right.
// Every new addition must check if it is larger or smaller than the root node
// and then the next, all the way until it reaches null, where it is finally 
// created and added to the tree hierarchy. 

#include "node.h"
#include <iostream>

class tree {
	private:
		node* root;

		// Adds a new node to the tree based on the size of its data compared to the rest of the nodes:
		void addNode(node* &currentNode, int data) {
			if (!currentNode) { // If the currentNode is null
				currentNode = new node(data); // Create a new node
				return;
			} 
			if (data > currentNode->getData()) { // Check if the data is greater than the current node's data
				addNode(currentNode->getRightNode(), data); // If so, traverse down the right side
			} else { // Else, go left
				addNode(currentNode->getLeftNode(), data);
			}
		}

		// Prints all the data in the tree in order from smallest value to largest value:
		void print(node* currentNode) {
			if (!currentNode) { // If the currentNode is null we've reached a leaf, or there is no tree (root == null)
				return;
			} // Tree traversal: go left unitl null, go back and print node data, then go right and repeat.
			print(currentNode->getLeftNode()); // Go left until we reach base case above
			std::cout << currentNode->getData() << " "; // Once we are at smallest node, print its data, then...
			print(currentNode->getRightNode()); // go right
		}

	public:
		tree() : root(nullptr) {}

		// Wrapper functions that call private methods that deal with the root node:
		void addNode(int data) { // Adds a node to the binary tree
			addNode(this->root, data);
		}

		void print() { // Prints all the nodes in order from smallest data to largest data
			print(this->root);
		}
};
