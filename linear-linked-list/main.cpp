// This is the main program that interacts with the user...

#include "lll.h"
#include "iostream"

int main() {
	lll list;	// Create an object of the lll class called "list"

	// Make the list
	list.add_at_end(5);
	list.add_at_end(3);
	list.add_at_end(7);
	list.add_at_end(4);
	list.add_at_end(1);
	list.add_at_end(6);
	list.add_at_end(5);

	// Print it forwards
	list.print();

	std::cout << "\n";

	// Print it backwards
	list.print_in_reverse();

	std::cout << "\n";

	// Counting the items
	int list_length = list.count_items();
	std::cout << "There are " << list_length << " nodes in the list." << "\n";
	
	// Summing the list
	int sum = list.sum_list();
	std::cout << "The sum of the list is:  " << sum << "\n";

	// Order the list
	list.order_list();
	list.print();
	
	std::cout << "\n";
	
	return 0;
}
