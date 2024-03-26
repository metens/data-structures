#include <iostream>

/* 
 * Red-Black Tree Properties:
 * 	1) All nodes are either "red" or "black"
 * 	2) The root is "black"
 * 	3) Null pointers are "black"
 * 	4) The number of "black" on any path from
 * 	   root to leaf are the same
 * 	5) No parent and child can both be "red"
 * 	6) New nodes are inserted as "red"
 */

struct node {
	int data;
	bool isRed;
	node* left;
	node* right;

	node(int data = 0) : data(data), isRed(true), left(nullptr), right(nullptr) {}
};

struct redBlackTree {
	node* root;

	redBlackTree() : root(nullptr) {}

	void insert(int data) {
		this->root = insert(root, data);
	}
	node*& insert(node* &current, int data) {
		if (!current) { // either no tree yet, or we reached a null at a leaf
			current = new node(data);
			if (current == this->root) current->isRed = false; // check if the new node is the root (property 2)
			return current;
		}
		if (data < current->data) {
			current->left = insert(current->left, data); // go left
			// we proceed with this check once we are at the grandparent of a newly inserted node:
			if (current->left->left) { // check the left-left grandchild of current
				node* uncle = current->right;
				node* parent = current->left;
				node* newNode = parent->left; // we know that a newly inserted node is always "red" (property 6)

				// check red-red vilocation of parent and its newly inserted child:
				if (newNode->isRed) {
					if ((parent->isRed && !uncle) || (parent->isRed && !uncle->isRed)) { // in both cases, uncle is black
						// we perform a left-left rotation	
						current->left = parent->right;
						parent->right = current;
						parent->isRed = false;
						current->isRed = true;

						current = parent;
						return current;
					} else if (parent->isRed && uncle->isRed) { // we need to 'color change'
						recolor(current, parent, uncle);	
						return current;
					}
				}
			} 
			if (current->left->right) { // check the left-right grandchild of current
				node* uncle = current->right;
				node* parent = current->left;
				node* newNode = parent->right; // isRed = true

				if (newNode->isRed) {
					// check the parent of the newNode:
					if ((parent->isRed && !uncle) || (parent->isRed && !uncle->isRed)) { // parent is red, uncle is black
						// preform left-right rotation:
						parent->right = newNode->left;
						current->left = newNode->right;
						newNode->left = parent;
						newNode->right = current;

						newNode->isRed = false;
						current->isRed = true;

						current = newNode;
						return current;

					} else if (parent->isRed && uncle->isRed) { // both parent and uncle are red
						recolor(current, parent, uncle);
						return current;
					}
				}
			}
		}
		else {
			current->right = insert(current->right, data); // go right
			if (current->right->right) { // check right-right grandchild of current
				node* parent = current->right;
				node* uncle = current->left;
				node* newNode = parent->right;

				if (newNode->isRed) {
					if ((parent->isRed && !uncle) || (parent->isRed && !uncle->isRed)) { // must rotate:
						// zig-zig rotation (left rotation)
						current->right = parent->left;
						parent->left = current;
						current->isRed = true;
						parent->isRed = false;

						current = parent;
						return current;	
					} else if (parent->isRed && uncle->isRed) { // color change
						recolor(current, parent, uncle);
						return current;
					}
				}
			} 
			if (current->right->left) { // check right-left grandchild of current
				node* parent = current->right;
				node* uncle = current->left;
				node* newNode = parent->left;

				if (newNode->isRed) {
					if ((parent->isRed && !uncle) || (parent->isRed && !uncle->isRed)) { // right-left rotation
						current->right = newNode->left;
						parent->left = newNode->right;
						newNode->left = current;
						newNode->right = parent;
						newNode->isRed = false;
						current->isRed = true;

						current = newNode;
						return current;
					} else if (parent->isRed && uncle->isRed) { // re-coloring
						recolor(current, parent, uncle);
						return current;
					}
				}
			}
		}
		return current;
	}

	void recolor(node* &grandParent, node* &parent, node* &uncle) {
		// change both parent and uncle of new node to black
		parent->isRed = false;
		uncle->isRed = false;
		// change the grandparent to red (if it is NOT root)
		if (this->root != grandParent)
			grandParent->isRed = true;
	}

	void print() {
		print(root);
	}
	void print(node* current) { // in order traversal (depth-first)
		if (!current) return; // reached the end
		print(current->left); // go left first
		if (current == this->root)
			std::cout << "[ROOT: " << current->data << " isRed: " << current->isRed << "] "; // print
		else
			std::cout << "[" << current->data << " isRed: " << current->isRed << "] "; // print

		print(current->right); // then go right
	}
};

int main() {
	redBlackTree T;
	T.insert(20);
	T.insert(40);
	T.insert(30);
	T.insert(50);
	T.insert(70);
	T.insert(45);
	T.insert(48);
	T.insert(35);

	T.print();
	std::cout << std::endl;

	return 0;
}
