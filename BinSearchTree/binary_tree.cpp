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
 *REFERENCE: find_node function: Week 5 Lecture - Trees - Slide 33
 */

using namespace std;

BinTreeNode* insert_node(BinTreeNode* tree,string node_to_insert,BinTreeNode* parent){
	if (tree == NULL){
		tree = new BinTreeNode(node_to_insert,parent);
	}
	else{
		/*
		if (tree->value == node_to_insert){
			count++;
		}
		*/
		if (tree->value > node_to_insert){
			if (tree->left == NULL){
				tree->left = new BinTreeNode(node_to_insert,parent);
			}
			else{
				//tree->frequency_of_node += count;
				insert_node(tree->left,node_to_insert,parent);
			}
		}
		else{
			if (tree->right == NULL){
				tree->right = new BinTreeNode(node_to_insert,parent);
			}
			else{
				//tree->frequency_of_node += count;
				insert_node(tree->right,node_to_insert,parent);
			}
		}
	}
	return tree;
}

BinTreeNode* find_node(BinTreeNode* tree, string node_to_find){
	if (tree->value == node_to_find){
		return tree;
	}
	else if (tree == NULL){
		cout << "Node Not Found!" << endl;
		return NULL;
	}
	else if (tree->value > node_to_find){
		cout << "Traversing Left on Tree from " << tree->value << " to " << tree->left << endl;
		return find_node(tree->left,node_to_find);
	}
	else{
		cout << "Traversing Left on Tree from " << tree->value << " to " << tree->right << endl;
		return find_node(tree->right,node_to_find);
	}
}

void frequency_output(BinTreeNode* tree){
	cout << "Frequency of Value " << tree->value << ": " << tree->frequency_of_node << endl;
	if (tree->left != NULL) frequency_output(tree->left);
	if (tree->right != NULL) frequency_output(tree->right);
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
	if (node->left != NULL){
		count++;
	}
	if (node->right != NULL){
		count++;
	}
	return count;
}

void remove_childless_node(BinTreeNode* parent_of_remove, BinTreeNode* node_to_remove){
	//removes node from tree, and updates parent's node connection
	if (parent_of_remove->left !=  NULL){
		parent_of_remove->left == NULL
	}
	else if (parent_of_remove-> right != NULL){
		parent_of_remove->right == NULL;
	}
	node_to_remove->value = NULL;	
}
void swap_one_child_node(BinTreeNode* parent_of_remove, BinTreeNode* node_to_remove){
	//removes node from tree, swapping the place of child to it's parent
	BinTreeNode* temp_swap = node_to_remove;
	if (node_to_remove->left != NULL){
		node_to_remove = node_to_remove->left;
	}
	else if (node_to_remove->right != NULL){
		node_to_remove = node_to_remove->right;
	}
	if (parent_of_remove->left == temp_swap){
		parent_of_remove->left = node_to_remove;
	}
	else if (parent_of_remove->right == temp_swap){
		parent_of_remove->right = node_to_remove;
	}
}
void remove_node(BinTreeNode* tree, string node_to_find){
	BinTreeNode* node_to_remove = find_node(tree,node_to_find);
	BinTreeNode* parent_of_remove = find_node(tree,node_to_remove->parent);
	if (node_to_remove == NULL){
		return;
	}
	int num_children = count_children(node_to_remove);
	switch (num_children){
		case 0:
			remove_childless_node(parent_of_remove,node_to_remove);
		case 1:
			swap_one_child_node()
		case 2:
	}
}

