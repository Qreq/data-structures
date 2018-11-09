#include "../Catch2/catch.hpp"
#include "binary_tree.cpp"

int i;
std::vector<std::string> correct_preorder = {};
std::vector<std::string> wordset1 = {"This", "is", "the","first","stage"};
BinTreeNode* binarytree1 = insert_node(NULL,wordset1[0]);
std::vector<std::string> wordset2 = {"I","really","do","enjoy","Computer", "Science","at","Coventry","University"};
BinTreeNode* binarytree2 = insert_node(NULL,wordset2[0]);
std::vector<std::string> wordset3 = {"Unit","Tests","are","extremely", "important","when","writing","code"};
BinTreeNode* binarytree3 = insert_node(NULL,wordset3[0]);


TEST_CASE("Binary Tree is created from words in a vector"){
	
}

TEST_CASE("Nodes are printed in pre order"){
	//creates Binary Tree for wordset1
	for (i = 1; i < wordset1.size();i++){
		std::string word = wordset1[i];
		insert_node(binarytree1,word);
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
		insert_node(binarytree2,word);
	}
	preorder_result2 = pre_order(binarytree2,preorder_result2);
	correct_preorder = {"I","do","Computer","at","Coventry","enjoy","really","Science","University"};
	REQUIRE(preorder_result2 == correct_preorder);
	
	//creates Binary Tree for wordset3
	for (i = 1; i < wordset3.size();i++){
		std::string word = wordset3[i];
		insert_node(binarytree3,word);
	}
	preorder_result3 = pre_order(binarytree3,preorder_result3);
	correct_preorder = {"Unit","Tests","are","extremely","code","important","when","writing"};
	REQUIRE(preorder_result3 == correct_preorder);
}
