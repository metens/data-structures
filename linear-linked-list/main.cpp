// This is the main program that interacts with the user...

#include "lll.h"
#include "iostream"

int main() {
	lll list;	// Create an object of the lll class called "list"

	// Make the list by adding at the end
	std::cout << "Make the list:\n";
	list.add_at_end(5);
	list.add_at_end(3);
	list.add_at_end(7);
	list.add_at_end(4);
	list.add_at_end(1);
	list.add_at_end(6);
	list.add_at_end(5);

	// Print it forwards
	list.print();

	std::cout << "\n\n";

	// Print it backwards
	std::cout << "Print it backwards:\n";
	list.print_in_reverse();

	std::cout << "\n\n";

	// Counting the items
	int list_length = list.count_items();
	std::cout << "There are " << list_length << " nodes in the list." << "\n";
	
	// Summing the list
	int sum = list.sum_list();
	std::cout << "The sum of the list is:  " << sum << "\n";

	// Order the list
	std::cout << "Order the list:\n";
	list.order_list();
	list.print();
	
	std::cout << "\n\n";

	// Delete odd nodes
	std::cout << "Delete odd value nodes:\n";
	list.delete_odd_or_even("odd");
	list.print();

	std::cout << "\n\n";

	// Add items to the front
	std::cout << "Add values to front nodes:\n";
	list.add_at_front(10);
	list.add_at_front(5);
	list.add_at_front(9);
	list.add_at_front(12);
	list.add_at_front(11);
	list.add_at_front(8);
	list.print();
	
	std::cout << "\n\n";

	// Delete even nodes
	std::cout << "Delete even valued nodes:\n";
	list.delete_odd_or_even("even");
	list.print();

	std::cout << "\n\n";
	// Order the list
	std::cout << "Order the list:\n";
	list.order_list();
	list.print();
	
	return 0;
}
