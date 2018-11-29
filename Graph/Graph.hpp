#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <vector>
#include <array>
/*
 * 
 * REFERENCE: two-dimensional vector creation by  ropez - http://www.cplusplus.com/forum/general/833/#msg2828
 * 
 * 
 */ 
class Graph{
	public:
	std::set<int> vertices;
	std::set<std::array<int,3>> edges;
	std::vector<std::vector<int>>* adj_matrix;
	Graph(int);
	void add_vertice(int);
	void add_edge(std::array<int,3>);
	void populate_matrix_zero();
	void matrix_connections();
	bool is_connected(int);
	std::set<int> trav_dfs(int);
	std::set<int> trav_bfs(int);
	std::vector<int> dijkstra(int);
	bool is_path(int,int);
};
#endif