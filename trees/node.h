// This is the node class for the binary tree
// which holds the instance data and basic 
// methods for getting that data.

class node {
	private:
		// Binary tree node with left and right pointers:
		int data;
		node* right_ptr;
		node* left_ptr;
	
	public:
		node() : data(0), right_ptr(nullptr), left_ptr(nullptr) {} // Defualt constructor setting all instance data to null

		node(int data) { // Constructor which creates a new node with the parameter data
			this->data = data;
			this->right_ptr = nullptr;
			this->left_ptr = nullptr;
		}
		~node() { // Destructor for each node
			this->data = 0;
			this->right_ptr = nullptr;
			this->left_ptr = nullptr;
		}

		int getData() { // Gets the private data
			return this->data;
		}

		// Gets either the right or left node pointer:
		node*& getRightNode() {
			return this->right_ptr;
		}
		node*& getLeftNode() {
			return this->left_ptr;
		}
};
