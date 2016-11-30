#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iosfwd>

class String
{
public:
	String() ;
	String(const String &s);
	String(const char *c);
	String(size_t size);
	~String();
	size_t size();
	String& operator+=(const String &other);
	String& operator=(const String &other);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	bool operator==(const String &other);
	char& operator[](size_t i);
	const char& operator[](size_t i) const;
	friend String operator+(const String &lhs, const String &rhs);
	int contain(const char c);
	int contain(const String &s);
	bool Delete(String &s);
	friend std::ostream& operator<<(std::ostream& os,const String & s);
private:
	char *_buf;
	size_t _len;
};

#endif

