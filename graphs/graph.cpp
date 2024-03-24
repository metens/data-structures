#include <iostream>
#include <queue>

class node {
	public:
		int data;
		node* next;

		node() : data(0), next(nullptr) {}
		node(int data = 0) : data(data), next(nullptr) {}
};

class graph {
	public:
		node** adjacencyList;
		int size;

		graph() {
			adjacencyList = nullptr;
		}
		graph(int size) {
			this->size = size + 1; // adding one to the size because we are starting at index 1 instead of 0
			adjacencyList = new node*[this->size];

			for (int i = 0; i < this->size; i ++) { // initialize the adjacencyList to null values
				adjacencyList[i] = nullptr; 
			}
		}

		void insertEdge(int vertex1, int vertex2) {
			if (!adjacencyList) return; // no adj list
			// add the edges to the adj list:
			insertEdge(adjacencyList[vertex1], vertex2);
			insertEdge(adjacencyList[vertex2], vertex1);
		}
		void insertEdge(node* &currentEdge, int adjVertex) { // traverse the curr list in the adj array
			if (!currentEdge) {
				currentEdge = new node(adjVertex); // add the adjacent edge to the adj list
				return;
			}
			insertEdge(currentEdge->next, adjVertex); // recursively traverse the curr list
		}

		void BFS(int vertex) { // prints all the edges in the adjacencyList breadth-first
			BFS(adjacencyList[vertex], vertex); // start BFS from input vertex
		}
		void BFS(node* &startVertex, int vertex) {
			std::queue<int> q; // create a queue to store verticies
			int visited[this->size];
			for (int i=0; i <this->size; i++) { // assign all verticies as unvisited (0)
				visited[i] = 0;
			}

			q.push(vertex); // push the starting vertex
			std::cout << vertex << " ";
			visited[vertex] = 1; // visited currentIndex

			while(!q.empty()) {
				node* curr = adjacencyList[q.front()]; // get the next node (vertex) in the adj list
				q.pop(); // remove the current vertex from the q
				while (curr) { // while the current adj list node is not null
					if (visited[curr->data] == 0) { // vertex not visited:
						std::cout << curr->data << " ";
						q.push(curr->data);
						visited[curr->data] = 1; // set current vertex to visited
					}
					curr = curr->next; // traverse to the next vertex
				}
			}
		}
	
};

int main() {
	graph myGraph(5); // five verticies
	myGraph.insertEdge(1, 2);
	myGraph.insertEdge(2, 3);
	myGraph.insertEdge(2, 4);
	myGraph.insertEdge(3, 4);

	myGraph.BFS(1); // start at vertex 1
	std::cout << std::endl;
	myGraph.BFS(2); // start at vertex 2
	std::cout << std::endl;
	myGraph.BFS(3); // start at vertex 3
	std::cout << std::endl;
	myGraph.BFS(4); // start at vertex 4
	std::cout << std::endl;

	return 0;
}
