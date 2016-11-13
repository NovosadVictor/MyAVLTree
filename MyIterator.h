#ifndef _MYITERATOR_H_
#define _MYITERATOR_H_
#include <string>

template<class U = std::string, class T>
class AVL_iterator {
public:
	AVL_iterator() : _node(NULL) {}
	AVL_iterator(const AVL_iterator &other) : _node(other._node) {}
	AVL_iterator(AVLNode<U, T> *other) : _node(other) {}
	AVLNode<U, T> operator*() { return *_node; }
	AVL_iterator< & operator++() { ++_node; return *this; }
	bool operator==(const AVL_iterator &other);
	bool operator<(const AVL_iterator &other);
	bool operator!=(const AVL_iterator &other);
	AVL_iterator& operator=(const AVL_iterator &other);
private:
	AVLNode *_node;
};


template<class U = std::string, class T>
bool AVL_iterator<U, T>::operator==(const AVL_iterator &other) {
	return (_node == other._node);
}
template<class U = std::string, class T>
bool AVL_iterator<U, T>::operator!=(const AVL_iterator &other) {
	return (_node != other._node);
}
template<class U = std::string, class T>
bool AVL_iterator<U, T>::operator<(const AVL_iterator &other) {
	return (_node < other._node);
}
template<class U = std::string, class T>
AVL_iterator& AVL_iterator<U, T>::operator=(const AVL_iterator> &other) {
	_node = other._node;
	return *this;
}

#endif
