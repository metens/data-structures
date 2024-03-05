#include "cll.cpp"

int main() {
	cll myList;

	// Add to the list:
	myList.addNode(2);
	myList.addNode(4);
	myList.addNode(7);

	myList.printList();
	std::cout << "\n"; // New Line

	return 0;
}
