#include <string>
#include "BinTreeNode.hpp"

BinTreeNode::BinTreeNode(std::string word)
{
	this->value = word;
	this->left = NULL;
	this->right = NULL;
	this->frequency = 1;
}