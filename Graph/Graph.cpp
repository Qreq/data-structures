#include <iostream>
#include <algorithm>
#include "Graph.hpp"
 /*
  * 
  * REFERENCE: find position of an elemt in vector found here: https://stackoverflow.com/a/15099748
	  * written by user: dasblinkenlight
  * 
  */
Graph::Graph(int vertice){
	this->vertices.insert(vertice);
	this->edges = {};
	this->adj_matrix = new std::vector<std::vector<bool>>;
}
void Graph::add_vertice(int new_vertice){
	this->vertices.insert(new_vertice);
}
void Graph::add_edge(std::array<int,2> new_edge){
	//adds inserted edge to graph on two nodes
	this->edges.emplace(new_edge);
	//connects the vertices to each other, instead of just directionally
	std::array<int,2> reverse_edge = {new_edge[1],new_edge[0]};
	this->edges.emplace(reverse_edge);
}
void Graph::populate_matrix_false(){
	for (int i = 0; i < this->vertices.size(); i++){
		std::vector<bool> connections;
		for (int j = 0; j < this->vertices.size(); j++){
			connections.push_back(false);
		}
		this->adj_matrix->push_back(connections);
	}
}
void Graph::matrix_connections(){
	std::set<std::array<int,2>>::iterator edge_iter;
	std::set<int>::iterator vert_iter;

	//for use with positions in adjacency matrix vector of graph
	int x = 0;
	/* checks if a vertice is connected with another vertice
	 * increments x and y for each pass through the edges.
	 * if is connected, set position at adjacency matrix to true
	 * if not, set it to false.
	 */
	for (vert_iter = this->vertices.begin(); vert_iter != this->vertices.end(); vert_iter++){
		for (edge_iter = this->edges.begin(); edge_iter != this->edges.end(); edge_iter++){
			std::array<int,2> current_edge = *edge_iter;
			if (*vert_iter == current_edge[0]){
				ptrdiff_t connected_to_pos = std::distance(this->vertices.begin(), std::find(this->vertices.begin(), this->vertices.end(), current_edge[1]));
				this->adj_matrix->at(x).at(connected_to_pos) = true;
			}
			
		}
		x++;
	}
}