#ifndef _MYITERATOR_H_
#define _MYITERATOR_H_
#include "MyAVLNode.h"

template<class U, class T>
class AVL_iterator {
public:
	AVL_iterator() : _node(NULL) {}
	AVL_iterator(const AVL_iterator &other) : _node(other._node) {}
	AVL_iterator(AVLNode<U, T> *other) : _node(other) {}
	AVLNode<U, T> operator*() { return *_node; }
//	AVL_iterator<U, T> &operator++();
	bool operator==(const AVL_iterator<U, T> &other);
	bool operator<(const AVL_iterator<U, T> &other);
	bool operator!=(const AVL_iterator<U, T> &other);
	AVL_iterator<U, T> &operator=(const AVL_iterator<U, T> &other);
	AVL_iterator<U, T> &GetLeft();
	AVL_iterator<U, T> &GetRight();
//	AVL_iterator<U, T> &GetNext();
	U key() { return _node->_key; }
	T value() { return _node->_value; }
private:
	AVLNode<U, T> *_node;
};

//template<class U, class T>
//AVL_iterator<U, T> &AVL_iterator<U, T>::GetNext() {
//	if (_node->_left == NULL)
//		if (_node->_right != NULL)
//			return (*this).GetRight();
//		else
//			
//	else
//		return (*this)>GetLeft();	
//
//}
template <class U, class T>
AVL_iterator<U, T> &AVL_iterator<U, T>::GetLeft() {
	_node = _node->_left;
	return *this;
}
template<class U, class T>
AVL_iterator<U, T> &AVL_iterator<U, T>::GetRight() {
	_node = _node->_right;
	return *this;	
}
//template<class U, class T>
//AVL_iterator<U, T> &AVL_iterator<U, T>::operator++() {
//	return (*this).GetNext();
//}
template<class U, class T>
bool AVL_iterator<U, T>::operator==(const AVL_iterator<U, T> &other) {
	return (_node == other._node);
}
template<class U, class T>
bool AVL_iterator<U, T>::operator!=(const AVL_iterator<U, T> &other) {
	return _node != other._node;
}
template<class U, class T>
bool AVL_iterator<U, T>::operator<(const AVL_iterator<U, T> &other) {
	return _node < other._node;
}
template<class U, class T>
AVL_iterator<U, T> &AVL_iterator<U, T>::operator=(const AVL_iterator<U, T> &other) {
	_node = other._node;
	return *this;
}

#endif
