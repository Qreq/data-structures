#include "binary_tree.cpp"
#include <fstream>
#include <boost/algorithm/string.hpp>
/*
 * 
 * CREDITS:  splits_strings function attributed to Jonathan Boccara
 * Found here on Solution 2: https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
 * 
 */

void binary_tree_using_textfile(){
	//creates binary tree from textfile
	vector<string> lines,convert_to_tree;
	lines = read_from_file("filetoread.txt");
	convert_to_tree = split_strings(lines);
	BinTreeNode* binarytree = insert_node(0,convert_to_tree[0],nullptr);
	for (int i = 1; i < convert_to_tree.size();i++){
		string word = convert_to_tree[i];
		insert_node(binarytree,word,binarytree->parent);
	}
	//print pre order of binary tree
	cout << "Printing Preorder ..." << endl;
	vector<string> preorder_list ={};
	preorder_list = pre_order(binarytree,preorder_list);
	for (int i = 0; i < preorder_list.size();i++){
		string node = preorder_list[i];
		cout << node << " ";
	}
	cout << endl;
	//searches for values
	vector<string> searches = {"Japanese","this","create","doll","cheese"};
	for (int i = 0; i < searches.size();i++){
		string node = searches[i];
		cout << endl << "Commencing Search for: " << node << endl;
		cout << "-------------------------------------" << endl;
		BinTreeNode* result_of_find_node = find_node(binarytree,node);
		if (result_of_find_node ==  nullptr) {
			cout << "Node Not Found" << endl;
		}
		else if (result_of_find_node->value == node){
			cout << "Node Found" << endl;
		}
	}
	cout << endl << "Commencing Deletion of Nodes" << endl;
	cout << "------------------------------------------" << endl;
	remove_node(binarytree,"I");
}
int main(){
	cout << "USING TEXT FILE" << endl;
	cout << "..............." << endl;
	binary_tree_using_textfile();
	return 0;
}