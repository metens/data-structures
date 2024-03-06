#include "cll.cpp"

int main() {
	cll myList;

	// Add to the list:
	myList.addNode(1);
	myList.addNode(2);
	myList.addNode(3);
	myList.addNode(4);
	myList.addNode(5);
	myList.addNode(6);
	myList.addNode(7);
	myList.addNode(8);

	myList.printList();
	std::cout << "\n"; // New Line

	// Remove a node:
	myList.removeNode(1);
	myList.removeNode(6);
	myList.removeNode(8);
	myList.removeNode(4);
	myList.removeNode(5);

	myList.printList();
	std::cout << "\n"; // New Line

	return 0;
}
