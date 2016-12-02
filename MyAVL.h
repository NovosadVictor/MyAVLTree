#ifndef _MYAVL_H_
#define _MYAVL_H_
#include "MyAVLNode.h"
#include "MyQueue.h"
#include <exception>


template<class U, class T>
AVLNode<U, T> *Next(AVLNode<U, T> *root, const U &str);

template <class U, class T>
class AVLTree {
public:
	class AVL_iterator {
	public:
		AVL_iterator(const AVLTree<U, T> &other) {
			node_ = NULL;
			root_ = other._root;
		}
		AVL_iterator() : node_(NULL), root_(NULL) {}
		AVL_iterator(const AVLTree<U, T> &Tr, AVLNode<U, T> *node) {
			root_ = Tr._root;
			node_ = node;
		}
		AVL_iterator(const AVL_iterator &other) : node_(other.node_), root_(other.root_) {}
		AVL_iterator(AVLNode<U, T> *other) : node_(other) {}
		AVLNode<U, T> operator*() { return *node_; }
		AVL_iterator GetLeft() {
			if (node_->_left) {
				AVL_iterator it(node_->_left);
				return it;
			}
		}
		AVL_iterator GetRight() {
			if (node_->_right) {
                       		AVL_iterator it(node_->_right);
                        	return it;
			}
                }
		bool operator==(const AVL_iterator &other) {
			return node_ == other.node_;
		}
		bool operator<(const AVL_iterator &other) {
			return node_ < other.node_;
		}
		bool operator!=(const AVL_iterator &other) {
			return node_ != other.node_;
		}
		AVL_iterator &operator=(const AVL_iterator &other) {
			node_ = other.node_;;
			return *this;
		}
		AVL_iterator &operator++()  {
			node_ =  Next(root_, node_->_key);
			return *this;
		}
		AVL_iterator operator--()  {
			node_ = Prev(root_, node_->_key);
			return *this;
		}
		U key() const {
			if (node_ != NULL)
				return node_->_key;
			throw 1;
		}
		T value() const {
			if (node_ != NULL)
				return node_->_value;
			throw 2;
		}
		AVLNode<U, T> *node_;
		AVLNode<U, T> *root_;
	};
	AVLTree() : _root(NULL), _size(0) {}
	AVLTree(const AVLTree<U, T> &other);
	~AVLTree();
	void insert(const U &str,T value);
	T &operator[](const U &str);
	AVLTree<U, T> &operator=(const AVLTree<U, T> &other);
	void AVLSort();
	AVLNode<U, T> **insert_(AVLNode<U, T> **node, const U &str, T value);
	void DeleteVertex(const U &str);
	AVLNode<U, T> **DeleteVertex_(AVLNode<U, T> **node, const U &str);
	AVLNode<U, T> *find_(AVLNode<U, T> *node, const U &str);
	bool find(const U &str);
	AVLNode<U, T> *GetMin_(AVLNode<U, T> *other) const;
        AVLNode<U, T> *GetMax_(AVLNode<U, T> *other) const;
	AVL_iterator GetMin() const {
                AVL_iterator it(GetMin_(_root));
		return it;
        }
        AVL_iterator GetMax() const {
       	        AVL_iterator it(GetMax_(_root));
		return it;
        }
        AVL_iterator GetRoot() const { 
		AVL_iterator it(_root);
		return it;
	}
	AVL_iterator GetNext(const AVL_iterator &it) const {
		AVL_iterator _it(next(it.key()));
		return _it;
	}
        AVL_iterator GetPrev(const AVL_iterator &it) const {
                AVL_iterator _it(*this, prev(it.key()));
		return _it;
        }
	AVLNode<U, T> *next(const U &str) const;
        AVLNode<U, T> *prev(const U &str) const;
	void Destruct(AVLNode<U, T> **node);
	AVL_iterator Find_(AVL_iterator node, const U &str) {
		if (str < node.key())
			Find_(node.GetLeft(), str);
		else
			if (str > node.key())
				Find_(node.GetRight(), str);
			else
				return node;
	}
	AVL_iterator Find(const U &str) {
		if (!find())
			AVL_iterator(NULL);
		else 
			return Find_(_root, str);
	}
	size_t size() { return _size; }
	void print_(AVLNode<U, T> *node, int lvl, T value, char c) const;
	void AVLPrint() const;
	queue<T> GetQueue();
private:
	AVLNode<U, T> *_root;
	size_t _size;
};


