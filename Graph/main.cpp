#include "unweighted_graph.cpp"

using namespace std;
Graph* populate_graph(Graph* graph, vector<int> nodes){
	
	for (int i = 1; i < nodes.size();i++){
		int node = nodes[i];
		add_vertice(node,graph);
	}
	return graph;
}

int main(){
	vector<int> nodes = {3,5,7,4,6,7,9,1,2,4,6,7};
	int first_node = nodes[0];
	Graph* my_graph = new Graph(first_node);
	my_graph = populate_graph(my_graph,nodes);

	return 0;
}