#ifndef _Interval_H
#define _Interval_H
#include "IComparable.h"
#include "IPrintable.h"
#include "Date.h"
#include <iostream>
using namespace std;
template <class T>
class Interval
{
public:
	// CONSTRUCTORS //
	Interval();
	Interval(const T&,const T& );
	~Interval();
	// FUNCTIONS //
	bool isBefore(const Interval<T>&);
	bool isEmpty()const;
	bool isAfter(const Interval<T>&)const;
	bool intersects(const Interval<T>&);
	bool contains(const  T&)const;
	bool isValid()const;
	string getProblem()const;
	T getStart()const;
	T getEnd()const;
	// OPERATORS OVERLOADING //
	template<typename dif>
	friend ostream& operator << (ostream& out, const Interval<dif>& print);
	Interval<T>& operator&&(const Interval<T>& other) ;
	Interval<T>& operator||(const Interval<T>& other) ;

private:
	T Start,End;
	string Error;
	bool invalid;
};





// CONSTRUCTORS & DISTRUCTOR //
template <typename T>
Interval<T>::Interval()// EMPTY DATA
{
	invalid = 1;
	Error = "EMPTY";
}
template <typename T>
Interval<T>::Interval(const T& Strt, const T& Edge)
{
	Start = Strt;
	End = Edge;
	invalid = 0;
	Error = "EMPTY";
	if (Strt > Edge) { invalid = 1; Error = "Invalid interval"; } // if start higher then the end
	if (Strt == Edge) { invalid = 1; Error = "EMPTY"; } // if start & end are the same
}

template <typename T>
Interval<T>::~Interval() {
}

// FUNCTIONS //
template <typename T>
bool Interval<T>::isBefore(const Interval<T>& check)
{
	if ((!isValid() && !check.isValid() )&&
		this->End <= check.Start)
			return true;
	return false;
}

template <typename T>
bool Interval<T>::isEmpty()const
{
	string check = "EMPTY";
	int i = 0;
	while (check[i] != '\0')
	{
		if (check[i + 1] == '\0' && check[i] = Error[i]) return true;
		i++;
	}
	return false;
}

template <typename T>
bool Interval<T>::isAfter(const Interval<T>& check)const
{
	if ((!isValid() && !check.isValid() )&&
		this->Start >= check.End)
			return true;
	return false;
}

template <typename T>
bool Interval<T>::intersects(const Interval<T>& check)
{
	if ((this->Start == check.Start && this->End == check.End))
		return true;
	if (((this->Start < check.Start && check.Start < this->End) ||
		(this->Start < check.End && check.End < this->End)))
		return true;
	if ((!((check.Start < this->Start && this->Start < check.End)))) {
		if ((!((check.Start < this->End && this->End < check.End))))
			return false;
	}
	if ((this->Start > check.End || this->End < check.Start))
		return false;
	else
		return true;
}
/// DATA REPORTING FUNCTIONS//
template <typename T>
string Interval<T>::getProblem() const {return Error;}
template <typename T>
bool Interval<T>::contains(const T& check)const{if(this->Start < check && check < this->End) return true;return false;}
template <typename T>
bool Interval<T>::isValid()const{return (invalid == false) ? false : true;}
template <typename T>
T Interval<T>::getStart()const{return Start;}
template <typename T>
T Interval<T>::getEnd()const{return End;}

// OPERATORS OVERLOADING //
template <typename T>
Interval<T>& Interval<T>::operator||(const Interval<T>& other)  {
	bool Empty = 0;
	Interval<T>* answer;
	if ((isValid() && !other.isValid())) Empty = 1;
	if (!intersects(other)) Empty = 1;
	if (Empty)
		answer = new Interval<T>(Start, Start - 1);
	else {
		T S = (Start < other.getStart()) ? Start : other.getStart();
		T E = (End > other.getEnd()) ? End : other.getEnd();
		answer = new Interval<T>(S, E);
	}
	return *answer;
}

template <typename T>
Interval<T>& Interval<T>::operator&&(const Interval<T>& other) {
	bool Empty = 0;
	Interval<T>* answer;
	if ((isValid() && !other.isValid())) Empty = 1;
	if (!intersects(other)) Empty = 1;
	if (Empty)
		answer = new Interval<T>();
	else {
		T S = Start > other.getStart() ? Start : other.getStart();
		T E = End < other.getEnd() ? End : other.getEnd();
		answer = new Interval<T>(S, E);
	}
	return *answer;
}

template <typename T>
ostream& operator << (ostream& out, const Interval<T>& Data) {
	if (!Data.isValid())
		out << "(" << Data.Start << ", " << Data.End << ")";
	else
		out << Data.getProblem();
	return out;
}

#endif // ! _Interval_H
