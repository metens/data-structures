#include <iostream>

struct node {
	int k1, k2;
	node *left, *mid, *right;
	int height;
	bool hasSpace;
	
	node(int k1=-1): k1(k1), k2(-1), left(nullptr), mid(nullptr), right(nullptr), height(0), hasSpace(true) {}
};

struct tree {
	node* root;

	tree() : root(nullptr) {}

	void insert(int data) {
		insert(root, data);
		
	} 
	void insert(node* &current, int data) {
		if (!current) 
			current = new node(data);
		else if (current->height == 0) { // leaf node
			if (current->hasSpace)
				insertAtLeaf(current, data);
			else // no space, so split
				splitLeafNode(current, data);
		} else {
			if (data < current->k1) {
				insert(current->left, data);
				if (current->left->height == current->height) // check if the left pointer is a split parent
					mergeNode(current, current->left);
			} else if (((current->k1 <= data && current->k2 == -1) && current->hasSpace) || (current->k1 <= data && data < current->k2)) {
				insert(current->mid, data);
				if (current->mid->height == current->height) // check split parent height
					mergeNode(current, current->mid);
			} else { // current->k2 < data
				insert(current->right, data);
				if (current->right->height == current->height)
					mergeNode(current, current->right);
			}
		}
	}

	void mergeNode(node* &current, node* child) { // current by reference, child by copy
		if (child->k1 < current->k1) {
			if (current->hasSpace) {
				// merge the values of child and parent:
				current->k2 = current->k1;
				current->k1 = child->k1;
				current->hasSpace = false;

				// update parent pointers: (must be in this order...)
				current->left = child->left;
				current->right = current->mid;
				current->mid = child->mid;
			} else { // current has no space for the upcoming node

			}
		} else if (current->k1 <= child->k1) {
			if (current->hasSpace) {
				// merge the two nodes:
				current->k2 = child->k1;
				current->hasSpace = false;

				// update parent pointers:
				current->mid = child->left;	
				current->right = child->mid;
			} else {

			}
		} else { // current->k2 < child->k1

		}
	}
	
	void splitLeafNode(node* &current, int data) {
		if (data < current->k1) {
			// create a new left and mid node:
			node* leftNode = new node(data);
			node* midNode = new node(current->k2);

			// update current data:
			current->k2 = -1;
			current->height++;
			current->hasSpace = true;

			// update current pointers:
			current->left = leftNode;
			current->mid = midNode;
		} else if (current->k1 <= data && data <= current->k2) {
			// create new parentNode and mid:
			node* parentNode = new node(data);
			node* midNode = new node(current->k2);

			// update current:
			current->k2 = -1;
			current->hasSpace = true;

			// update parent pointers and data:
			parentNode->left = current;
			parentNode->mid = midNode;
			parentNode->height++;

			// update current to be parent
			current = parentNode;
		} else { // current->k2 < data
			// create a new parent and mid:
			node* parentNode = new node(current->k2);
			node* midNode = new node(data);

			// update current data:
			current->k2 = -1;
			current->hasSpace = true;

			// update parentNode pointers and data:
			parentNode->left = current;
			parentNode->mid = midNode;
			parentNode->height++;

			// update current to become parent
			current = parentNode;
		}
	}

	void insertAtLeaf(node* &current, int data) {
		if (data < current->k1) { // shift bigger key
			current->k2 = current->k1;
			current->k1 = data;
			current->hasSpace = false;
		} else {// data goes to k2 spot
			current->k2 = data;
			current->hasSpace = false;
		}
	}

	void print() { print(root); }
	void print(node* current) {
		if (!current) return;
		print(current->left);
		std::cout << current->k1 << " ";
		print(current->mid);
		if (current->k2 != -1)
			std::cout << current->k2 << " ";
		print(current->right);
	}
};

int main() {
	
	tree T;
	// ascending order test: [PASSED]
	T.insert(10);
	T.insert(20);
	T.insert(30);
	T.insert(40);
	T.insert(50);
	T.insert(60);
	T.insert(70);
	T.insert(80);
	T.insert(90);
	T.insert(100);
	T.insert(110);
	T.print(); std::cout << std::endl;

	tree T1;
	// descending order test: [PASSED]
	T1.insert(110);
	T1.insert(100);
	T1.insert(90);
	T1.insert(80);
	T1.insert(70);
	T1.insert(60);
	T1.insert(50);
	T1.insert(40);
	T1.insert(30);
	T1.insert(20);
	T1.insert(10);
	T1.print(); std::cout << std::endl;

	tree T2;
	// random order: [PASSED]
	T2.insert(80);
	T2.insert(30);
	T2.insert(20);
	T2.insert(110);
	T2.insert(10);
	T2.insert(90);
	T2.insert(100);
	T2.insert(50);
	T2.insert(60);
	T2.insert(40);
	T2.insert(70);
	T2.print(); std::cout << std::endl;

	tree T3;
	// random order with duplicates: [PASSED]
	T3.insert(60);
	T3.insert(10);
	T3.insert(110);
	T3.insert(90);
	T3.insert(100);
	T3.insert(10);
	T3.insert(70);
	T3.insert(40);
	T3.insert(90);
	T3.insert(20);
	T3.insert(30);
	T3.insert(50);
	T3.insert(100);
	T3.insert(40);
	T3.insert(80);
	T3.insert(60);
	T3.insert(100);
	T3.insert(80);
	T3.print(); std::cout << std::endl;

	return 0;
}
