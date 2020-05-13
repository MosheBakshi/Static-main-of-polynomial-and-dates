#ifndef _IComparable_H
#define _IComparable_H
#include <iostream>
#include <iomanip>

using namespace std;
template <class T>
class IComparable
{
public:
	virtual ~IComparable() {};
	virtual bool operator<(const T& Compared)= 0;
	virtual bool operator>(const T& Compared)= 0;
	virtual bool operator<=(const T& Compared)= 0;
	virtual bool operator>=(const T& Compared)= 0;
	virtual bool operator==(const T& Compared)= 0;
	virtual bool operator!=(const T& Compared)= 0;
};

#endif // ! _IComparable_H
