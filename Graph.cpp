#include<string>
#include<iostream>
#include<vector>
#include<queue>

struct Node {
	int 	value;
	bool	visited;
	std::vector<int> edges;
	Node (int _value) : visited(false) {
		value = _value;
	}
};

class Graph {
	std::vector<Node*> v;
	int size;
public:
	Graph (int value);
	void add_vertex (int value);
	void add_edge (int index_a, int index_b);
	void print_graph ();
	void transverse_graph_from (int i);
};

Graph::Graph (int value) : size(1) {
	this->v.push_back (new Node (value));
	std::cout << "Created a vertex with value " << this->v.at (0)->value << std::endl;
}

void Graph::add_vertex (int value) {
	this->v.push_back (new Node (value));
	++this->size;
	std::cout << "Created a vertex with value " << this->v.at (this->v.size ()-1)->value << std::endl;
}

void Graph::add_edge (int index_a, int index_b) {
	Node* n = this->v.at (index_b);
	this->v.at (index_a)->edges.push_back (n->value);
}

void Graph::print_graph () {
	for (int i = 0; i < this->v.size (); ++i) {
		std::cout << "At vertex " << this->v.at (i)-> value << ": ";
		for (int j = 0; j < this->v.at (i)->edges.size (); ++j) {
			std::cout << " " << this->v.at (i)->edges.at (j) << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::transverse_graph_from (int i) {
	std::queue<Node*> q;
	Node* current;
	Node* temp;
	q.push (this->v.at (i));	// start transversal from index i
	while (!(q.empty ())) {	
		current = q.front ();	// pop the first node from the queue
		q.pop ();
		if (!(current->visited == true)) {
			current->visited = true;			// set the current node as visited
			for (int j = 0; j < current->edges.size (); ++j) {
				temp = this->v.at (current->edges.at (j) - 1);	// get the adjacent node
				if (!(temp->visited)) 
					q.push (temp);				// push the node to the back of queue if it is not visited
			}
			std::cout << "Visited vertex at " << current->value << std::endl;
		}
	}
}

int main () {
	Graph* g = new Graph (1);
	g->add_vertex (2);
	g->add_vertex (3);
	g->add_vertex (4);
	g->add_vertex (5);
	g->add_vertex (6);

	g->add_edge (0, 1);
	g->add_edge (0, 2);
	
	g->add_edge (1, 0);
	g->add_edge (1, 2);
	g->add_edge (1, 3);

	g->add_edge (2, 0);
	g->add_edge (2, 1);
	g->add_edge (2, 3);
	g->add_edge (2, 5);
	
	g->add_edge (3, 1);
	g->add_edge (3, 2);
	g->add_edge (3, 4);
	g->add_edge (3, 5);
	
	g->add_edge (4, 3);
	g->add_edge (4, 5);

	g->add_edge (5, 2);
	g->add_edge (5, 3);
	g->add_edge (5, 4);
	
	g->print_graph ();
	g->transverse_graph_from (0);
}
