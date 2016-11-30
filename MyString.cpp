#include "MyString.h"
#include <iostream>
#include <exception>
#include <string.h>
String::String() 
{
        _buf = new char[1];
        _len = 0;
	if (!_buf)
		throw std::bad_alloc();
	_buf[0] = '\0';
}
String::String(const String &s)
{
         _len = s._len;
        _buf = new char[s._len + 1];
	if (!_buf)
		throw std::bad_alloc();
	memcpy(_buf, s._buf, _len + 1);
}
String::String(const char *c)
{
       _len = strlen(c);
       _buf = new char[strlen(c) + 1];
	if (!_buf)
		throw std::bad_alloc();
	memcpy(_buf, c, _len + 1);
}
String::String(size_t size)
{       
        _buf = new char[size + 1];
        _len = size;
	if (!_buf)
		throw std::bad_alloc();
	_buf[size] = '\0';
}
String::~String()
{
	delete[]_buf;
}
size_t String::size()
{
	return _len;
}
char& String::operator[](size_t i)
{
	if (i >= _len)
		throw 1;
	return _buf[i];
}
const char & String::operator[](size_t i) const
{
	return const_cast<String &>(*this)[i];
}
String& String::operator+=(const String &other)
{
	String s(_buf);
	delete[]_buf;
	_buf = new char[_len + other._len + 1];
	if (!_buf)
		throw std::bad_alloc();
	for (size_t i = 0; i < _len; ++i)
		_buf[i] = s._buf[i];
	for (size_t i = _len, j = 0; i < _len + other._len; ++i, ++j)
		_buf[i] = other._buf[j];
	_len += other._len;
	_buf[_len] = '\0';
	return *this;
}
String& String::operator=(const String &other)
{
	if ((*this) == other)
	    return *this;
        char *_b = new char[other._len + 1]; 
	delete[]_buf;
	if (!_b)
		throw std::bad_alloc();
        _buf = _b;
        _len = other._len;
	memcpy(_buf, other._buf, _len + 1);
	return *this;
}
bool String::operator==(const String &other)
{
	if (_len != other._len)
		return false;
	for (size_t i = 0; i < _len; ++i)
		if (_buf[i] != other._buf[i])
			return false;
	return true;
}
String operator+(const String &lhs,const String &rhs)
{
	String s(lhs._len + rhs._len);
	for (size_t i = 0; i < lhs._len; ++i)
		s._buf[i] = lhs._buf[i];
	for (size_t i = lhs._len, j = 0; i < lhs._len + rhs._len; ++i, ++j)
		s._buf[i] = rhs._buf[j];
	s._buf[lhs._len + rhs._len] = '\0';
	return s;
}
int String::contain(const char c)
{
	for (size_t i = 0; i < _len; ++i)
		if (_buf[i] == c)
			return i;
	return -1;
}
int String::contain(const String &s)
{
	for (size_t i = 0; i < _len; ++i)
		if ((_buf[i] == s[0]) && (i + s._len) <= _len)
		{
			bool r = true;
			for (size_t j = i + 1; j < i + s._len; ++j)
				if (_buf[j] != s[j - i])
				{
					r = false;
					break;
				}
			if (r)
			    return i;
		}
	return -1;
}
bool String::Delete(String &s)
{
	size_t count = (*this).contain(s);
	if (!count)
		return false;
	else
	{
		String s1;
		for (size_t i = 0; i < count; ++i)
			s1[i] = _buf[i];
		for (size_t i = count + s.size(); i < _len; ++i)
			s1[i] = _buf[i];
		_len -= s.size();
		return true;
	}
}
std::ostream& operator<<(std::ostream& os,const String &s)
{
	for (size_t i = 0; i < s._len; ++i)
		os << s._buf[i];
	return os;
}
bool operator<(const String &lhs, const String &rhs) {
	if (strcmp(lhs._buf,rhs._buf) < 0)
 		   return true;
	return false;
}
bool operator!=(const String &lhs, const String &rhs) {
	if (strcmp(lhs._buf, rhs._buf) != 0)
		return true;
	return false;
}
bool operator>(const String &lhs, const String &rhs) {
	if (strcmp(lhs._buf, rhs._buf) > 0)
		return true;
	return false;
}
bool operator<=(const String &lhs, const String &rhs) {
	if (strcmp(lhs._buf, rhs._buf) == 0 || lhs < rhs)
		return true;
	return false;
}
