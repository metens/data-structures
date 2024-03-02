// This is the main program that interacts with the user...

#include "lll.h"
#include "iostream"

int main() {
	lll list;	// Create an object of the lll class called "list"

	// Make the list
	list.add_at_end(10);
	list.add_at_end(20);
	list.add_at_end(50);
	list.add_at_end(80);
	list.add_at_end(95);

	// Print it forwards
	list.print();

	std::cout << "\n";

	// Print it backwards
	list.print_in_reverse();

	std::cout << "\n";
	
	return 0;
}
