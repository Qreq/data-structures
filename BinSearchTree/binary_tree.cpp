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
 * 
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

vector<string> read_from_file(){
	string filename = "filetoread.txt";
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
	vector<string> result;
	for (int i= 0; i < lines.size(); i++){
		string text = lines[i];
		boost::split(result,text, [](char c){
			return c == ' ';
		});
	}
	return result;
}

/*
int main(){
	vector<string> wordset = {"This", "is", "the","first","stage","the"};
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
*/
