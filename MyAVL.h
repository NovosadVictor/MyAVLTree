#ifndef _MYAVL_H_
#define _MYAVL_H_
#include "MyIterator.h"
#include <exception>

template <class U, class T>
class AVLTree {
public:
	AVLTree() : _root(NULL), _size(0) {}
	~AVLTree();
	void insert(const U &str,T value);
	AVLNode<U, T> **insert_(AVLNode<U, T> **node, const U &str, T value);
	void DeleteVertex(const U &str);
	AVLNode<U, T> **DeleteVertex_(AVLNode<U, T> **node, const U &str);
	AVLNode<U, T> *find_(AVLNode<U, T> *node, const U &str);
	bool find(const U &str);
	AVL_iterator<U, T> GetMin();
	AVL_iterator<U, T> GetMax();
	AVLNode<U, T> *GetMin_(AVLNode<U, T> *other);
        AVLNode<U, T> *GetMax_(AVLNode<U, T> *other);
	AVL_iterator<U, T> GetNext(AVL_iterator<U, T> it);
	AVLNode<U, T> *next(const U& str);
	void Destruct(AVLNode<U, T> **node);
	AVL_iterator<U, T> Find_(AVL_iterator<U, T> node, const U &str);
	AVL_iterator<U, T> Find(const U &str);
	AVL_iterator<U, T> GetRoot() { AVL_iterator<U, T> it(_root); return it; }
	size_t size() { return _size; }
	void print_(AVLNode<U, T> *node, int lvl, T value, char c);
	void AVLPrint();
	AVLNode<U, T> *_root;
private:
	size_t _size;
};

template<class U, class T>
AVL_iterator<U, T> AVLTree<U, T>::GetNext(AVL_iterator<U, T> it) {
	return it = AVL_iterator<U, T>(next((it.node_)->_key));
}
template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::next(const U& str) {
	AVLNode<U, T> *cur = _root;
	AVLNode<U, T> *suc = NULL;
	while (cur != NULL) {
		if (cur->_key > str) {
			suc = cur;
			cur = cur->_left;
		}
		else
			cur = cur->_right;
	}
	return suc;
}
template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::GetMin_(AVLNode<U, T> *other) {
	if (other->_left == NULL)
		return other;
	return GetMin_(other->_left);
}
template<class U, class T>
AVL_iterator<U, T> AVLTree<U, T>::GetMin() {
	return AVL_iterator<U, T>(GetMin_(_root));
}
template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::GetMax_(AVLNode<U, T> *other) {
        if (other->_right == NULL)
                return other;
        return GetMax_(other->_right);
}
template<class U, class T>
AVL_iterator<U, T> AVLTree<U, T>::GetMax() {
        return AVL_iterator<U, T>(GetMax_(_root));
}	
template<class U, class T>
AVL_iterator<U, T> AVLTree<U, T>::Find_(AVL_iterator<U, T> node, const U &str) {
	if (str < node.key())
		Find_(node.GetLeft(), str);
	else
		if (str > node.key())
			Find(node.GetRight(), str);
		else
			return node;
}
template<class U, class T>
AVL_iterator<U, T> AVLTree<U, T>::Find(const U &str) {
	if (!find())
		return AVL_iterator<U, T>(NULL);
	else 
		return Find_(_root, str);
}
template<class U, class T>
void AVLTree<U, T>::Destruct(AVLNode<U, T> **node) {
	if (*node != NULL) {
		Destruct(&((*node)->_left));
		Destruct(&((*node)->_right));
		delete *node;
	}
}

template<class U, class T>
AVLTree<U, T>::~AVLTree() {
	Destruct(&_root);
}
template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::find_(AVLNode<U, T> *node, const U &str) {
	if (node == NULL)
		return NULL;
	if (str < node->_key) {
		find_(node->_left, str);
		return node;
	}
	else
		if (str > node->_key) {
			find_(node->_right, str);
			return node;
		}
		else
			return node;
}

template<class U, class T>
bool AVLTree<U, T>::find(const U &str) {
	return (find_(_root, str) != NULL);
}

template<class U, class T>
AVLNode<U, T> **AVLTree<U, T>::insert_(AVLNode<U, T> **node, const U &str,T value) {
	if (*node == NULL) {
		*node = new AVLNode<U, T>(str, value);
		return node;
	}
	else {
		if (str <= (*node)->_key)
			(*node)->_left = *(insert_(&((*node)->_left), str, value));		
		else 
			(*node)->_right = *(insert_(&((*node)->_right), str, value));
		*node = ((*node)->Balance());
		return node;
	}
}

template<class U, class T>
void AVLTree<U, T>::insert(const U &str, T value) {
		insert_(&_root, str, value);
		++_size;
}

template<class U, class T>
AVLNode<U, T> **AVLTree<U, T>::DeleteVertex_(AVLNode<U, T> **node, const U &str) {
	if (str < (*node)->_key)
		(*node)->_left = *(DeleteVertex_(&((*node)->_left), str));
	else
		if (str > (*node)->_key)
			(*node)->_right = *(DeleteVertex_(&((*node)->_right), str));
		else {
			AVLNode<U, T> **l = &((*node)->_left);
			AVLNode<U, T> *_l = (*node)->_left;
			AVLNode<U, T> *r = ((*node)->_right);
			delete *node;
			*l = _l;
			if (r == NULL)
				return l;
			AVLNode<U, T> *min = (r)->findMin();
			min->_right = (r)->deleteMin();
			min->_left = *l;
			*node = (min->Balance());
			return node;
		}	
	(*node)->Balance();
	return node;	
}

template<class U, class T>
void AVLTree<U, T>::DeleteVertex(const U &str) {
	if (find(str)) {
		DeleteVertex_(&_root, str);
		--_size;
	}
	else
		throw 3;
}
template<class U, class T>
void AVLTree<U, T>::print_(AVLNode<U, T> *node, int lvl, T value, char c) {
	if (node == NULL)
		return;
	for (int i = 0; i < lvl; i++)
		std::cout << "     ";
	std::cout << "|" 
        << node->BalanceFactor() 
        << ", " << value
        << ", " << c
        << "|" << "("
        << node->_key
        << ", " << node->_value << ")" << "\n";
	print_(node->_left, lvl - 2, node->_value, 'L');
	print_(node->_right, lvl + 2, node->_value, 'R');
}
template<class U, class T>
void AVLTree<U, T>::AVLPrint() {
	print_(_root, _size, 0, '0');
}
#endif
