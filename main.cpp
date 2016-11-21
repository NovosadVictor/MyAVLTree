#include "MyAVL.h"
#include <iostream>
#include <string>





int main() {
	AVLTree<std::string, int> Tree;
	Tree.insert("first", 1);
	Tree.insert("second", 2);
	Tree.insert("third", 3);
	Tree.insert("fourth", 4);
	Tree.insert("fivth", 5);
//	std::cout << "                          Tree 1 = {1, 2, 3, 4, 5}\n"  << std::endl;
//	Tree.AVLPrint();
	Tree.insert("sixth", 6);
	Tree.insert("seventh", 7);
	Tree.insert("eighth", 8);
	Tree.insert("nineth", 9);
	Tree.insert("tenth", 10);
//	std::cout << "             Tree 2 = Tree1 + {6, 7, 8, 9, 10}\n" << std::endl;
//	Tree.AVLPrint();
	Tree.DeleteVertex("first");
	Tree.DeleteVertex("fivth");
//	std::cout << "                 Tree 3 = Tree 2 - {1, 5}\n" << std::endl;
//	Tree.AVLPrint();
	Tree.DeleteVertex("second");
//	std::cout << "                 Tree4 = Tree 3 - {2}\n" << std::endl;
	Tree.AVLPrint();
//	AVL_iterator<std::string, int> it;
//	it = Tree.GetRoot();
//	std::cout << (*it)._key << std::endl;
//	it.GetLeft();
//	std::cout << (*it)._key << std::endl;
	Tree.DeleteVertex("third");
	Tree.DeleteVertex("fourth");
	Tree.DeleteVertex("sixth");
	Tree.AVLPrint();
	return 0;
}
