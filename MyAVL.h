#ifndef _MYAVL_H_
#define _MYAVL_H_
//#include "MyAVLNode.h"
#include "MyIterator.h"
#include <exception>


template <class U, class T>
class AVLTree {
public:
	AVLTree() : _root(NULL), _size(0) {}
//	AVLTree(const AVLTree<U, T> &other);
	~AVLTree();
	void insert(const U &str,T value);// И ЗДЕСЬ
	AVLNode<U, T> **insert_(AVLNode<U, T> **node, const U &str, T value); // ВОТ ЗДЕСЬ
	void DeleteVertex(const U &str);
	AVLNode<U, T> **DeleteVertex_(AVLNode<U, T> **node, const U &str);
	AVLNode<U, T> *find_(AVLNode<U, T> *node, const U &str);
	bool find(const U &str);
	void Destruct(AVLNode<U, T> **node);
	AVL_iterator<U, T> Find_(AVL_iterator<U, T> node, const U &str);
	AVL_iterator<U, T> Find(const U &str);
	AVL_iterator<U, T> GetRoot() { AVL_iterator<U, T> it(_root); return it; }
	size_t size() { return _size; }
	void print_(AVLNode<U, T> *node, int lvl, T value, char c);
	void AVLPrint();
private:
	AVLNode<U, T> *_root;
	size_t _size;
};

template<class U, class T>
AVL_iterator<U, T> AVLTree<U, T>::Find_(AVL_iterator<U, T> node, const U &str) {
	if (str < node.key())
		(*this).Find_(node.GetLeft(), str);
	else
		if (str > node.key())
			(*this).Find(node.GetRight(), str);
		else
			return node;
}
template<class U, class T>
AVL_iterator<U, T> AVLTree<U, T>::Find(const U &str) {
	if (!(*this).find())
		return AVL_iterator<U, T>(NULL);
	else 
		return (*this).Find_(_root, str);
}
template<class U, class T>
void AVLTree<U, T>::Destruct(AVLNode<U, T> **node) {
	if (*node != NULL) {
		(*this).Destruct(&((*node)->_left));
		(*this).Destruct(&((*node)->_right));
		std::cout << "*node before = " << *node << std::endl;
		std::cout << (*node)->_key << std::endl;
		delete *node;
		std::cout << "*node = " << *node << std::endl;
		std::cout << "node = " << node << std::endl;
		std::cout << "true" << (*node)->_key << "true" << std::endl;
	}
}

template<class U, class T>
AVLTree<U, T>::~AVLTree() {
	std::cout << "DESTRUCTION" << std::endl;
	(*this).Destruct(&_root);
}
template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::find_(AVLNode<U, T> *node, const U &str) {
//	std::cout << "FIND" << std::endl;
//	std::cout << "_root -> _key = " << _root->_key << std::endl;
	if (node == NULL)
		return NULL;
	if (str < node->_key)
		(*this).find_(node->_left, str);
	else
		if (str > node->_key)
			(*this).find_(node->_right, str);
		else
			return node;
}

template<class U, class T>
bool AVLTree<U, T>::find(const U &str) {
	return ((*this).find_(_root, str) != NULL);
}

template<class U, class T>
AVLNode<U, T> **AVLTree<U, T>::insert_(AVLNode<U, T> **node, const U &str,T value) {
	if (*node == NULL) {
		*node = new AVLNode<U, T>(str, value);
//		std::cout << "*node = " << (*node) << std::endl;
//		std::cout << "node->_key = " << (*node)->_key << std::endl;
		return node;
	}
	if (*node != NULL) {
		if (str <= (*node)->_key){
//			std::cout << "<=" << std::endl;
			(*node)->_left = *((*this).insert_(&((*node)->_left), str, value));		
		}
		else {
//			std::cout << ">" << std::endl;
			(*node)->_right = *((*this).insert_(&((*node)->_right), str, value));
		}
		*node = *((*node)->Balance());
		return node;
	}
}

template<class U, class T>
void AVLTree<U, T>::insert(const U &str, T value) {
//		std::cout << "INSERT" << std::endl;
//		std::cout << "_root = " << _root << std::endl;
//		std::cout << "_root BF = " << _root->BalanceFactor() << std::endl;
		(*this).insert_(&_root, str, value);
//		std::cout << "_root = " << _root << std::endl;
//		std::cout << "_root->_key = " <<_root->_key << std::endl;
		++_size;
}

template<class U, class T>
AVLNode<U, T> **AVLTree<U, T>::DeleteVertex_(AVLNode<U, T> **node, const U &str) {
//	std::cout << "DELETE_" << std::endl;
	if (str < (*node)->_key)
		(*node)->_left = *((*this).DeleteVertex_(&((*node)->_left), str));
	else
		if (str > (*node)->_key)
			(*node)->_right = *((*this).DeleteVertex_(&((*node)->_right), str));
		else {
			AVLNode<U, T> **l = &((*node)->_left);
			AVLNode<U, T> **r = &((*node)->_right);
			delete *node;
			if (*r == NULL)
				return l;
			AVLNode<U, T> *min = (*r)->findMin();
			min->_right = (*r)->deleteMin();
			min->_left = *l;
			*node = *(min->Balance());
			return node;
		}	
	(*node)->Balance();
	return node;	
}

template<class U, class T>
void AVLTree<U, T>::DeleteVertex(const U &str) {
//	std::cout << "DELETE" << std::endl;
	if ((*this).find(str)) {
		(*this).DeleteVertex_(&_root, str);
		--_size;
//		std::cout << "_root key = " << _root->_key << std::endl;
//		std::cout << "size = " << _size << std::endl;
	}
	else
		throw 3;
}
template<class U, class T>
void AVLTree<U, T>::print_(AVLNode<U, T> *node, int lvl, T value, char c) {
	if (node == NULL)
		return;
	for (int i = 0; i < lvl; i++)
		std::cout << "       ";
	std::cout << "|" << value << ", " << c << "|" << "(" << node->_key << ", " << node->_value << ")" << "\n";
	(*this).print_(node->_left, lvl - 2, node->_value, 'L');
	(*this).print_(node->_right, lvl + 2, node->_value, 'R');
}
template<class U, class T>
void AVLTree<U, T>::AVLPrint() {
	(*this).print_(_root, _size, 777, 'G');
}
#endif
