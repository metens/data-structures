#include "minHeap.h"

int main() {
	minHeap heap;

	heap.add(3);
	heap.add(5);
	heap.add(2);
	heap.add(6);
	heap.add(4);
	heap.add(1);

	cout << "Depth first: " << endl;
	heap.depthFirstPrint();
	cout << endl;

	cout << "Breadth first: " << endl;
	heap.breadthFirstPrint();
	cout << endl;

	return 0;
}
