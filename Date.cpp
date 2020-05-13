#include "Date.h"
#include <iostream>
#include <iomanip>

Date::Date(int d, int m, int y) : Day(d), Month(m), Year(y) { isValid(); }
Date::Date(const Date& another)
{
	setDay(another.Day);
	setMonth(another.Month);
	setYear(another.Year);
	isValid();
}
Date::~Date() {}

Date& Date::operator=(const Date& other) {

	this->Day = other.Day;
	this->Month = other.Month;
	this->Year = other.Year;
	this->Error = other.Error;
	this->ErrFlag = other.ErrFlag;
	isValid();//for safety
	return *this;
}

bool Date::operator<(const Date& Compared)
{
	bool day = (this->Day < Compared.Day);
	bool month = (this->Month < Compared.Month);
	bool year = (this->Year < Compared.Year);
	bool EY = (this->Year = Compared.Year); //Equal YEAR
	bool EM = (this->Month = Compared.Month);//Equal MONTH
	if (year) { return true; }
	if (month && EY) { return true; }
	if (day && EM && EY) { return true; }
	return false;
}
bool Date::operator>(const Date& Compared)
{
	bool day = (this->Day > Compared.Day);
	bool month = (this->Month > Compared.Month);
	bool year = (this->Year > Compared.Year);
	bool EY = (this->Year = Compared.Year); //Equal YEAR
	bool EM = (this->Month = Compared.Month);//Equal MONTH
	if (year) { return true; }
	if (month && EY) { return true; }
	if (day && EM && EY) { return true; }
	return false;
}
bool Date::operator<=(const Date& Compared)
{
	bool day = (this->Day <= Compared.Day);
	bool month = (this->Month <= Compared.Month);
	bool year = (this->Year <= Compared.Year);
	bool EY = (this->Year == Compared.Year);//Equal YEAR
	bool EM = (this->Month == Compared.Month);//Equal MONTH
	if (year) { return true; }
	if (month && EY) { return true; }
	if (day && EM && EY) { return true; }
	return false;
}
bool Date::operator>=(const Date& Compared)
{
	bool day = (this->Day >= Compared.Day);
	bool month = (this->Month >= Compared.Month);
	bool year = (this->Year >= Compared.Year);
	bool EY = (this->Year = Compared.Year);//Equal YEAR
	bool EM = (this->Month = Compared.Month);//Equal Month
	if (year) { return true; }
	if (month && EY) { return true; }
	if (day && EM && EY) { return true; }
	return false;
}
bool Date::operator==(const Date& Compared)
{
	bool day = (this->Day == Compared.Day);
	bool month = (this->Month == Compared.Month);
	bool year = (this->Year == Compared.Year);
	if (day && month && year) { return true; }
	return false;
}
bool Date::operator!=(const Date& Compared)
{
	bool day = (this->Day != Compared.Day);
	bool month = (this->Month != Compared.Month);
	bool year = (this->Year != Compared.Year);
	if (day || month || year) {return true;}
	return false;
}

istream& operator >> (istream& in, Date& reciever)
{
	in >> reciever.Day;
	if (in.peek() == '/') in.get();
	in >> reciever.Month;
	if (in.peek() == '/') in.get();
	in >> reciever.Year;
	reciever.isValid();
	return in;
}
ostream& operator << (ostream& out, Date& givver)
{
	if (!(givver.ifFlag())) 
	{
		if (givver.Day < 10) out << "0";
			out << givver.Day << "/";
		if (givver.Month < 10) out << "0";
			out << givver.Month << "/";
			out << givver.Year;
	}
	else
		out << givver.SendError();
	return out;
}

void Date::isValid()
{
		Error = ""; 
		ErrFlag = 0;
		bool LPDYR = this->Year % 4 == 0 && (this->Year % 100 != 0 || this->Year % 400 == 0); // leaped year
		if (Month < 1 || Month > 12) // wrong month enter
		{
		Error = "Illegal month";
		ErrFlag = 1;
		}
		else if ((((Day > 31 && Month % 2 == 1)||(Day > 31 && Month == 12)) ||// check for month 1,3,5,7,9,12 day <=31
			(Day > 30 && Month != 2 && Month != 12 && Month % 2 == 0)) ||// check for month 4,6,8,10 day<=30 and month != 2
			 (Day> 31 || Day < 1)) {													 // check for negetive numbers
			Error = "Illegal day for month";
			ErrFlag = 1;
		}
		else if (Month < 1 || Month > 12) // wrong month enter
		{
			Error = "Illegal month";
			ErrFlag = 1;
		}
		else if (!LPDYR && Day > 28 && Month == 2) {// not leaped year and day>29 (this only if month = 2,)
			Error = "Not a leap year";
			ErrFlag = 1;
		}

}

void Date::setDay(int d) {  Day = d; this->isValid();}
void Date::setMonth(int m) {  Month = m; this->isValid();}
void Date::setYear(int y) {  Year = y; this->isValid();}
bool Date::ifFlag()const {return ErrFlag;}
string Date::SendError()const { return Error; }
