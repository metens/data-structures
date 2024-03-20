#include <iostream>
#include <queue>

class node {
	public: 
		int data;
		node* left;
		node* right;

		node(int data = 0) : data(data), left(nullptr), right(nullptr) {} // default constructor
		~node() { data = 0; left = nullptr; right = nullptr; } // destructor, reset all data to default
};

class tree {
	public:
		node* root;
		tree() : root(nullptr) {} // default constructor
		~tree() { removeAll(root); } // remove all nodes in the tree

		void removeAll(node* &root) {
			if (!root) return; // nothing to delete
			removeAll(root->left); // travel all the way left first
			removeAll(root->right); // repeat on the right;
			delete root; // delete every node
			root = nullptr;
		}

		// adding a node with data
		void addNode(node* &current, int data) {
			if (!current) { // reached null
				current = new node(data);
				return;
			}
			if (data >= current->data) addNode(current->right, data); // go right if data is larger
			else addNode(current->left, data); // go left if data is smaller

		}
		void addNode(int data) { // wrapper for recursive addNode
			return addNode(root, data);
		}

		// adding a node pointer
		void addNode(node* &current, node* newNode) { // newNode could also be an entire subtree
			if (!newNode) return; // nothing to add
			if (!current) { // if null, add new node here
				current = newNode;
				return;
			}
			if (newNode->data >= current->data) addNode(current->right, newNode);
			else addNode(current->left, newNode); // if data at newNode is smaller than current data, traverse left
		}

		void removeNode(node* &current, int data) {
			if (!current) return; // nothing to remove 
			if (data == current->data) { 
				node* rightSubtree = current->right; // hold onto right subtree (could be null)
				node* leftSubtree = current->left; // hold onto left subtree (could be null);
				delete current; // remove the node with the matching data
				current = rightSubtree; // current becomes the right subtree
				return addNode(current, leftSubtree); // add the left subtree to the new current
			}
			if (data > current->data) removeNode(current->right, data);
			else removeNode(current->left, data);
		}
		void removeNode(int data) { // wrapper for recursive method
			removeNode(root, data);
		}

		void print() { // prints tree using depth-first-traversal (i.e. in-order traversal)
			print(root);
		}
		void print(node* current) { 
			if (!current) return;
			print(current->left); // traverse all the way left
			std::cout << current->data << " "; // print data
			print(current->right); // then repeat going right 
		}

		void printPreOrder() { // pre-order traversal
			printPreOrder(root);	
		}
		void printPreOrder(node* current) {
			if (!current) return;
			std::cout << current->data << " "; // visit the root first
			printPreOrder(current->left); // then left
			printPreOrder(current->right); // then right
		}

		void printPostOrder() { // post-order traversal
			printPostOrder(root);
		}
		void printPostOrder(node* current) {
			if (!current) return;
			printPostOrder(current->left);
			printPostOrder(current->right);
			std::cout << current->data << " ";
		}

		void breadthFirstPrint() {
			if (!root) return; // no tree
			std::queue<node*> q; // initialize a queue
			q.push(root); // push the root node into the queue 

			node* current = nullptr;
			while (!q.empty()) { // print the front of the queue until its empty and wev'e traversed the tree:
				current = q.front(); // current is the front of the queue
				std::cout << current->data << " ";
				q.pop(); // remove the front node
				// check if the left & right child exists before pushing them into the queue
				if (current->left) q.push(current->left); 
				if (current->right) q.push(current->right);
			}
		}
};

int main() {
	tree T;

	int data[] = {5, 8, 3, 11, 12, 7, 6, '\0'};
	int length = 0;
	while (data[length] != '\0') { // get length of array
		length++;
	}

	std::cout << "Length of data array: " << length << std::endl;

	int root = 10;
	T.addNode(root);

	for (int i = 0; i < length; i++) { // add all data from array
		T.addNode(data[i]); 
	}

	std::cout << "Depth-first (in-order) traversal: ";
	T.print(); std::cout << std::endl;

	std::cout << "Breadth-first traversal: ";
	T.breadthFirstPrint(); std::cout << std::endl;

	std::cout << "Pre-order traversal: ";
	T.printPreOrder(); std::cout << std::endl;

	std::cout << "Post-order traversal: ";
	T.printPostOrder(); std::cout << std::endl; 

	/*
	   T.removeNode(3);
	   T.print(); std::cout << std::endl;

	   T.removeNode(11);
	   T.print(); std::cout << std::endl;

	   T.removeNode(6);
	   T.print(); std::cout << std::endl;

	   T.removeNode(10); // remove the root
	   T.print(); std::cout << std::endl;
	   */
	return 0;
}
