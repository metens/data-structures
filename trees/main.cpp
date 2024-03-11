// This is the main program that creates the binary tree.
// The tree can add nodes, and print all the nodes contained
// in the tree in order.

#include "tree.h"
using namespace std;

int main() {

	tree myTree; // Create an object of the tree class

	// Add nodes of random integer data:
	myTree.addNode(5);
	myTree.addNode(8);
	myTree.addNode(2);
	myTree.addNode(15);
	myTree.addNode(6);
	myTree.addNode(1);
	myTree.addNode(10);
	myTree.addNode(7);

	// Print the integer data in order from smallest to largest:
	myTree.print();

	return 0;
}
