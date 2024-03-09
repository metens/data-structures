public class Node {
	// Hash maps have "key": "value" mappings
	public String key;
	public String value;
	private Node next;

	public Node () { // Default constructor
		this("", ""); // Call the constructor with empty strings
	}

	public Node (String key, String value) { // Node constructor
		this.key = key;
		this.value = value;
		this.next = null; 
	}

	// Setter and getter methods for the next Node link:
	public void setNextNode(Node nextNode) {
		this.next = nextNode;
	}
	public Node getNextNode() {
		return this.next;
	}
}
