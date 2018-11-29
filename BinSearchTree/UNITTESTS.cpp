#include "../Catch2/catch.hpp"

#include "binary_tree.cpp"

int i;
vector<string> correct_preorder = {};
vector<std::string> wordset1 = {"This", "is", "the","first","stage"};
BinTreeNode* binarytree1 = insert_node(nullptr,wordset1[0],nullptr);
vector<string> wordset2 = {"I","really","do","enjoy","Computer", "Science","at","Coventry","University"};
BinTreeNode* binarytree2 = insert_node(nullptr,wordset2[0],nullptr);
vector<string> wordset3 = {"Unit","Tests","are","extremely", "important","when","writing","code"};
BinTreeNode* binarytree3 = insert_node(nullptr,wordset3[0],nullptr);


TEST_CASE("Binary Tree is created from words in a vector"){
	
}

TEST_CASE("Nodes are printed in pre order"){
	//creates Binary Tree for wordset1
	for (i = 1; i < wordset1.size();i++){
		std::string word = wordset1[i];
		insert_node(binarytree1,word,binarytree1);
	}
	std::vector<std::string> preorder_result1 = {};
	std::vector<std::string> preorder_result2 = {};
	std::vector<std::string> preorder_result3 = {};
	preorder_result1 = pre_order(binarytree1,preorder_result1);
	correct_preorder = {"This","is","first","the","stage"};
	REQUIRE(preorder_result1 == correct_preorder);
	
	//creates Binary Tree for wordset2
	for (i = 1; i < wordset2.size();i++){
		std::string word = wordset2[i];
		insert_node(binarytree2,word,binarytree2);
	}
	preorder_result2 = pre_order(binarytree2,preorder_result2);
	correct_preorder = {"I","Computer","Coventry","really","do","Science","at","University","enjoy"};
	REQUIRE(preorder_result2 == correct_preorder);
	
	//creates Binary Tree for wordset3
	for (i = 1; i < wordset3.size();i++){
		std::string word = wordset3[i];
		insert_node(binarytree3,word,binarytree3);
	}
	preorder_result3 = pre_order(binarytree3,preorder_result3);
	correct_preorder = {"Unit","Tests","are","extremely","code","important","when","writing"};
	REQUIRE(preorder_result3 == correct_preorder);
}


TEST_CASE("File contents are stored into vector AND words are split properly into another vector"){
	vector<string> result_lines,result_binarytree;
	vector<string> correct_lines = {"First Line is here",
								   "And now the Second",
								   "Finally, a Third"};
	vector<string> correct_binarytree = {"First","Line","is","here",
										"And","now","the","Second",
										"Finally,","a","Third"};
	result_lines = read_from_file("UT_TEXTFILE.txt");
	REQUIRE(correct_lines == result_lines);
	
	result_binarytree = split_strings(result_lines);
	REQUIRE(correct_binarytree == result_binarytree);
}

TEST_CASE("Finds a Node in the Binary Tree"){
	BinTreeNode* node_found1_true = find_node(binarytree1, "first");
	BinTreeNode* node_found1_false = find_node(binarytree1, "count");
	BinTreeNode* node_found1_edge_true = find_node(binarytree1, "the");
	BinTreeNode* node_found1_edge_false = find_node(binarytree1, "First");
	
	//REQUIRE(node_found1_true->value == "first");
	//REQUIRE(node_found1_false == nullptr);
	REQUIRE(node_found1_edge_true->value == "the");
	REQUIRE(node_found1_edge_false == nullptr);
	
	BinTreeNode* node_found2_true = find_node(binarytree2, "really");
	BinTreeNode* node_found2_false = find_node(binarytree2, "borgin");
	BinTreeNode* node_found2_edge_true = find_node(binarytree2, "at");
	BinTreeNode* node_found2_edge_false = find_node(binarytree2, "computer");
	REQUIRE(node_found2_true->value == "really");
	REQUIRE(node_found2_false == nullptr);
	REQUIRE(node_found2_edge_true->value == "at");
	REQUIRE(node_found2_edge_false == nullptr);
	
	BinTreeNode* node_found3_true = find_node(binarytree3, "Tests");
	BinTreeNode* node_found3_false = find_node(binarytree3, "burke");
	BinTreeNode* node_found3_edge_true = find_node(binarytree3, "writing");
	BinTreeNode* node_found3_edge_false = find_node(binarytree3, "tests");
	REQUIRE(node_found3_true->value == "Tests");
	REQUIRE(node_found3_false == nullptr);
	REQUIRE(node_found3_edge_true->value == "writing");
	REQUIRE(node_found3_edge_false == nullptr);
}

