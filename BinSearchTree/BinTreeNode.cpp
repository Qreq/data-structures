#include <string>
#include "BinTreeNode.hpp"

BinTreeNode::BinTreeNode(std::string word,BinTreeNode* parent){
	this->value = word;
	this->left = nullptr;
	this->right = nullptr;
	this->frequency_of_node = 1;
	this->parent = parent;
}
BinTreeNode::~BinTreeNode(){
	std::cout << "deleted" << std::endl;
}