public class DoublyLinkedList {
	private Node head; // The pointer to the head of the list
	private Node tail; // The pointer to the tail of the list

	// Default constructor setting the links to null:
	public DoublyLinkedList() {
		this.head = null;
		this.tail = null;
	}

	// Add a new Node to the head of the list:
	public void addToHead(int data) {
		if (this.head == null) { // There is no list so create a new Node
			this.head = new Node(data);	
			this.tail = this.head; // The tail and the head are the same
		} else { // There is a list
			Node newHead = new Node(data);
			newHead.setNext(this.head); // Connect the new node to the list
			this.head.setPrevious(newHead); // Connect the head to the newHead
			this.head = newHead; // The head of the list is newly established	
		}
	}	
	// Add a new Node to the tail of the list:
	public void addToTail(int data) {
		if (this.tail == null) { // Check if there is a list
			this.tail = new Node(data); // If no list, create a new Node
			this.head = this.tail; // And set both head and tail equal to it	
		} else {
			Node newTail = new Node(data);
			newTail.setPrevious(this.tail); // Connect the new tail's link to the previous tail		
			this.tail.setNext(newTail); // Link the previous tail to the new tail
			this.tail = newTail; // Set the List's tail to the new Node at the end of the list
		}
	}

	// Printing all the data in each node starting from the Head:
	public void printList() {
		if (this.head == null) return; // No list, nothing to print	
		Node currentHead = this.head; // Set a temporary head to traverse the list	
		while (currentHead != null) { // Traverse the list, and print all Node data
			System.out.print(currentHead.getData() + " ");
			currentHead = currentHead.getNextNode();
		}
	}

	public static void main(String args[]) {
		
		DoublyLinkedList myList = new DoublyLinkedList(); // Create a new List

	// Add Nodes to the head of the list:
		myList.addToHead(10);	
		myList.addToHead(7);	
		myList.addToHead(11);	
		myList.printList();

		System.out.println(); // New Line

	// Add Nodes to the tail:
		myList.addToTail(8);
		myList.addToTail(5);
		myList.addToTail(2);
		myList.printList();
		
		System.out.println(); // New Line
	}
}
