#ifndef _MYAVLNODE_H_
#define _MYAVLNODE_H_
#include <iostream>

template<class U, class T>
class AVLNode {
public:
	AVLNode() : _left(NULL), _right(NULL), _height(0) {}
	AVLNode(const U &key, T value) : _key(key), _value(value) , _height(1) , _left(NULL), _right(NULL) {}
//	AVLNode(const AVLNode<U, T> &other) : _key(other._key), _value(other._value), _left(other._left), _right(other._right), _height(other._height) {}
	AVLNode<U, T> **LeftRotate();
	AVLNode<U, T> **RightRotate();
	AVLNode<U, T> **Balance();
	AVLNode<U, T> *findMin();
	AVLNode<U, T> *deleteMin();
	int BalanceFactor();
	size_t FixHeight();
	U _key;
	T _value;
	AVLNode<U, T> *_left;
	AVLNode<U, T> *_right;
	size_t _height;
//	~AVLNode();
};


//template<class U, class T>
//AVLNode<U, T>::~AVLNode<U, T>() {
//	if (_left)
//		delete _left;
//	if (_right)
//		delete _right;
//}
template<class U, class T>
size_t AVLNode<U, T>::FixHeight() {
	size_t H_l = _left ? _left->FixHeight() : 0;
	size_t H_r = _right ? _right->FixHeight() : 0;
	return (H_l > H_r ? H_l : H_r) + 1;
}

template<class U, class T>
AVLNode<U, T> **AVLNode<U, T>::RightRotate() {
	AVLNode<U, T> *L = _left;
//	std::cout << "L = " << L << std::endl;
//	std::cout << "L left = " << L->_left << std::endl;
//	std::cout << "L right = " << L->_right << std::endl;
	_left = L->_right;
	L->_right = this;
	(*this).FixHeight();
	L->FixHeight();
	AVLNode<U, T> **This = new AVLNode<U, T>*;
	*This = L;
	AVLNode<U, T> **_T = This;
	*This = NULL;
	delete *This;
	*_T = L;
	return _T;
}

template<class U, class T>
AVLNode<U, T> **AVLNode<U, T>::LeftRotate() {
	AVLNode<U, T> *R = _right;
	_right = R->_left;
	R->_left = this;
	(*this).FixHeight();
	R->FixHeight();
	AVLNode<U, T> **This = new AVLNode<U, T>*;
	*This = R;
	AVLNode<U, T> **_T = This;
	*This = NULL;
	delete *This;
	*_T = R;
	return _T;
}

template<class U, class T>
AVLNode<U, T> **AVLNode<U, T>::Balance() {
	(*this).FixHeight();
	if ((*this).BalanceFactor() == 2) {
//		std::cout << "BF == 2 " << std::endl;
		if (_right->BalanceFactor() < 0)
			_right = *(_right->RightRotate());
		return (*this).LeftRotate();
	}
	if ((*this).BalanceFactor() == -2) {
//		std::cout << "BF == -2 " << std::endl;
		if (_left->BalanceFactor() > 0)
			_left = *(_left->LeftRotate());
		return (*this).RightRotate();
	}
	AVLNode<U, T> **This = new AVLNode<U, T>*;
	*This = this;
	AVLNode<U, T> **_T = This;
//	std::cout << "*T = " << *_T << std::endl;
	*This = NULL;
//	std::cout << "*T = " << *_T << std::endl;
	delete *This;
	*_T = this;
//	std::cout << "*T after = " << *_T << std::endl;
	return _T;
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
	return *((*this).Balance());
}
#endif
