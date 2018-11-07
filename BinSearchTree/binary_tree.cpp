#include <string>
#include <vector>
#include <iostream>
#include "BinTreeNode.hpp"

using namespace std;

BinTreeNode* insert_node(BinTreeNode* tree,string node_to_insert){
	if (tree == NULL){
		//cout << "got to NULL" << endl;
		tree = new BinTreeNode(node_to_insert);
		//cout << "ROOT NODE " << tree->value << endl;
	}
	else{
		if (tree->value > node_to_insert){
			if (tree->left == NULL){
				tree->left = new BinTreeNode(node_to_insert);
			}
			else{
				tree = insert_node(tree->left,node_to_insert);
			}
		}
		else{
			if (tree->right == NULL){
				tree->right = new BinTreeNode(node_to_insert);
			}
			else{
				tree = insert_node(tree->right,node_to_insert);
			}
		}
	}
	return tree;
}

void pre_order(BinTreeNode* tree){
	cout << "Before Print" << endl;
	cout << tree->value << " ";
	if (tree->left != NULL) pre_order(tree->left);
	if (tree->right != NULL) pre_order(tree->right);
}

int main(){
	/*
	 * WORDS ARE NOT SET INTO PROPERTIES
	 */
	vector<string> words = {"This", "is", "the","first","stage"};
	BinTreeNode* binarytree = NULL;
	for (int i = 0; i < words.size();i++){
		string word = words[i];
		insert_node(binarytree,word);
	}
	cout << "Printing Preorder ..." << endl;
	pre_order(binarytree);
	//cout << "Root Node is" << binarytree->value << endl;
	return 0;
}