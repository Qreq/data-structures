#include "Graph.hpp"
#include<iostream>

Graph::Graph(int vertice){
	this->vertices.insert(vertice);
	this->edges = {};
	this->adj_matrix = new std::vector<std::vector<bool>>;
}