#include<string>
#include<iostream>
#include<vector>

struct Node {
	int 	value;
	std::vector<int> edges;
	Node (int _value) {
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

int main () {
	Graph* g = new Graph (1);
	g->add_vertex (2);
	g->add_edge (0, 1);
	g->print_graph ();
}
