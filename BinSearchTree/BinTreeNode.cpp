#include <string>
#include "BinTreeNode.hpp"

BinTreeNode::BinTreeNode(std::string word){
	*value = word;
	*left = NULL;
	*right = NULL;
}