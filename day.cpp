
#include "day.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

void Date::setDay(int day) {
	if (day < 31)
	{
		this->day = day;
	}
	else
	{
		cout << "Invalid Days!!" << endl;
	}
}
void Date::setMonth(int month) {
	if (month < 12)
	{
		this->month = month;
	}
	else
	{
		cout << "Invalid Month!!" << endl;
	}
	
}
void Date::setYear(int year) { this->year = year; }

void Date::printDate() {
	cout << day << " - " << month << " - " << year << endl;
}
