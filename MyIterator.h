#ifndef _MYITERATOR_H_
#define _MYITERATOR_H_
#include "MyAVLNode.h"

template<class U, class T>
class AVL_iterator {
public:
	AVL_iterator() : node_(NULL) {}
	AVL_iterator(const AVL_iterator<U, T> &other) : node_(other.node_) {}
	AVL_iterator(AVLNode<U, T> *other) : node_(other) {}
	AVLNode<U, T> operator*() { return *node_; }
	bool operator==(const AVL_iterator<U, T> &other);
	bool operator<(const AVL_iterator<U, T> &other);
	bool operator!=(const AVL_iterator<U, T> &other);
	AVL_iterator<U, T> &operator=(const AVL_iterator<U, T> &other);
	AVL_iterator<U, T> GetLeft();
	AVL_iterator<U, T> GetRight();
	AVLNode<U, T> *next(const U& str);
	AVL_iterator<U, T> operator++();
	U key() { return node_->_key; }
	T value() { return node_->_value; }
	AVLNode<U, T> *node_;
};

template<class U, class T>
AVLNode<U, T> *AVL_iterator<U, T>::next(const U &str) {
	AVLNode<U, T> *cur = _root;/////вот тут ннадо что-то сделать, как-то передать сюда указатель на корень дерева
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
AVL_iterator<U, T> AVL_iterator<U, T>::operator++() {
	return AVL_iterator<U, T>(next(node_->_key));	
}
template<class U, class T>
AVL_iterator<U, T> AVL_iterator<U, T>::GetLeft() {
	node_ = node_->_left;
	return *this;
}
template<class U, class T>
AVL_iterator<U, T> AVL_iterator<U, T>::GetRight() {
	node_ = node_->_right;
	return *this;	
}
template<class U, class T>
bool AVL_iterator<U, T>::operator==(const AVL_iterator<U, T> &other) {
	return (node_ == other._node_);
}
template<class U, class T>
bool AVL_iterator<U, T>::operator!=(const AVL_iterator<U, T> &other) {
	return node_ != other.node_;
}
template<class U, class T>
bool AVL_iterator<U, T>::operator<(const AVL_iterator<U, T> &other) {
	return node_ < other.node_;
}
template<class U, class T>
AVL_iterator<U, T> &AVL_iterator<U, T>::operator=(const AVL_iterator<U, T> &other) {
	node_ = other.node_;
	return *this;
}

#endif
