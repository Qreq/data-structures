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

BinTreeNode* insert_node(BinTreeNode* tree,string node_to_insert){
	if (tree == NULL){
		tree = new BinTreeNode(node_to_insert);
	}
	else{
		/*
		if (tree->value == node_to_insert){
			count++;
		}
		*/
		if (tree->value > node_to_insert){
			if (tree->left == NULL){
				tree->left = new BinTreeNode(node_to_insert);
			}
			else{
				//tree->frequency_of_node += count;
				insert_node(tree->left,node_to_insert);
			}
		}
		else{
			if (tree->right == NULL){
				tree->right = new BinTreeNode(node_to_insert);
			}
			else{
				//tree->frequency_of_node += count;
				insert_node(tree->right,node_to_insert);
			}
		}
	}
	return tree;
}

bool find_node(BinTreeNode* tree, string node_to_find){
	if (tree->value == node_to_find){
		return true;
	}
	else if (tree == NULL){
		cout << "Node Not Found!" << endl;
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