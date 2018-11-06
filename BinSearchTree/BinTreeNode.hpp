#ifndef BINTREE_H
#define BINTREE_H
#include <string>

class BinTreeNode{
	public:
	std::string value;
	BinTreeNode* left;
	BinTreeNode* right;
	BinTreeNode(std::string){};
};
#endif