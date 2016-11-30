#include "MyAVL.h"
#include "MyString.h"
#include <cassert>

void test1();
void test2();
void test3();
void test4();


int main() {
	try {
//		test1();
//		test2();
//		test3();
		test4();
	}
	catch(int e) {
		if (e == 3) {
			std::cout << "YOU TRY DELETE UNFIND VERTEX" << std::endl;
			return 0;
		}
	}
	return 0;
}
void test2() {
	std::cout << "TEST 2, INSERT" << std::endl;
	AVLTree<String, int> Tree;
	Tree.insert("first", 1);
	Tree.insert("second", 2);
	Tree.insert("third", 3);
	Tree.insert("fourth", 4);
	Tree.insert("fivth", 5);
	std::cout << "\n                          Tree 1 = {1, 2, 3, 4, 5}\n"  << std::endl;
	Tree.AVLPrint();
	Tree.insert("sixth", 6);
	Tree.insert("seventh", 7);
	Tree.insert("eighth", 8);
	Tree.insert("nineth", 9);
	Tree.insert("tenth", 10);
	std::cout << "\n                            Tree 2 = Tree1 + {6, 7, 8, 9, 10}\n" << std::endl;
	Tree.AVLPrint();
}
void test3() {
	std::cout << "\nTEST 3 , DELETE\n" << std::endl;
	AVLTree<String, int> Tree;
	Tree.insert("first", 1);
        Tree.insert("second", 2);
        Tree.insert("third", 3);
        Tree.insert("fourth", 4);
        Tree.insert("fivth", 5);
	Tree.insert("sixth", 6);
        Tree.insert("seventh", 7);
        Tree.insert("eighth", 8);
        Tree.insert("nineth", 9);
        Tree.insert("tenth", 10);
	std::cout << "Tree {1,2,3,4,5,6,7,8,9,10} before del\n" << std::endl;
	Tree.AVLPrint();
	Tree.DeleteVertex("first");
	Tree.DeleteVertex("fivth");
	std::cout << "                       Tree - {1, 5}\n" << std::endl;
	Tree.AVLPrint();
	Tree.DeleteVertex("second");
	std::cout << "\n                  Tree - {2}\n" << std::endl;
	Tree.AVLPrint();
	Tree.DeleteVertex("third");
	Tree.DeleteVertex("fourth");
	Tree.DeleteVertex("sixth");
	std::cout << "\n                     Tree - {3,4,6}\n" << std::endl;
	Tree.AVLPrint();
}
void test1() {
	AVLTree<String, int> Tree;
        Tree.insert("first", 1);
        Tree.insert("second", 2);
        Tree.insert("third", 3);
        Tree.insert("fourth", 4);
        Tree.insert("fivth", 5);
        Tree.insert("sixth", 6);
        Tree.insert("seventh", 7);
        Tree.insert("eighth", 8);
        Tree.insert("nineth", 9);
        Tree.insert("tenth", 10);
	assert(Tree.find("first") && Tree.find("second") && Tree.find("fivth") && Tree.find("sixth"));
}
void test4() {
	std::cout << "TEST 4 iterators" << std::endl;
	AVLTree<String, int> Tree;
	Tree.insert("first", 1);
        Tree.insert("second", 2);
        Tree.insert("third", 3);
        Tree.insert("fourth", 4);
        Tree.insert("fivth", 5);
        Tree.insert("sixth", 6);
	Tree.AVLPrint();
	AVL_iterator<String, int> it(Tree);
	for(it = Tree.GetMin(); it != Tree.GetMax(); ++it)
		std::cout << "(" << it.key() << ", " << it.value() << ")" << std::endl;
	std::cout << "(" << it.key() << ", " << it.value() << ")" << std::endl;
	
}
