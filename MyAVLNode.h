#ifndef _MYAVLNODE_H_
#define _MYAVLNODE_H_
#include <iostream>

template<class U, class T>
class AVLNode {
public:
	AVLNode();
	AVLNode(const U &key, const T &value);
	AVLNode<U, T> *LeftRotate();
	AVLNode<U, T> *RightRotate();
	AVLNode<U, T> *Balance();
	AVLNode<U, T> *findMin();
	AVLNode<U, T> *deleteMin();
	int BalanceFactor();
	size_t FixHeight();
	U _key;
	T _value;
	AVLNode<U, T> *_left;
	AVLNode<U, T> *_right;
	size_t _height;
};

template<class U, class T>
AVLNode<U, T>::AVLNode() {
	_left = NULL;
	_right = NULL;
	_height = 0;
}
template<class U, class T>
AVLNode<U, T>::AVLNode(const U &key, const T &value) {
	_key = key;
	_value = value;
	_height = 1;
	_left = NULL;
	_right = NULL;
}
template<class U, class T>
size_t AVLNode<U, T>::FixHeight() {
	size_t H_l = _left ? _left->FixHeight() : 0;
	size_t H_r = _right ? _right->FixHeight() : 0;
	return (H_l > H_r ? H_l : H_r) + 1;
}

template<class U, class T>
AVLNode<U, T> *AVLNode<U, T>::RightRotate() {
	AVLNode<U, T> *L = _left;
	_left = L->_right;
	L->_right = this;
	FixHeight();
	L->FixHeight();
	return L;
}

template<class U, class T>
AVLNode<U, T> *AVLNode<U, T>::LeftRotate() {
	AVLNode<U, T> *R = _right;
	_right = R->_left;
	R->_left = this;
	FixHeight();
	R->FixHeight();
	return R;
}

template<class U, class T>
AVLNode<U, T> *AVLNode<U, T>::Balance() {
	FixHeight();
	if (BalanceFactor() == 2) {
		if (_right->BalanceFactor() < 0)
			_right = _right->RightRotate();
		return LeftRotate();
	}
	if (BalanceFactor() == -2) {
		if (_left->BalanceFactor() > 0)
			_left = _left->LeftRotate();
		return RightRotate();
	}
	return this;
}

template<class U, class T>
int AVLNode<U, T>::BalanceFactor() {
	if (this == NULL)
		return 0;
	int r_height = _right ? _right->FixHeight() : 0;
	int l_height = _left ? _left->FixHeight() : 0;
	return r_height - l_height;
}

template<class U, class T>
AVLNode<U, T> *AVLNode<U, T>::findMin() {
	return _left ? _left->findMin() : this;
}

template<class U, class T>
AVLNode<U, T> *AVLNode<U, T>::deleteMin() {
	if (_left == NULL)
		return _right;
	_left = _left->deleteMin();
	return Balance();
}
#endif
