#include "MyAVL.h"






int main() {
	AVLTree<std::string, int> Tree;
	Tree.insert("first", 1);
	Tree.insert("second", 2);
	Tree.insert("third", 3);
	Tree.DeleteVertex("first");
	return 0;
}
