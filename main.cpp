#include "MyAVL.h"
#include "MyString.h"


void test1();
void test2();


int main() {
	test1();
	test2();
	return 0;
}

void test1() {
	std::cout << "TEST 1" << std::endl;
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
	Tree.AVLPrint();
}
void test2() {
	std::cout << "TEST 2" << std::endl;
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
	std::cout << "Tree before del" << std::endl;
        Tree.AVLPrint();
	Tree.DeleteVertex("first");
	Tree.DeleteVertex("fourth");
	Tree.DeleteVertex("second");
	std::cout << "Tree after del 1,4,2" << std::endl;
	Tree.AVLPrint();
}

