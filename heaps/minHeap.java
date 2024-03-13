// This minHeap class is implemented as a priority queue.
// But the conceptualization is of a binary tree (each node 
// having no more than two children).
//
// For efiiciencies case, the minHeap will be implemented
// using an ArrayList of Integer values.
//
// The smallest node value will always be at the root of the
// binary tree. All children will ALWAYS be larger than their
// parent node.
//
// The locations of any child or parent node can be found
// using the index derived from codeCademy:
//
// left Child: (index * 2) + 1
// right child: (index * 2) +2
// parent: floor [(index + 1) / 2]
//
// This minHeap class will be able to add nodes and also 
// remove nodes. When adding to the tree, if the parent
// is larger than the newlay added node, we will heapify up
// to restore order. Conversly, when we remove the root,
// we may have to heapify down since we will be swapping
// the smallest node with the largest node before removing.

import java.util.ArrayList; // Importing the ArrayList class
import java.lang.Math; // For the parentIndex calculation above
import java.util.Collections; // For swapping elements in the ArrayList

public class minHeap {
	public ArrayList<Integer> heap;
	public int size;

	public minHeap() {
		this.heap = new ArrayList<Integer>();
		this.heap.add(null); // The zeroth index will be 0, so
												 // that we can have the 'root' be at 
												 // index 1 in the list (tree).
		this.size = 0; // How many nodes we have in our 'tree'
	}

	public void add(int value) { // Method for adding to heap
		this.heap.add(value); // Adds the value to the end, or
													// at the bottom of the tree.
		System.out.println("Value " + value + " added to minHeap: " + this.heap);
		this.size++; // Increment the size
		this.heapifyUp(); // Making any adjustments if necessary
	}

	private void heapifyUp() { // Checks if all nodes are in order
														 // and makes swaps if any parent is
														 // larger than its child.
		int current = this.size; // The current index of our node
		while (current > 1 && this.heap.get(current) < this.heap.get(this.getParent(current))) {
				System.out.println("Swap parent at index " + this.getParent(current) + " with value " 
						+ this.heap.get(this.getParent(current)) + " and child at index " + current 
						+ " with value " + this.heap.get(current));
				Collections.swap(this.heap, this.getParent(current), current); // Swap the parent (larger)
																																			 // with the child (smaller)
				System.out.println(this.heap); // Show heapifiedUp 'tree'
				current--; // New location in the tree
		}
	}

	// left Child: (index * 2) + 1
	// right child: (index * 2) +2
	// parent: floor [(index + 1) / 2]
	// Since our arrayList starts at index 1, we can subtract one from each equation above:
	private int getLeft(int currentIndex) { // Gets the index of the left child
																					// of our current node at currentIndex
		return (currentIndex * 2);
	}
	private int getRight(int currentIndex) {
		return (currentIndex * 2) + 1;
	}
	private int getParent(int currentIndex) { // Gets the index of the parent node
																						// given the index or our current node
		return (int) Math.floor((currentIndex) / 2);
	}

	public static void main(String[] args) {
		minHeap myHeap = new minHeap();

		myHeap.add(5);
		myHeap.add(8);
		myHeap.add(1);
		myHeap.add(11);
		myHeap.add(4);
		myHeap.add(7);
	}
}
