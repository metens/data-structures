// This is the List class which handles the Nodes. There is a constructor,
// adding methods, removing methods, and a printing method.

public class List {

	public Node head;

	public List() { // the constructor sets the head to null
		this.head = null;
	}

 // Adding a new node with data to the front of the list
	public void addToHead(int data) {
		Node newHead = new Node(data); // create a new node to be the front of the list
		Node currentHead = this.head; // a temporary pointer to not lose the rest of the list
		this.head = newHead;
		if (currentHead != null) {
			this.head.setNextNode(currentHead);
		}
	}

// Adding Node at the end of the list
	public void addToTail(int data) {
		Node tail = this.head; // setting a temp to the head
		if (tail == null) {
			this.head = new Node(data); // if tail is null, there are no nodes, make one here
		} else {
			while (tail.getNextNode() != null) { // traverse the list until we reach null
				tail = tail.getNextNode();
			}
			tail.setNextNode(new Node(data)); // create a new node at the end
		}
	}  

	// Removing the first node 
	public void removeHead() {
		if (this.head == null) {
			return; // nothing to remove
		}
		this.head = this.head.getNextNode(); // set head to the next node
	}

	// Print all data in the list
	public void printList() {
		Node currentNode = this.head; // temporary Node pointer to traverse the list
		while (currentNode != null) {
			System.out.print(currentNode.getData() + " ");
			currentNode = currentNode.getNextNode();
		}
		System.out.println(); // new line once all node data is printed
	}  

 // This is main, where we create a list and manipulate it:
	public static void main(String []args) {
	
		List myList = new List(); // create a List object

	// Add new Nodes to the front:
		myList.addToHead(5);
		myList.addToHead(9);
		myList.addToHead(4);
		myList.printList();

	// Add new Nodes at the end:
		myList.addToTail(6);
		myList.addToTail(2);
		myList.addToTail(1);
		myList.printList();

	// Remove a couple Nodes:
		myList.removeHead();
		myList.removeHead();
		myList.printList();
	}

}
