#include "unweighted_graph.cpp"

using namespace std;
Graph* populate_graph(Graph* graph, vector<int> nodes){
	
	for (int i = 1; i < nodes.size();i++){
		int node = nodes[i];
		add_vertice(node,graph);
	}
	return graph;
}
Graph* populate_edges(Graph* graph, set<array<int,2>> edges){
	set<array<int,2>>::iterator edge_iter;
	for (edge_iter = edges.begin(); edge_iter != edges.end(); edge_iter++){
		add_edge(graph,*edge_iter);
	}
	return graph;
}
int main(){
	vector<int> nodes = {3,5,7,4,6,7,9,1,2,4,6,7};
	set<array<int,2>> edges = {{4,6},{1,4},{3,7},{9,5}};
	int first_node = nodes[0];
	Graph* my_graph = new Graph(first_node);
	my_graph = populate_graph(my_graph,nodes);
	my_graph = populate_edges(my_graph,edges);
	my_graph = populate_adjacency_matrix(my_graph);
	for (int i = 0; i < my_graph->adj_matrix.size(); i++){
		for (int j = 0; my_graph->adj_matrix.size(); j++){
			cout << my_graph->adj_matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}