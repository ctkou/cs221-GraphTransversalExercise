#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

struct Node {
	int 	value;
	bool	visited;
	bool 	pending;
	std::vector<int> edges;
	Node (int _value) : visited(false), pending(false) {
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
	void breadth_first_transversal_from (int i);
	void depth_first_transversal_from (int i);
	void graph_reset ();
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

void Graph::breadth_first_transversal_from (int i) {
	std::queue<Node*> q;
	Node* current;
	Node* temp;
	this->v.at (i)->pending = true;
	q.push (this->v.at (i));					// start transversal from index i
	while (!(q.empty ())) {	
		current = q.front ();					// pop the first node from the queue
		q.pop ();
		current->visited = true;				// set the current node as visited
		for (int j = 0; j < current->edges.size (); ++j) {
			temp = this->v.at (current->edges.at (j) - 1);	// get the adjacent node
			if (!(temp->visited) && !(temp->pending)) {
				q.push (temp);				// push the node to the back of queue if it is not visited and not discovered
				temp->pending = true;
			}
		}
		std::cout << "Visited vertex at " << current->value << std::endl;
	}
	graph_reset ();
}

void Graph::depth_first_transversal_from (int i) {
	std::stack<Node*> s;
	Node* current;
	Node* temp;
	this->v.at (i)->pending = true;
	s.push (this->v.at (i));
	while (!(s.empty())) {
		current = s.top ();
		s.pop ();
		current->visited = true;
		for (int j = current->edges.size () - 1; j >= 0; --j) {
			temp = this->v.at (current->edges.at (j) - 1);
			if (!(temp->visited) && !(temp->pending)) {
				s.push(temp);
				temp->pending = true;
			}
		}
		std::cout << "Visited vertext at " << current->value << std::endl;
	}	
	graph_reset();
}

void Graph::graph_reset () {
	for (int i = 0; i < this->v.size(); ++i) {
		this->v.at (i)->visited = false;
		this->v.at (i)->pending = false;
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
	
	std::cout << "breadth first transversal: " << std::endl;
	g->breadth_first_transversal_from (0);

	delete g;

	g = new Graph (1);

	g->add_vertex(2);
	g->add_vertex(3);
	g->add_vertex(4);
	g->add_vertex(5);
	g->add_vertex(6);
	g->add_vertex(7);

	g->add_edge (0, 1);
	g->add_edge (0, 2);
	g->add_edge (0, 3);

	g->add_edge (1, 0);
	g->add_edge (1, 4);
	
	g->add_edge (2, 0);
	g->add_edge (2, 4);

	g->add_edge (3, 0);
	g->add_edge (3, 5);

	g->add_edge (4, 1);
	g->add_edge (4, 2);
	g->add_edge (4, 6);

	g->add_edge (5, 3);
	g->add_edge (5, 6);

	g->add_edge (6, 4);
	g->add_edge (6, 5);

	std::cout << "depth first transversal: " << std::endl;
	g->depth_first_transversal_from (0);

}
