#include <set>
#include <vector>
#include <array>
class Graph{
	public:
	std::set<int> vertices;
	std::set<std::array<int,2>> edges;
	std:vector<bool> adj_matrix;
	Graph(std::set<int>, std::set<std::array<int,2>>, std::vector<bool>);
}