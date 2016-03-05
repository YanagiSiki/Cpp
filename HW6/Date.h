#include <iostream>
#include <string>
#include <vector>
#include <UnitTest++.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class Date {
    friend ostream &operator<<(ostream & , const Date &);
    friend istream &operator>>(istream &, Date &);
public:
    Date(int y=1900, int m=1, int d=1);  //default constructor
    Date(const Date &);            // copy constructor
    Date(char *);                  //conversion constructor from "yyyy/mm/dd"
    void setDate(int, int, int);   //set Year, Month, Day
    Date &operator++();             //prefix increament operator
    Date operator++(int);          //postfix increament operator
    operator char *() const;  //conversion operator to "yyyy/mm/day"
    const Date &operator+=(int);   //add day
    bool operator==(const Date &) const; //equality operator
    bool operator!=(const Date &) const; //inequality operator
    bool operator<(const Date &) const;  //inequality operator
    static bool leapYear(int);  // is date in a leap year
    int endOfMonth(int) const; // is date at the end of month
    Date &setYear(int);
    Date &setMonth(int);
    Date &setDay(int);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
private:
    int year;
    int month;
    int day;
    static const int days[];
    void helpIncrement();
};
