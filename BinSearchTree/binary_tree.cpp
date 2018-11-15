#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "BinTreeNode.hpp"

/*
 * 
 *REFERENCE: insert_node function: https://cumoodle.coventry.ac.uk/pluginfile.php/2300410/mod_resource/content/0/Binary%20Search%20Tree%20in%20C%2B%2B.cpp
 *REFERENCE: pre_order function: Week 5 Lecture - Trees, Slide 20
 *REFERENCE: find_node function: Week 5 Lecture - Trees - Slide 14
 *REFERENCE: remove_node function: Week 5 Lecture - Trees - Slide 33
 */

using namespace std;

BinTreeNode* insert_node(BinTreeNode* tree,string node_to_insert,BinTreeNode* parent){
	if (tree == nullptr){
		tree = new BinTreeNode(node_to_insert,parent);
	}
	else if (tree->value ==  node_to_insert){
		tree->frequency_of_node += 1;
	}
	else{
		if (tree->value > node_to_insert){
			if (tree->left == nullptr){
				tree->left = new BinTreeNode(node_to_insert,tree);
			}
			else{
				insert_node(tree->left,node_to_insert,tree);
			}
		}
		else{
			if (tree->right == nullptr){
				tree->right = new BinTreeNode(node_to_insert,tree);
			}
			else{
				insert_node(tree->right,node_to_insert,tree);
			}
		}
	}
	return tree;
}

BinTreeNode* find_node(BinTreeNode* tree, string node_to_find){
	if (tree->value == node_to_find){
		return tree;
	}
	else if (tree->right == nullptr && tree->left == nullptr){
		return nullptr;
	}
	else if (tree->value > node_to_find){
		cout << "Traversing Left on Tree from " << tree->value << " to " << tree->left->value << endl;
		return find_node(tree->left,node_to_find);
	}
	else{
		cout << "Traversing Right on Tree from " << tree->value << " to " << tree->right->value << endl;
		return find_node(tree->right,node_to_find);	
	}
}

void frequency_output(BinTreeNode* tree){
	cout << "Frequency of Value " << tree->value << ": " << tree->frequency_of_node << endl;
	if (tree->left != nullptr) frequency_output(tree->left);
	if (tree->right != nullptr) frequency_output(tree->right);
}
vector<string> pre_order(BinTreeNode* tree, vector<string> preorder_list){
	preorder_list.emplace_back(tree->value);
	if (tree->left != nullptr){
		preorder_list = pre_order(tree->left, preorder_list);
	} 
	if (tree->right != nullptr){
		preorder_list = pre_order(tree->right, preorder_list);
	}
	return preorder_list;
}

vector<string> read_from_file(string filename){
	string line;
	vector<string> lines;
	ifstream file (filename);
	if (file.is_open()){
		while (getline(file,line)){
			lines.emplace_back(line);
		}
	}
	else{
		cout << "Unable to open file:" << filename << endl;
	}
	return lines;
}
vector<string> split_strings(vector<string> lines){
	vector<string> result,split_text;
	for (int i= 0; i < lines.size(); i++){
		string text = lines[i];
		boost::split(split_text,text, [](char c){
			return c == ' ';
		});
		for (int j = 0; j < split_text.size(); j++){
			string word = split_text[j];
			result.emplace_back(word);
		}
	}
	return result;
}

int count_children(BinTreeNode* node){
	int count = 0;
	if (node->left != nullptr){
		count++;
	}
	if (node->right != nullptr){
		count++;
	}
	return count;
}

void remove_childless_node(BinTreeNode* node_to_remove){
	//removes node from tree, and updates parent's node connection
	if (node_to_remove->parent->left ==  node_to_remove){
		node_to_remove->parent->left = nullptr;
	}
	else if (node_to_remove->parent->right == node_to_remove){
		node_to_remove->parent->right = nullptr;
	}
	node_to_remove = nullptr;
}
void remove_one_child_node(BinTreeNode* parent_of_remove, BinTreeNode* node_to_remove){
	//removes node from tree, swapping the place of child to it's parent
	BinTreeNode* temp_swap = node_to_remove;
	if (node_to_remove->left != nullptr){
		node_to_remove = node_to_remove->left;
	}
	else if (node_to_remove->right != nullptr){
		node_to_remove = node_to_remove->right;
	}
	if (parent_of_remove->left == temp_swap){
		parent_of_remove->left = node_to_remove;
	}
	else if (parent_of_remove->right == temp_swap){
		parent_of_remove->right = node_to_remove;
	}
}
string find_max_from_left(BinTreeNode* node_to_remove, string max_value){
	//finds max value on lfet subtree of node to remove, swaps it with the removal node, and deletes the duplicate value
	if (node_to_remove->value > max_value){
		max_value = node_to_remove->value;
	}
	if (node_to_remove->right != nullptr){
		return find_max_from_left(node_to_remove->right,max_value);
	}
	else if (node_to_remove->left != nullptr){
		return find_max_from_left(node_to_remove->left,max_value);
	}
	return max_value;	
}
void remove_two_child_node(BinTreeNode* parent_of_remove, BinTreeNode* node_to_remove, BinTreeNode* tree){
	string max_value = find_max_from_left(node_to_remove->left,node_to_remove->value);
	BinTreeNode* duplicate_node = find_node(tree,max_value);
	node_to_remove->value = max_value;
	duplicate_node->value = nullptr;
	duplicate_node->left = nullptr;
	duplicate_node->right = nullptr;
}
BinTreeNode* remove_node(BinTreeNode* tree, string node_to_find){
	BinTreeNode* node_to_remove = find_node(tree,node_to_find);
	if (node_to_remove == nullptr){
		return node_to_remove;
	}
	int num_children = count_children(node_to_remove);
	switch (num_children){
		case 0:
			remove_childless_node(node_to_remove);
			break;
		case 1:
			remove_one_child_node(node_to_remove->parent,node_to_remove);
			break;
		case 2:
			remove_two_child_node(node_to_remove->parent,node_to_remove,tree);
			break;
	}
	return tree;
		
}

