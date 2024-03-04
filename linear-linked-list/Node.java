// This is the Node class that has an integer as data and a 
// pointer to another Node. The methods of this class consist
// of a constructor that initializes the data to a given number
// and the next pointer to null. To keep the class data private,
// we have a setter method that sets the next pointer to a 
// given Node, and a getter method that returns the value of 
// the next pointer.

public class Node { 

 // only accessible in this class
  private int data;
  private Node next; 

  public Node(int data) { // Node constructor
    this.data = data;
    this.next = null;
  }

 // setter and getter methods to handle the Node data
  public void setNextNode(Node node) {
    this.next = node;
  }

  public Node getNextNode() {
    return this.next;
  }
	
	public int getData() {
		return this.data;
	}

}
