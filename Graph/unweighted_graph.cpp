#include <iostream>

#include "Graph.hpp"

using namespace std;

void add_vertice(int new_vertice, Graph* graph_to_add){
	graph_to_add->vertices.insert(new_vertice);
}

void add_edge(Graph* graph_to_add, array<int,2> new_edge){
	//adds inserted edge to graph on two nodes
	graph_to_add->edges.insert(new_edge);
	//connects the vertices to each other, instead of just directionally
	array<int,2> reverse_edge = {new_edge[1],new_edge[0]};
	graph_to_add->edges.insert(reverse_edge);
}