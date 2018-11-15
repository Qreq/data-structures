#include "Graph.hpp"
Graph::Graph(int vertice){
	this->vertices.insert(vertice);
	this->edges = {};
	this->adj_matrix = {};
}