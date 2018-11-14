#include <string>
#include "BinTreeNode.hpp"

BinTreeNode::BinTreeNode(std::string word,BinTreeNode* parent){
	this->value = word;
	this->left = NULL;
	this->right = NULL;
	this->frequency_of_node = 1;
	this->parent = parent;
}