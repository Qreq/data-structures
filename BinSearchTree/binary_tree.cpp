#include <string>
#include <vector>
#include <iostream>
#include "BinTreeNode.hpp"

using namespace std;

BinTreeNode* insert_node(BinTreeNode* tree,string node_to_insert){
	if (tree == NULL){
		cout << "got to NULL" << endl;
		tree = new BinTreeNode(node_to_insert);
	}
	else if (tree->value < node_to_insert){
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
	return tree;
}
int main(){
	vector<string> words123 = {"This", "is", "the","first","stage"};
	string word = words123[0];
	cout << word << endl;
	BinTreeNode* binarytree = insert_node(NULL,word);
	cout << "Root Node is" << binarytree->value << endl;
	return 0;
}