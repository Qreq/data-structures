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
bool Graph::is_path(int start, int end, std::set<int> checked_vertices){
	if (start == end){
		return true;
	}
	checked_vertices.insert(start);
	
	ptrdiff_t connection_line = std::distance(this->vertices.begin(), std::find(this->vertices.begin(),this->vertices.end(),start));
	std::cout << "CONNECTION_LINE = " << connection_line << std::endl;
	
	auto matr_it = this->adj_matrix->at(connection_line).begin();
	bool all_vertices_used = true;
	std::set<int>::iterator vert_iter = this->vertices.begin();
	std::cout << checked_vertices.size() << std::endl;
	
	//
	//
	//
	
	ptrdiff_t connected_index = std::distance(this->adj_matrix->at(connection_line).begin(), std::find(matr_it,this->adj_matrix->at(connection_line).end(),true));
	std::cout << "size of checked = "<< checked_vertices.size() << std::endl;
	std::advance(vert_iter,connected_index);
	std::set<int>::iterator used_vert_iter = checked_vertices.begin();
	for (used_vert_iter; used_vert_iter != checked_vertices.end(); used_vert_iter++){
		std::cout << "i = " << *used_vert_iter << std::endl;
		if (*vert_iter == *used_vert_iter){
			std::cout << "duplicate" << std::endl;
			matr_it = std::find(this->adj_matrix->at(connection_line).begin(),this->adj_matrix->at(connection_line).end(),*vert_iter);
			matr_it++;
		}
		/*
		else(used_vert_iter != checked_vertices.end()){
			std::cout << "got here" << std::endl;
			all_vertices_used = false;
		}
		*/
	}
	if (all_vertices_used){
		return false;
	}
	//std::cout << "CONNECTED TO ==== " << *vert_iter << std::endl;
	
	
	return is_path(*vert_iter,end,checked_vertices);
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
			for (std::array<int,2> edge : this->edges){
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
			for (std::array<int,2> edge : this->edges){
				if (edge[0] == vert_to_check){
					int next_vert = edge[1];
					vertices.push(next_vert);
				}
			}
		}
	}
	return visited;
}