#include <iostream>
#include <algorithm>
#include "Graph.hpp"
 
using namespace std;

void add_vertice(int new_vertice, Graph* graph_to_add){
	graph_to_add->vertices.insert(new_vertice);
}

void add_edge(Graph* graph_to_add, array<int,2> new_edge){
	//adds inserted edge to graph on two nodes
	graph_to_add->edges.emplace(new_edge);
	//connects the vertices to each other, instead of just directionally
	array<int,2> reverse_edge = {new_edge[1],new_edge[0]};
	graph_to_add->edges.emplace(reverse_edge);
}
Graph* empty_matrix(Graph* graph){
	for (int i = 0; i < graph->vertices.size(); i++){
		vector<bool> connections;
		for (int j = 0; j < graph->vertices.size(); j++){
			graph->adj_matrix->at(i).at(j) = false;
			//connections.push_back(false);
		}
		cout << "Pushing" << endl;
		//graph->adj_matrix->at(i).push_back(connections);
	}
	cout << "Retuning" << endl;
	return graph;
}
Graph* populate_adjacency_matrix(Graph* graph_with_matrix){
	set<array<int,2>>::iterator edge_iter;
	set<int>::iterator vert_iter;
	
	graph_with_matrix = empty_matrix(graph_with_matrix);
	//for use with positions in adjacency matrix vector of graph
	int x = 0;
	
	/* checks if a vertice is connected with another vertice
	 * increments x and y for each pass through the edges.
	 * if is connected, set position at adjacency matrix to true
	 * if not, set it to false.
	 */
	for (vert_iter = graph_with_matrix->vertices.begin(); vert_iter != graph_with_matrix->vertices.end(); vert_iter++){
		cout << "x = " << x << endl;
		vector<bool> vertices_connected = {};
		for (edge_iter = graph_with_matrix->edges.begin(); edge_iter != graph_with_matrix->edges.end(); edge_iter++){
			array<int,2> current_edge = *edge_iter;
			if (*vert_iter == current_edge[0]){
				cout << "Are Connected" << endl;
				graph_with_matrix->adj_matrix->at(x).at(current_edge[1]) = true;
			}
			else{
				cout << "not connected" << endl;
			}
			
		}
		graph_with_matrix->adj_matrix->push_back(vertices_connected);
		x++;
	}
	return graph_with_matrix;
}