template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::prev(const U& str) const {
        AVLNode<U, T> *cur = _root;
        AVLNode<U, T> *suc = NULL;
        while (cur != NULL) {
                if (cur->_key < str) {
                        suc = cur;
                        cur = cur->_right;
                }
                else
                        cur = cur->_left;
        }
        return suc;
}

template<class U, class T>
void AVLTree<U, T>::AVLSort() {
	if (_size == 0)
		throw 3;
	queue<T> Q = GetQueue();
	Q.QueueSort();
	AVL_iterator it(*this);
	for(it = GetMin(); it != GetMax(); ++it) {
		(it.node_)->_value = Q.front();
		Q.pop();
	}
	(it.node_)->_value = Q.front();
	Q.pop();
}
template<class U, class T>
queue<T> AVLTree<U, T>::GetQueue() {
	AVL_iterator it;
	queue<T> Q;
	for (it = GetMin(); it != GetMax(); it = GetNext(it))
		Q.push((it.node_)->_value);
	Q.push((it.node_)->_value);
	return Q;
}
template<class U, class T>
T &AVLTree<U, T>::operator[](const U &str) {
	if (!find(str))
		throw 4;
	AVL_iterator it = Find(str);
	return it.value();
} 
template<class U, class T>
AVLTree<U, T>::AVLTree(const AVLTree<U, T> &other) {
	_root = NULL;
	_size = 0;
	*this = other;
}
template<class U, class T>
AVLTree<U, T> &AVLTree<U, T>::operator=(const AVLTree<U, T> &other) {
	if (_size > 0)
		Destruct(&_root);
	_root = NULL;
	AVLNode<U, T> *Cur = other._root;
	AVLNode<U, T> *right = other._root;
	while (Cur->_left != NULL)
		Cur = Cur->_left;
	while (right->_right != NULL)
		right = right->_right;
	while (Cur != right) {
		insert(Cur->_key, Cur->_value);
		Cur = other.next(Cur->_key);
	}
	insert(right->_key, right->_value);
	return *this;
}	
template<class U, class T>
AVLNode<U, T> *Next(AVLNode<U, T> *root, const U &str) {
	AVLNode<U, T> *cur = root;
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
AVLNode<U, T> *Prev(AVLNode<U, T> *root, const U &str) {
        AVLNode<U, T> *cur = root;
        AVLNode<U, T> *suc = NULL;
        while (cur != NULL) {
                if (cur->_key < str) {
                        suc = cur;
                        cur = cur->_right;
                }
                else
                        cur = cur->_left;
        }
        return suc;
}
template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::next(const U &str) const {
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
AVLNode<U, T> *AVLTree<U, T>::GetMin_(AVLNode<U, T> *other) const {
	if (other->_left == NULL)
		return other;
	return GetMin_(other->_left);
}
template<class U, class T>
AVLNode<U, T> *AVLTree<U, T>::GetMax_(AVLNode<U, T> *other) const{
        if (other->_right == NULL)
                return other;
        return GetMax_(other->_right);
}
template<class U, class T>
void AVLTree<U, T>::Destruct(AVLNode<U, T> **node) {
	if (*node != NULL) {
		Destruct(&((*node)->_left));
		Destruct(&((*node)->_right));
		delete *node;
		--_size;
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
		*node = (*node)->Balance();
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
	*node = (*node)->Balance();
	return node;	
}

template<class U, class T>
void AVLTree<U, T>::DeleteVertex(const U &str) {
	if (find(str)) {
		DeleteVertex_(&_root, str);
		--_size;
	}
	else
		throw 5;
}
template<class U, class T>
void AVLTree<U, T>::print_(AVLNode<U, T> *node, int lvl, T value, char c) const {
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
void AVLTree<U, T>::AVLPrint() const{
	if (_size == 0)
		throw 6;
	print_(_root, _size, 0, '0');
}
#endif
