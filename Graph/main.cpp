#include "Graph.hpp"
#include <iostream>

using namespace std;
Graph* populate_graph(Graph* graph, vector<int> nodes){
	
	for (int i = 1; i < nodes.size();i++){
		int node = nodes[i];
		graph->add_vertice(node);
	}
	return graph;
}
Graph* populate_edges(Graph* graph, set<array<int,2>> edges){
	set<array<int,2>>::iterator edge_iter;
	for (edge_iter = edges.begin(); edge_iter != edges.end(); edge_iter++){
		graph->add_edge(*edge_iter);
	}
	return graph;
}
void adjacency_matrix(Graph* graph){
	graph->populate_matrix_false();
	graph->matrix_connections();
}
int main(){
	vector<int> nodes = {3,5,7,4,6,7,12,1,2,4,6,7};
	set<array<int,2>> edges = {{4,6},{1,4},{3,7},{12,5},{2,6},{2,7},{3,12},{3,5}};
	int first_node = nodes[0];
	Graph* my_graph = new Graph(first_node);
	my_graph = populate_graph(my_graph,nodes);
	my_graph = populate_edges(my_graph,edges);
	adjacency_matrix(my_graph);
	
	cout << "Printing adj matrix" << endl;
	for (int i = 0; i < my_graph->adj_matrix->size(); i++){
		for (int j = 0; j < my_graph->adj_matrix->at(i).size(); j++){
			bool is_connected = my_graph->adj_matrix->at(i).at(j);
			cout << is_connected << " ";
		}
		cout << endl;
	}
	return 0;
}