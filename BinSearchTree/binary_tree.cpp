#include <string>
#include <vector>
#include <iostream>
#include "BinTreeNode.hpp"

/*
 * 
 *REFERENCE: insert_node function: https://cumoodle.coventry.ac.uk/pluginfile.php/2300410/mod_resource/content/0/Binary%20Search%20Tree%20in%20C%2B%2B.cpp
 *REFERENCE: pre_order function: Week 5 Lecture - Trees, Slide 20
 * 
 */

using namespace std;

BinTreeNode* insert_node(BinTreeNode* tree,string node_to_insert){
	if (tree == NULL){
		tree = new BinTreeNode(node_to_insert);
	}
	else{
		if (tree->value > node_to_insert){
			if (tree->left == NULL){
				tree->left = new BinTreeNode(node_to_insert);
			}
			else{
				insert_node(tree->left,node_to_insert);
			}
		}
		else{
			if (tree->right == NULL){
				tree->right = new BinTreeNode(node_to_insert);
			}
			else{
				insert_node(tree->right,node_to_insert);
			}
		}
	}
	return tree;
}

vector<string> pre_order(BinTreeNode* tree, vector<string> preorder_list){
	//cout << tree->value << " ";
	preorder_list.emplace_back(tree->value);
	if (tree->left != NULL){
		preorder_list = pre_order(tree->left, preorder_list);
	} 
	if (tree->right != NULL){
		preorder_list = pre_order(tree->right, preorder_list);
	}
	return preorder_list;
}

int main(){
	vector<string> wordset = {"This", "is", "the","first","stage"};
	BinTreeNode* binarytree = insert_node(0,wordset[0]);
	for (int i = 1; i < wordset.size();i++){
		string word = wordset[i];
		insert_node(binarytree,word);
	}
	cout << "Printing Preorder ..." << endl;
	vector<string> preorder_list ={};
	preorder_list = pre_order(binarytree,preorder_list);
	for (int i = 0; i < preorder_list.size();i++){
		string node = preorder_list[i];
		cout << node << " ";
	}
	cout << endl;
	//cout << "Root Node is" << binarytree->value << endl;
	return 0;
}