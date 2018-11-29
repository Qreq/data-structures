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
	
	REQUIRE(node_found1_true->value == "first");
	REQUIRE(node_found1_false == nullptr);
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

TEST_CASE("Counts Number of Children on a Node"){
	BinTreeNode* tree1_node_0children = find_node(binarytree1, "first");
	BinTreeNode* tree1_node_2children = find_node(binarytree1, "is");
	int num_children_tree1_0 = count_children(tree1_node_0children);
	int num_children_tree1_2 = count_children(tree1_node_2children);
	REQUIRE(num_children_tree1_0 == 0);
	REQUIRE(num_children_tree1_2 == 2);
	
	BinTreeNode* tree2_node_0children = find_node(binarytree2, "Coventry");
	BinTreeNode* tree2_node_1child = find_node(binarytree2, "Science");
	BinTreeNode* tree2_node_2children = find_node(binarytree2, "do");
	int num_children_tree2_0 = count_children(tree2_node_0children);
	int num_children_tree2_1 = count_children(tree2_node_1child);
	int num_children_tree2_2 = count_children(tree2_node_2children);
	REQUIRE(num_children_tree2_0 == 0);
	REQUIRE(num_children_tree2_1 == 1);
	REQUIRE(num_children_tree2_2 == 2);
	
	BinTreeNode* tree3_node_0children = find_node(binarytree3, "writing");
	BinTreeNode* tree3_node_1child = find_node(binarytree3, "are");
	BinTreeNode* tree3_node_2children = find_node(binarytree3, "extremely");
	int num_children_tree3_0 = count_children(tree3_node_0children);
	int num_children_tree3_1 = count_children(tree3_node_1child);
	int num_children_tree3_2 = count_children(tree3_node_2children);
	REQUIRE(num_children_tree3_0 == 0);
	REQUIRE(num_children_tree3_1 == 1);
	REQUIRE(num_children_tree3_2 == 2);
}

TEST_CASE("Finds Max Value on Left of desired node"){
	BinTreeNode* tree1_2children = find_node(binarytree1, "is");
	std::string tree1_max_val = find_max_from_left(tree1_2children->left, tree1_2children->left->value);
	REQUIRE(tree1_max_val == "first");
	
	BinTreeNode* tree2_root = find_node(binarytree2, "I");
	BinTreeNode* tree2_do_node = find_node(binarytree2, "do");
	std::string tree2_max_val = find_max_from_left(tree2_root->left, tree2_root->left->value);
	std::string tree2_do_max_val = find_max_from_left(tree2_do_node->left, tree2_do_node->left->value);
	REQUIRE(tree2_max_val == "Coventry");
	REQUIRE(tree2_do_max_val == "at");
	
	BinTreeNode* tree3_root = find_node(binarytree3, "Unit");
	std::string tree3_max_val = find_max_from_left(tree3_root->left, tree3_root->left->value);
	REQUIRE(tree3_max_val == "Tests");
}

TEST_CASE("Removes Node with No Children"){
	BinTreeNode* tree1_0children = remove_node(binarytree1, "first");
	BinTreeNode* tree1_0children_removed = find_node(tree1_0children, "first");
	BinTreeNode* tree1_parent_of_removed = find_node(tree1_0children, "is");
	REQUIRE(tree1_0children_removed == nullptr);
	REQUIRE(tree1_parent_of_removed->left == nullptr);
	
	BinTreeNode* tree2_0children = remove_node(binarytree2, "enjoy");
	BinTreeNode* tree2_0children_removed = find_node(tree2_0children, "enjoy");
	BinTreeNode* tree2_parent_of_removed = find_node(tree2_0children, "do");
	REQUIRE(tree2_0children_removed == nullptr);
	REQUIRE(tree2_parent_of_removed->right == nullptr);
	
	BinTreeNode* tree3_0children = remove_node(binarytree3, "writing");
	BinTreeNode* tree3_0children_removed = find_node(tree3_0children, "writing");
	BinTreeNode* tree3_parent_of_removed = find_node(tree3_0children, "when");
	REQUIRE(tree3_0children_removed == nullptr);
	REQUIRE(tree3_parent_of_removed->right == nullptr);
}

TEST_CASE("Removes Node with One Child"){
	BinTreeNode* tree2_1child = remove_node(binarytree2, "Science");
	BinTreeNode* tree2_1child_removed = find_node(tree2_1child, "Science");
	BinTreeNode* tree2_parent_of_removed = find_node(tree2_1child, "do");
	BinTreeNode* tree2_do_new_left = find_node(tree2_1child, "at");
	REQUIRE(tree2_1child_removed == nullptr);
	REQUIRE(tree2_parent_of_removed->left == tree2_do_new_left);
	
	BinTreeNode* tree3_1child = remove_node(binarytree3, "important");
	BinTreeNode* tree3_1child_removed = find_node(tree3_1child, "important");
	BinTreeNode* tree3_parent_of_removed = find_node(tree3_1child, "extremely");
	BinTreeNode* tree3_do_new_right = find_node(tree3_1child, "when");
	REQUIRE(tree3_1child_removed == nullptr);
	REQUIRE(tree3_parent_of_removed->right == tree3_do_new_right);
}

TEST_CASE("Removes Node with Two Children"){
	BinTreeNode* tree2_2children = remove_node(binarytree2, "I");
	BinTreeNode* tree2_2children_removed = find_node(tree2_2children, "I");
	BinTreeNode* tree2_new_parent = find_node(tree2_2children, "Coventry");
	REQUIRE(tree2_2children_removed == nullptr);
	REQUIRE(tree2_new_parent->left->value == "Computer");
	REQUIRE(tree2_new_parent->right->value == "really");
	
	BinTreeNode* tree3_2children = remove_node(binarytree3, "Unit");
	BinTreeNode* tree3_2children_removed = find_node(tree3_2children, "Unit");
	BinTreeNode* tree3_new_parent = find_node(tree3_2children, "Tests");
	REQUIRE(tree3_2children_removed == nullptr);
	REQUIRE(tree3_new_parent->left == nullptr);
	REQUIRE(tree3_new_parent->right->value == "are");
}