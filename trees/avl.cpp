#include <iostream>
#include <algorithm>
#include <queue>

class node {
	public:
		int data;
		int height;
		node* left;
		node* right;

		node(int data = 0) : data(data), height(0), left(nullptr), right(nullptr) {}
};

class avl {
	public:
		node* root;

		avl() : root(nullptr) {}

		void print() {
			print(root);
		}
		void print(node* current) {
			if (!current) return;
			print(current->left);
			std::cout << current->data << " ";
			print(current->right);
		}

		void insert(int data) {
			insert(root, data);
		}

		void insert(node* &current, int data) { 
			if (!current) { // base case: no tree, or we reached null
				current = new node(data);
				return; // return the height of the current subtree recursively
			}
			if (data < current->data) insert(current->left, data); // smaller data left
			else insert(current->right, data); // if data is >=, go right
			// update the height at each node:
			if (current->left && current->right)
				current->height = std::max(current->left->height, current->right->height) + 1;
			else if (current->left)
				current->height = current->left->height + 1;
			else if (current->right)
				current->height = current->right->height + 1;
			else current->height = 1;
			// check the balance factor:
			int balanceFactor = getBalanceFactor(current);

			// rebalance if necessary:
			if (balanceFactor > 1) { // we are left-heavy
				// check if we need a right-rotation, or a left-right rotation
				int balanceFactorLeftChild = getBalanceFactor(current->left);
				if (balanceFactorLeftChild >= 1) // we are left-left heavy, so perform right rotation
					rightRotation(current);
				else // we are left-right heavy, so perform left-right rotation
					left_rightRotation(current);
			}
			if (balanceFactor < -1) { // we are right heavy
				// check whether we are right-right heavy or right left heavy
				int balanceFactorRightChild = getBalanceFactor(current->right);
				if (balanceFactorRightChild <= -1) // we are right-right heavy, so perform left rotation
					leftRotation(current);
				else // we are right-left heavy, so perform a right-left rotation
					right_leftRotation(current);

			}
		}

		int getBalanceFactor(node* current) {
			int leftHeight = 0; int rightHeight = 0;
			if (!current->left && current->right) {
			       	leftHeight = -1;
				rightHeight = current->right->height;
			}
			else if (!current->right && current->left) {
				rightHeight = -1;
				leftHeight = current->left->height;
			}
			else if (!current->left && !current->right) {
				leftHeight = -1;
				rightHeight = -1;
			}
			else {
				leftHeight = current->left->height;
				rightHeight = current->right->height;
			}
			int BalanceFactor = leftHeight - rightHeight; 
			return BalanceFactor;
		}

		void rightRotation(node* &A) {
			// A is the parent of B, B is the left child of A
			// rotate the child (B) to the right
			// A becomes the right child of B and A takes it's
			// previous childs right subtree
			node* B = A->left;
			A->left = B->right;
			B->right = A;	
			if (this->root == A) // update the root of the tree
				this->root = B;
		}
		void leftRotation(node* &A) {
			// A is the parent of B, B is the right child of A.
			// left rotate at A such that B becomes the parent
			// of A and A becomes the left child of B.
			// A gets the left subtree of B
			node* B = A->right;
			A->right = B->left;
			B->left = A;
			if (this->root == A) // update the root of the tree
				this->root = B;
		}
		void left_rightRotation(node* &A) {
			node* B = A->left;
			node* C = B->right; // hold onto B's node right subtree
			// C becomes the new root, with B becoming its left subtree
			// and A becoming its right subtree
			B->right = C->left;
			A->left = C->right;
			C->left = B;
			C->right = A;
			if (this->root == A) // update the root of the tree
				this->root = C;
		}
		void right_leftRotation(node* &A) {
			node* B = A->right;
			node* C = B->left; // hold onto B's left subtree
			// C becomes the new root, with A as its left child,
			// and B as its right child. B gets C's right subtree
			// and A gets C's left subtree
			B->left = C->right;
			A->right = C->left;
			C->left = A;
			C->right = B;
			if (this->root == A) // update the root of the tree
				this->root = C;
		}

		void printBreadthFirst() {
			if (!root) return; // check if we have a tree
			std::queue<node*> q; // create a queue
			q.push(root);
			printBreadthFirst(q);
		}
		void printBreadthFirst(std::queue<node*> q) {
			if (q.empty()) return; // visited each node 
			node* current = q.front(); // grab the node at the front of the queue
			q.pop(); // dequeue the current node we are on

			std::cout << current->data << " ";
			
			// check current node's children. push them onto the queue if they exist
			if (current->left) q.push(current->left);
			if (current->right) q.push(current->right);
			printBreadthFirst(q);
		}
};

int main() {

	std::cout << "Examples of each rotation case in AVL trees (printed breadth-first): " << std::endl;
	std::cout << std::endl;

	// left-rotation
	std::cout << "Tree before 'Left-Rotation': (nodes added in this order) 10 20 30";
	std::cout << std::endl;

	avl Tleft;
	Tleft.insert(10);
	Tleft.insert(20);
	Tleft.insert(30);

	std::cout << "Tree after rotation: ";
	Tleft.printBreadthFirst();
	std::cout << std::endl;
	std::cout << std::endl;

	// right-rotation
	std::cout << "Tree before 'Right-Rotation': (nodes added in this order) 30 20 10";

	avl Tright;
	Tright.insert(30);
	Tright.insert(20);
	Tright.insert(10);
	std::cout << std::endl;

	std::cout << "Tree after 'Right-Rotation': ";
	Tright.printBreadthFirst();
	std::cout << std::endl;
	std::cout << std::endl;

	// left-right rotation
	std::cout << "Tree before 'Left-Right-Rotation': (nodes added in this order) 30 10 20";

	avl Tleft_right;
	Tleft_right.insert(30);
	Tleft_right.insert(10);
	Tleft_right.insert(20);
	std::cout << std::endl;

	std::cout << "Tree after 'Left-Right-Rotation': ";
	Tleft_right.printBreadthFirst();
	std::cout << std::endl;
	std::cout << std::endl;

	// right-left rotation
	std::cout << "Tree before 'Right-Left-Rotation': (nodes added in this order) 10 30 20";

	avl Tright_left;
	Tright_left.insert(10);
	Tright_left.insert(30);
	Tright_left.insert(20);
	std::cout << std::endl;

	std::cout << "Tree after 'Right-Left-Rotation': ";
	Tright_left.printBreadthFirst();
	std::cout << std::endl;

	return 0;
}
