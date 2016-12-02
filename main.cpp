#include "MyAVL2.h"
#include "MyString.h"
#include <cassert>

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main() {
	try {
		test1();
		test2();
		test3();
		test4();
		test5();
		test6();
	}
	catch(int e) {
		switch(e) {
			case 1: { std::cout << "YOU CALLD FUNC KEY() FOR NULL" << std::endl; return -1;}
			case 2: { std::cout << "YOU CALLD FUNC VALUE() FOR NULL" << std::endl; return -1;}
			case 3: { std::cout << "YOU CALLD FUNC SORT() FOR EMPTY" << std::endl; return -1;}
			case 4: { std::cout << "YOU CALLD FUNC [] FOR UNEXIST" << std::endl; return -1;}
			case 5: { std::cout << "YOU CALLD FUNC DELETE FOR UNEXIST VERTEX" << std::endl; return -1;}
			case 6: { std::cout << "YOU CALLD FUNC PRINT FOR EMPTY" << std::endl; return -1;}
			default: { return 0; }
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
	std::cout << "\nTEST 4 iterators\n" << std::endl;
	AVLTree<String, int> Tree;
	Tree.insert("first", 1);
        Tree.insert("second", 2);
        Tree.insert("third", 3);
        Tree.insert("fourth", 4);
        Tree.insert("fivth", 5);
        Tree.insert("sixth", 6);
	Tree.AVLPrint();
	AVLTree<String, int>::AVL_iterator it(Tree);
	for(it = Tree.GetMin(); it != Tree.GetMax(); ++it)
		std::cout << "(" << it.key() << ", " << it.value() << ")" << std::endl;
	std::cout << "(" << it.key() << ", " << it.value() << ")" << std::endl;
}
void test5() {
 	std::cout << "\nTEST 5, =\n" << std::endl;
        AVLTree<String, int> Tree;
        Tree.insert("first", 1);
        Tree.insert("second", 2);
        Tree.insert("third", 3);
        Tree.insert("fourth", 4);
        Tree.insert("fivth", 5);
        std::cout << "\n                          Tree 1 = {1, 2, 3, 4, 5}\n"  << std::endl;
        Tree.AVLPrint();
	AVLTree<String, int> Tree_copy;
	Tree_copy = Tree;
	std::cout << '\n';
	std::cout << "\nCopy Tree\n" << std::endl;
	Tree_copy.AVLPrint();
}
void test6() {
	std::cout << "\nTEST 6, AVLSort\n" << std::endl;
	AVLTree<String, int> Tree;
        Tree.insert("first", 1);
        Tree.insert("second", 2);
        Tree.insert("third", 3);
        Tree.insert("fourth", 4);
        Tree.insert("fivth", 5);
        Tree.insert("sixth", 6);
	std::cout << "        Tree before sort\n" << std::endl;
	Tree.AVLPrint();
	Tree.AVLSort();
	std::cout << "\n        Tree after sort\n" << std::endl;
	Tree.AVLPrint();
}
