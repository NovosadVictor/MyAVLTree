#ifndef _MYAVLNODE_H_
#define _MYAVLNODE_H_
#include <string>

template<class U = std::string, class T>
class AVLNode {
public:
	AVLNode() : _left(NULL), _right(NULL), _height(0) {}
	AVLNode(const U &key, T value) : _key(key), _value(value) , _height(1) , _left(NULL), _right(NULL) {}
	AVLNode(const AVLNode<U, T> &other) : _key(other._key), _value(other._value), _left(other._left), _right(other._right), _height(other._height) {}
	AVLNode<U, T> *LeftRotate();
	AVLNode<U, T> *RightRotate();
	AVLNode<U, T> *Balance();
	AVLNode<U, T> *findMin();
	AVLNode<U, T> *deleteMin();
	int BalanceFactor();
	size_t FixHeight();
private:
	U _key;
	T _value;
	AVLNode<U, T> *_left;
	AVLNode<U, T> *_right;
	size_t _height;
};



template<class U = std::string, class T>
size_t AVLNode<U, T>::FixHeight() {
	size_t H_l = _left->_height;
	size_t H_r = _right->_height;
	return (H_l > H_r ? H_l : H_r) + 1;
}

template<class U = std::string, class T>
AVLNode<U, T> *AVLNode<U, T>::RightRotate() {
	AVLNode<U, T> *L = _left;
	_left = L->_right;
	L->_right = this;
	*this.FixHeight();
	L->FixHeight();
	return L;
}

template<class U = std::string, class T>
AVLNode<U, T> *AVLNode<U, T>::LeftRotate() {
	AVLNode<U, T> *R = _right;
	_right = R->_left;
	R->_left = this;
	*this.FixHeight();
	R->_FixHeight();
	return R;
}

template<class U = std::string, class T>
AVLNode<U, T> *AVLNode<U, T>::Balance() {
	*this.FixHeight();
	if (*this.BalanceFactor() == 2) {
		if (_right->BalanceFactor() < 0)
			_right = _right->RightRotate();
		return *this.LeftRotate();
	}
	else {
		if (_left->BalanceFactor() > 0)
			_left = _left->LeftRotate();
		return *this.RightRotate();
	}
	return *this;
}

template<class U = std::string, class T>
int AVLNode<std::string, T>::BalanceFactor() {
	int r_height = _right == NULL ? 0 : _right->_height;
	int l_height = _left == NULL ? 0 : _left->_height;
	return r_height - l_height;
}

template<class U = std::string, class T>
AVLNode<U, T> *AVLNode<U, T>::findMin() {
	return _left ? _left->findMin() : _left;
}

template<class U = std::string, class T>
AVLNode<U, T> *AVLNode<U, T>::deleteMin() {
	if (_left == NULL)
		return _right;
	else
		_left = _left->deleteMin();
	return *this.Balance();
}

#endif
