#ifndef _MYAVL_H_
#define _MYAVL_H_
#include <iostream>
#include "MyAVLNode.h"
//#include "MyIterator.h"
#include <exception>


template <class U = std::string, class T>
class AVLTree {
public:
	AVLTree() : _root(NULL), _size(0) {}
//	AVLTree(const AVLTree<U, T> &other);
	~AVLTree();
	AVLNode<U, T> *insert(const U &str,T value);
	AVLNode<U, T> *DeleteVertex(const U &str);
	AVLNode<U, T> *find(const U &str);
	AVL_iterator<U, T> FindIt(const U &str);
	size_t size() { return _size; }
private:
	AVLNode<U, T> *_root;
	AVLTree<U, T> *_left;
	AVLTree<U, T> *_right;
	size_t _size;
};

template<class U = std::string, class T>
AVLTree<U, T>::~AVLTree() {
	delete _root;
	delete _left;
	delete _right;
}
template<class U = std::string, class T>
AVLNode<U, T> *AVLTree<U, T>::find(const U &str) {
	AVLTree<U, T> *ROOT = this;
	if (ROOT == NULL)
		throw 1;
	if (ROOT->_root->_key == str)
		return ROOT->_root;
	while (ROOT->_root != NULL) {
		if (ROOT->_root->_key < str)
			ROOT->_left->find(str);
		else
			ROOT->_right->find(str);
	}
}

template<class U = std::string, class T>
AVLNode<U, T> *AVLNode<U, T>::insert(const U &str,T value) {
	AVLTree<U, T> *ROOT = this;
	if (ROOT == NULL) {
		ROOT->_root = new AVLNode<U, T>(str, value);
		return ROOT->_root;
	}
	else
		if (str <= ROOT->_root->_key)
			return ROOT->_left->insert(str, value);
		else
			return ROOT->_right->insert(str, value);
	ROOT->_root.Balance();
	++size;
	return ROOT->_root;
}

template<class U = std::string, class T>
AVLNode<U, T> *AVLNode<U, T>::DeleteVertex(const U &str) {
	AVLTree<U, T> *ROOT = this;
	if (ROOT == NULL)
		throw 3;
	else
		if (str < ROOT->_root->_key)
			ROOT->_left->DeleteVertex(str);
		else {
			if (str > ROOT->_root->_key)
				ROOT->_right->DeleteVertex(str);
			else
				AVLNode<U, T> *l = f->_left;
				AVLNode<U, T> *r = f->_right;
				delete f;
				if (r == NULL)
					return l;
				AVLNode<U, T> *min = r.findMin();
				min->_right = r->deleteMin();
				min->_left = l;
				return min.Balance();
		}
	ROOT->_root->Balance();
	--size;
	return ROOT->_root;	
}
		
#endif
