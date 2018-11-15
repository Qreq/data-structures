#ifndef BINTREE_H
#define BINTREE_H
#include <string>

class BinTreeNode{
	public:
	std::string value;
	BinTreeNode* left;
	BinTreeNode* right;
	BinTreeNode* parent;
	int frequency_of_node;
	BinTreeNode(std::string, BinTreeNode*);
};
#endif