// This is the HashMap class. It contains an array of linked lists
// with an initialized 'maxSize' of indicies. The class contains two
// constructos, the default calls the paramaterized one if no 'maxSize'
// is givin. The class contains a hash function with returns a hashcode
// for the given key. It also contains an 'assign()' method to insert a key/value
// pair, as well as a 'retrieve()' method to find the value for a given key.
// The main method uses the HashMap class to map the keys (NBA players) to their
// values (NBA teams);

// Import the String codePointAt() Method for the hash function:
import java.io.*;

public class HashMap {
	public LinkedList[] hashmap; // The hashmap is an array of linkedlists
	public int maxSize; // The maximum size of our hash table (array)

	public HashMap() {
		// Defualt constructor will call the second constructor with an unbounded size if no size is specified:
		this(Integer.MAX_VALUE);
	}

	// Constructor with argument maxSize
	public HashMap(int maxSize) {
		this.maxSize = maxSize;
		this.hashmap = new LinkedList[maxSize]; // All the indicies at each array index are assigned null
		for (int i = 0; i < this.maxSize; i++) {
			this.hashmap[i] = new LinkedList(); // Assign a head to a linked list at each array index in our hash table
		}
	}

	// The hash function witch returns an array index to put the given key:value pair
	public int hash(String key) { 
		int hashCode = 0; // Instantiate a hash code
		for (int i = 0; i < key.length(); i++) {
			hashCode += key.codePointAt(i); // Incrementing the Unicode value of each character in the key String
		}
		int hashIndex = hashCode % this.maxSize; // MODULO of the hashCode with the maxSize of our array will give us an index to map the data
		return hashIndex;
	}

	public void assign(String key, String value) { // Assign a key:value pair to the hash table
		int index = this.hash(key); // Get the arrayIndex we will store the key at using the hash function
		if (this.hashmap[index].head == null) { // Check if there is a spot at the index to map our data
			this.hashmap[index].addToTail(key, value); // Create a new node at the index
			System.out.println("key: '" + key + "', value: '" + value + "' added at index: '" + index + "'.");
			return;
		}
		Node current = this.hashmap[index].head; // Set the current temporary variable to the array index head pointer
		while (current.getNextNode() != null) {
			// Check if there is a reassignment of the key
			if (current.key == key){ // No new node is needed
				current.value = value; // Reassign the new value
				return;
			}
			// Traverse the list at the array index to add new hash data
			current = current.getNextNode();
		}
		current.setNextNode(new Node(key, value)); // Create a new node at the end of the list
		System.out.println("key: '" + key + "', value: '" + value + "' added at index: '" + index + "'.");
		return;
	}

	public String retrieve(String key) { // Searches the hash table for the key and returns the value
		int index = this.hash(key); // Get the index where the key is located
		Node current = this.hashmap[index].head;
		try { // Searching for a key:

			while (current != null) { // Traverse the list at the array index to find the key
				if (current.key == key) { // Check each node in the list
					System.out.println("\n'" + key + "' plays for the '" + current.value + "'.");
					return current.value;
				}
				current = current.getNextNode();
			}
			throw new Error(key); // If the key was not found, throw an error
		} catch (Error e) {
			System.out.println("\n'" + key + "' does not play in the NBA.");
			return "";
		}
	}

	public static void main(String[] args) {

		// This hash table uses separate chaining to handle collisions of keys hashed at the same index.
		HashMap playerTeamsNBA = new HashMap(3); // A hash table of static size 3 mapping players to their NBA team

		// Assign keys: 'NBA players' to their respective value: 'Teams' in the hash table:
		playerTeamsNBA.assign("Stephen Curry", "Golden State Warriors");
		playerTeamsNBA.assign("LeBron James", "Los Angeles Lakers");
		playerTeamsNBA.assign("Luka Doncic", "Dallas Mavericks");
		playerTeamsNBA.assign("Damian Lillard", "Milwuakee Bucks");
		playerTeamsNBA.assign("Kevin Durant", "Pheonix Suns");
		playerTeamsNBA.assign("James Harden", "Los Angeles Clippers");
		playerTeamsNBA.assign("Tim Duncan", "San Antonio Spurs");
		playerTeamsNBA.assign("Michael Jordan", "Chicago Bulls");

		// Retreive the team of a given NBA player:
		String NBAplayer1 = "Damian Lillard";
		String NBAteam1 = playerTeamsNBA.retrieve(NBAplayer1);

		String NBAplayer2 = "Michael Jordan";
		String NBAteam2 = playerTeamsNBA.retrieve(NBAplayer2);

		String NBAplayer3 = "Kevin Durant";
		String NBAteam3 = playerTeamsNBA.retrieve(NBAplayer3);

		// Check for a player that doesn't play in the NBA:
		String nonNBAplayer = "Nathan Metens";
		String NBAteam = playerTeamsNBA.retrieve(nonNBAplayer);
	}
}
