#include "binary_tree.cpp"
#include <fstream>
void binary_tree_using_vector(){
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
void binary_tree_using_textfile(){
	
}
int main(){
	cout << "USING VECTOR" << endl;
	cout << "............" << endl;
	binary_tree_using_vector();
	cout << "............" << endl;
	cout << "USING TEXT FILE" << endl;
	cout << "..............." << endl;
	binary_tree_using_textfile();
}