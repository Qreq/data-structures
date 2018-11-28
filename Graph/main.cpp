#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
Graph* populate_graph(Graph* graph, vector<int> nodes){
	
	for (int i = 1; i < nodes.size();i++){
		int node = nodes[i];
		graph->add_vertice(node);
	}
	return graph;
}
Graph* populate_edges(Graph* graph, set<array<int,3>> edges){
	set<array<int,3>>::iterator edge_iter;
	for (edge_iter = edges.begin(); edge_iter != edges.end(); edge_iter++){
		graph->add_edge(*edge_iter);
	}
	return graph;
}
void adjacency_matrix(Graph* graph){
	graph->populate_matrix_false();
	graph->matrix_connections();
}
void save_dfs_file(set<int> path){
	ofstream path_file;
	path_file.open("dfs.txt");
	for (int node : path){
		path_file << node + " ";
	}
	path_file.close();
}	
int main(){
	vector<int> nodes = {3,5,7,4,6,7,12,1,2,4,6,7};
	set<array<int,3>> edges = {{4,6,3},{1,4,3},{3,7,6},{12,5,2},{2,6,4},{2,7,8},{3,12,3},{3,5,9}};
	int first_node = nodes[0];
	Graph* my_graph = new Graph(first_node);
	my_graph = populate_graph(my_graph,nodes);
	my_graph = populate_edges(my_graph,edges);
	adjacency_matrix(my_graph);
	
	cout << "Printing adj matrix" << endl;
	for (int i = 0; i < my_graph->adj_matrix->size(); i++){
		for (int j = 0; j < my_graph->adj_matrix->at(i).size(); j++){
			int is_connected = my_graph->adj_matrix->at(i).at(j);
			cout << is_connected << " ";
		}
		cout << endl;
	}
	
	if (my_graph->is_path(1,6)){
		cout << "path: Yes" << endl;
	}
	else{
		cout << "path: No" << endl;
	}
	set<int> dfs_result = my_graph->trav_dfs(3);
	set<int> bfs_result = my_graph->trav_bfs(2);
	bool is_connected = my_graph->is_connected(3);
	if (is_connected){
		cout << "conneted: yes" << endl;
	}
	else{
		cout << "connected: no" << endl;
	}
	//save_dfs_file(dfs_result);
	return 0;
}