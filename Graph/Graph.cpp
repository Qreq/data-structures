#include "Graph.hpp"
Graph::Graph(std::set<int> vertices, std::set<std::array<int,2>> edges, std::vector<bool> adj_matrix){
	this->vertices = vertices;
	this->edges = edges;
	this->adj_matrix = adj_matrix;
}