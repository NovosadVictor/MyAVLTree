#ifndef _MYLIST_H_
#define _MYLIST_H_
#include <iosfwd>
template<class T>
struct list
{
	T _x;
	list<T> *_next;
	list() : _next(NULL){}
};

#endif
