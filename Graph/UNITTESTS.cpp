#include <vector>
#include <iostream>
#include "Graph.hpp"
#include "../Catch2/catch.hpp"

Graph* graph1 = new Graph(3);
Graph* graph2 = new Graph(12);
Graph* graph3 = new Graph(7);

TEST_CASE("Check Vertices are entered in graph"){
	std::vector<int> vertices_to_add1 = {3,7,8,9,5,2,4,9,10}; //9
	std::vector<int> vertices_to_add2 = {11,7,5,2,7,4,1}; //7
	std::vector<int> vertices_to_add3 = {3,8,7,15,16,7,3,18,13,8,4,2,6}; //13 - 7 3 8 15 16 18 13 4 2 6
	
	for (int vertex : vertices_to_add1){
		graph1->vertices.insert(vertex);
	}
	for (int vertex : vertices_to_add2){
		graph2->vertices.insert(vertex);
	}
	for(int vertex : vertices_to_add3){
		graph3->vertices.insert(vertex);
	}
	
	REQUIRE(graph1->vertices.size() == 8);
	REQUIRE(graph2->vertices.size() == 7);
	REQUIRE(graph3->vertices.size() == 10);
}