// This LinkedList class controlls the Node class and its data.
// The LinkedList class has a head variable that's initialized to null
// in the constructor and has an 'addToTail()' method that
// adds the key/value pair mappings for the hashmap class.
public class LinkedList {
	public Node head; // Head pointer to a Node object

	public LinkedList() {
		this.head = null;
	}

	// Adding a new Node to the end of the list:
	public void addToTail(String key, String value) {
		if (this.head == null) { // There is no list, create a new node
			this.head = new Node(key, value); // Create a new node with key and value data
			return;
		}
		Node current = this.head; // Create a temporary to traverse the list to find the tail (end)
		while (current.getNextNode() != null) {
			current = current.getNextNode(); // Set current to it's next link until null is reached
		}
		current.setNextNode(new Node(key, value)); // Create a new node at the end with key:value data
		return;
	}

	public void printList() { 
		Node current = this.head;
		while (current != null) {
			System.out.println(current.key + current.value);
			current = current.getNextNode();
		}
		return;
	}
}
