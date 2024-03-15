#include "node.h"
#include <queue>
#include <iostream>
using namespace std;

// This is the minHeap class. It is a binary tree with a root node holding the smallest value.
// Both children of the root must have larger value than itself. This must hold true for every
// subtree to the root as well.

class minHeap {
	private:
		node* root;

		// We want to add the new node at the very end of the tree. Since the min heap
		// must be a complete binary tree, this means that every node must have two 
		// children before we create a new layer of leafs.
		void add(node* &current, int value, int layer, node* &parent) {
			if (current == nullptr) { // Either there is no tree, or we reached the null of a leaf
				current = new node(value, parent);
				cout << "Added value: " << value << " at layer: " << layer << " of the minHeap." << endl;
				if (current == this->root) {
					cout << "The root of the tree has value: " << current->getValue() << "\n" << endl;
				} else {
					cout << "Parent value of " << value << " is: " << parent->getValue() << " at layer: " << layer -1 << "\n" << endl;
				}
			}
			// If the left pointer is null we go there to create a new node
			else if (current->getLeft() == nullptr) {
			add(current->getLeft(), value, ++layer, current);
			} // If the right pointer is null, go there to create a new node
			else if (current->getRight() == nullptr) { 
			add(current->getRight(), value, ++layer, current); // go left first
			} 
			else { // Otherwise, we traverse left and check again
			add(current->getLeft(), value, ++layer, current);
			}
			// After adding a new node, we need to check if its value is smaller than its parent.
			// If this is the case, we must swap it with its parent until we are a minHeap again.
			heapifyUp(current); // This method takes care of any violations in value arangement in the tree.
		}

		void heapifyUp(node* &current) {
			if (current == this->root) { // We checked all parents and their children. The minHeap structure is restored.
				return;
			}
			// Check the newly added node's value with its parent's value
			if (current->getParent()->getValue() > current->getValue()) { // If current's value is smaller, we swap them
				// Swapping values:
				int temp = current->getParent()->getValue();
				current->getParent()->setValue(current->getValue()); // The parent gets the childs smaller value
				current->setValue(temp); // The child gets the parents' larger value
				cout << "Child value: " << current->getParent()->getValue() << " Was swapped with parent value: " << current->getValue() << "\n" << endl;
			}
			heapifyUp(current->getParent()); // Checking the newly swapped parent with its' parent
		}

		void depthFirstPrint(node* current) {
			if (current == nullptr) { // Either no tree, or we reched null at a leaf
				return;
			}
			depthFirstPrint(current->getLeft()); // Travel left first to print all nodes in order
			cout << current->getValue() << " ";
			depthFirstPrint(current->getRight()); // Travel right next
		}

		void breadthFirstPrint(node* root) {
			if (root == nullptr) return; // No tree
			queue<node*> q;
			q.push(root); // Add root to the queue

			while (!q.empty()) { // Until there are no more nodes
				node* current = q.front(); // Current is first the root, then its children
				q.pop();
				cout << current->getValue() << " "; // Print value at front

				if (current->getLeft() != nullptr) // Left to right traversal and print
					q.push(current->getLeft());
				if (current->getRight() != nullptr)
					q.push(current->getRight());
			}
		}

	public:
		minHeap() {
			root = nullptr;
		}

		void add(int value) { // Wrapper method for the recursive method that is private
			add(root, value, 1, root); // Layer one is the root and it has no parent (nullptr)
		}

		void depthFirstPrint() {
			depthFirstPrint(root);
		}

		void breadthFirstPrint() {
			breadthFirstPrint(root);
		}
};
