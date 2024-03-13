// This is the node class for the minHeap.
// It has integer data, left and right pointers
// to its children, constructors, and basic
// getter methods.

class node {
	private:
		// Nodes have integer data
		// and pointers to the left
		// and right nodes in the heap:
		int value;
		node* right;
		node* left;

	public:
		// Constructors:
		node() : value(0), right(nullptr), left(nullptr) {}
		node(int value = 0) {
			this->value = value;
			this->right = nullptr;
			this->left = nullptr;
		}

		// Destructor:
		~node() {
			this->value = 0;
			this->right = nullptr;
			this->left = nullptr;
		}

		// Getters for the private data:
		int getValue() { return this->value; }
		node* getRight() { return this->right; }
		node* getLeft() { return this->left; }

		// Setters for the private data:
		void setValue(int value) { this->value = value; }
		void setRight(node* &right) { this->right = right; }
		void setLeft(node* &left) { this->left = left; }
};
