#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include "Graph.hpp"
 /*
  * 
  * REFERENCE: find position of an elemt in vector found here: https://stackoverflow.com/a/15099748
	  * written by user: dasblinkenlight
  * REFERENCE: DFS & BFS pseudocode written by Diana Hintea available here: https://cumoodle.coventry.ac.uk/pluginfile.php/2463345/mod_resource/content/0/Week%207%20Lecture%20-%20More%20Graphs.pdf
	  * DFS - Week 7 Slide 5
	  * BFS - Week 7 Slide 10
  * REFERENCE: Dijstra algorithm pseudocode found here: http://www.gitta.info/Accessibiliti/en/html/Dijkstra_learningObject1.html
  *
  */
Graph::Graph(int vertice){
	this->vertices.insert(vertice);
	this->edges = {};
	this->adj_matrix = new std::vector<std::vector<int>>;
}
void Graph::add_vertice(int new_vertice){
	this->vertices.insert(new_vertice);
}
void Graph::add_edge(std::array<int,3> new_edge){
	//adds inserted edge to graph on two nodes
	this->edges.emplace(new_edge);
	//connects the vertices to each other, instead of just directionally
	std::array<int,3> reverse_edge = {new_edge[1],new_edge[0],new_edge[2]};
	this->edges.emplace(reverse_edge);
}
void Graph::populate_matrix_zero(){
	for (int i = 0; i < this->vertices.size(); i++){
		std::vector<int> connections;
		for (int j = 0; j < this->vertices.size(); j++){
			connections.push_back(0);
		}
		this->adj_matrix->push_back(connections);
	}
}
void Graph::matrix_connections(){
	std::set<std::array<int,3>>::iterator edge_iter;
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
			std::array<int,3> current_edge = *edge_iter;
			if (*vert_iter == current_edge[0]){
				ptrdiff_t connected_to_pos = std::distance(this->vertices.begin(), std::find(this->vertices.begin(), this->vertices.end(), current_edge[1]));
				this->adj_matrix->at(x).at(connected_to_pos) = current_edge[2];
			}
			
		}
		x++;
	}
}
std::set<int> Graph::trav_dfs(int start_vert){
	std::stack<int> vertices;
	std::set<int> visited;
	vertices.push(start_vert);
	while(!vertices.empty()){
		int vert_to_check = vertices.top();
		vertices.pop();
		bool has_visit = false;
		std::set<int>::iterator vert_iter = visited.begin();
		for (vert_iter; vert_iter !=  visited.end(); vert_iter++){
			if (vert_to_check == *vert_iter){
				has_visit = true;
			}
		}
		if(!has_visit){
			visited.insert(vert_to_check);
			for (std::array<int,3> edge : this->edges){
				if (edge[0] == vert_to_check){
					int next_vert = edge[1];
					vertices.push(next_vert);
				}
			}
		}
	}
	return visited;
}
std::set<int> Graph::trav_bfs(int start_vert){
	std::queue<int> vertices;
	std::set<int> visited;
	vertices.push(start_vert);
	while(!vertices.empty()){
		int vert_to_check = vertices.front();
		vertices.pop();
		bool has_visit = false;
		std::set<int>::iterator vert_iter = visited.begin();
		for (vert_iter; vert_iter !=  visited.end(); vert_iter++){
			if (vert_to_check == *vert_iter){
				has_visit = true;
			}
		}
		if (!has_visit){
			visited.insert(vert_to_check);
			for (std::array<int,3> edge : this->edges){
				if (edge[0] == vert_to_check){
					int next_vert = edge[1];
					vertices.push(next_vert);
				}
			}
		}
	}
	return visited;
}
bool Graph::is_connected(int start_vert){
	std::set<int> dfs_order = trav_dfs(start_vert);
	return (dfs_order == this->vertices) ? true : false;
}

std::vector<int> Graph::dijkstra(int start_vert){
	std::vector<int> distance,previous;
	
	for (int vertex : this->vertices){
		//REFERENCE: max val of int found here: https://stackoverflow.com/a/8690690
		int max_val = std::numeric_limits<int>::max();
		distance[vertex] = max_val;
		previous[vertex] = 0;
	}
	distance[start_vert] = 0;
	std::set<int> all_nodes = this->vertices;
	while(!all_nodes.empty()){
		std::set<int>::iterator vert_iter = all_nodes.begin();
		int smallest_distance_vert = *vert_iter;
		//finds smallest distance from all vertices
		for (vert_iter; vert_iter != all_nodes.end(); vert_iter++){
			if (*vert_iter < smallest_distance_vert){
				smallest_distance_vert = *vert_iter;
			}
		}
		all_nodes.erase(smallest_distance_vert);
		
		for (std::array<int,3> edge : this->edges){
			if (edge[0] == smallest_distance_vert){
				int distance_to_add = distance[smallest_distance_vert] + edge[2];
				int adjacent_vertice = edge[1];
				if (distance_to_add < distance[adjacent_vertice]){
					distance[adjacent_vertice] = distance_to_add;
					previous[adjacent_vertice] = smallest_distance_vert;
				}
			}
		}	
	}
	return previous;
}
bool Graph::is_path(int start, int end){
	std::set<int> path_traversed = trav_bfs(start);
	std::set<int>::iterator path_iter = path_traversed.begin();
	for (path_iter; path_iter != path_traversed.end(); path_iter++){
		if (*path_iter == end){
			return true;
		}
	}
	return false;
}