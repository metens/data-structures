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
	list.add_at_end(100);
	list.add_at_end(15);

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
	std::cout << "The sum of the list is:  " << sum;
	
	std::cout << "\n";
	
	return 0;
}
