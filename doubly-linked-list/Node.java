
/* This is a Node class for doublt linked lists that has 
 data (an integer), a link to the next
 node, and the link to a previous node. The methods
 are for setting and getting the data as well as the
 next and previous links. */

public class Node {
        private int data;
        // Next and previous links (pointers):
        private Node next;
        private Node previous;

        // Default constructor setting all data to null:
        public Node() {
                this.data = 0;
                this.next = null;
                this.previous = null;
        }

        // Create a new Node with data:
        public Node(int data) {
                this.data = data;
                this.next = null;
                this.previous = null;
        }

        // Setting the Node links:
        public void setNext(Node nextNode) {
                this.next = nextNode;
        }
        public void setPrevious(Node previousNode) {
                this.previous = previousNode;
        }

        // Getting the data and links:
        public int getData() {
                return this.data;
        }
        public Node getNextNode() {
                return this.next;
        }
        public Node getPreviousNode() {
                return this.previous;
        }

}
