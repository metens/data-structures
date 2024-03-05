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

	// Removing at the head:
	public void removeHead() {
		if (this.head == null) { // No list
			return;
		} else if (this.head.getNextNode() == null) { // There is only one Node in the list, make both links null
			this.head = null;
			this.tail = null;
		} else { // The list is longer than one Node
			Node headToRemove = this.head; // Set a temp to the head we will remove from the list
			this.head = this.head.getNextNode(); // Set the current head to the next node in the list
			headToRemove.setNext(null); // Isolate the head to be removed from the rest of the list
			this.head.setPrevious(null); // Make the list's new head previous link to null (cutting off access to the original head
		}
	}
	// Remove at the tail:
	public void removeTail() {
		if (this.tail == null) return; // No list, nothing to remove
		else if (this.tail.getPreviousNode() == null) {
			this.tail = null; this.head = null; // There is only the one Node, so set links to null to remove it
		}	else {
			Node tailToRemove = this.tail; // Set a temp to the tail
			this.tail = this.tail.getPreviousNode(); // Set the tail equal to its previous Node	
			tailToRemove.setPrevious(null); // Isolate the tail to be removed
			this.tail.setNext(null); // Remove the link to the tail to remove
		}
	}
	// Remove any node in the list:
	public void removeNode(int data) {
		if (this.head == null) return; // Nothing to remove since there is no list
		Node currentHead = this.head; // Set a temp to the list's head
		while (currentHead != null) { // traverse the list with the temp until we reach the end
			if (currentHead.getData() == data) { // We found the matching Node
				// We need to isolate the Node by connecting it's next and previous linked Nodes to one another
				Node previousNode = currentHead.getPreviousNode();
				Node nextNode = currentHead.getNextNode();

				previousNode.setNext(currentHead.getNextNode());
				nextNode.setPrevious(currentHead.getPreviousNode());
			// Isolate the currentHead:
				currentHead.setNext(null);
				currentHead.setPrevious(null);
				return;
			}
			currentHead = currentHead.getNextNode(); // Set the temp to the next linked node
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

		// Removing linked Nodes at the front of the list
		myList.removeHead();
		myList.removeHead();
		myList.printList();

		System.out.println(); // New Line

		// Removing linked Nodes at the tail of the list
		myList.removeTail();
		myList.removeTail();
		myList.printList();

		System.out.println(); // New Line
		
		// Adding a few more Nodes:
		myList.addToTail(6);
		myList.addToHead(11);
		myList.printList();

		System.out.println(); // New Line
	
		// Removing a node from the middle
		myList.removeNode(8);
		myList.printList();

		System.out.println(); // New Line
	}
}
