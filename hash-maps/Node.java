// This Node class holds two String variables: key and value. The key maps to the value.
// The class also contains two constructors and methods for setting/getting the link to the
// next node, as well as a setter for the data.
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

	// Setter for the Node data:
	public void setData(String key, String value) {
		this.key = key;
		this.value = value;
	}

	// Setter and getter methods for the next Node link:
	public void setNextNode(Node nextNode) {
		this.next = nextNode;
	}
	public Node getNextNode() {
		return this.next;
	}
}
