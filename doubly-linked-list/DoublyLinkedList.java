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

	// Printing all the data in each node starting from the Head:
	public void printList() {
		if (head == null) return; // No list, nothing to print	
		Node currentHead = this.head; // Set a temporary head to traverse the list	
		while (currentHead != null) { // Traverse the list, and print all Node data
			System.out.print(currentHead.getData() + " ");
			currentHead = currentHead.getNextNode();
		}
	}

	public static void main(String args[]) {
		
		DoublyLinkedList myList = new DoublyLinkedList(); // Create a new List
		myList.addToHead(10);	
		myList.addToHead(7);	
		myList.addToHead(11);	
		myList.printList();
	}
}
