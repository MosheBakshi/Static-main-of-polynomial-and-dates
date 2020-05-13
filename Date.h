#ifndef _DATE_H
#define _DATE_H
#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"
using namespace std;

class Date : public IPrintable, public IComparable<Date>//inheritance
{
	friend istream& operator >> (istream& in, Date& reciever);
	friend ostream& operator << (ostream& out, Date& givver);
public:
	//constructors & distructors
	Date(int d=0, int m=0, int y=0);// using default data if no info added
	Date(const Date& other); //in case object passed into the object
	~Date();
	//operators overloading
	Date& operator = (const Date& another);
	bool operator<(const Date& Compared)override;
	bool operator>(const Date& Compared)override;
	bool operator<=(const Date& Compared)override;
	bool operator>=(const Date& Compared)override;
	bool operator==(const Date& Compared)override;
	bool operator!=(const Date& Compared)override;
	void isValid();

	//self functions
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	bool ifFlag()const;
	string SendError()const;
private:
	int Day, Month, Year;
	string Error;
	bool ErrFlag;
};


#endif // !_DATE_H
