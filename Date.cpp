/*
  Title : Average Calculator
  File id : Date.cpp
  Author : Riley Fewell
  Description : This implements the functions from the Date class
*/

#include "Grade.h"
#include "Date.h"
#include <iostream>
#include <cstdlib>


using namespace std;

// This is a default constructor whick sets the variables to a value.
Date::Date ()
{
  month = 0;
  day = 0;
  year = 0;
}

//This is a copy constructor that copies the value of a variable into the
// other variable
Date::Date (const Date & D)
{
  month = D.month;
  day = D.day;
  year = D.year;
}

// This is an assignment function that assigns a new value to the variables
Date::Date (int inMonth, int inDay, int inYear)
{
  month = inMonth;
  day = inDay;
  year = inYear;
}

// This is an equals operator which is assigns the value to of one variable to the other if they
// are not equal
Date & Date::operator = (const Date & D)
{
  if (this == &D)
    return *this;
  month = D.month;
  day = D.day;
  year = D.year;
  return *this;
}

//This is a destructor function
Date::~Date ()
{
}

// This allows the application function to set the month variable to a certain value
void Date::SetMonth (int inMonth)
{
  month = inMonth;
}

// This allows the application function to set the day variable to a certain value
void Date::SetDay (int inDay)
{
  day = inDay;
}

// This allows the application function to set the year variable to a certain value
void Date::SetYear (int inYear)
{
  year = inYear;
}

//This allows the application function to gain access to the month variablew
int Date::GetMonth() const
{
  return month;
}

//// This allows the application function to set the day variable to a certain value
int Date::GetDay() const
{
  return day;
}
//// This allows the application function to set the year variable to a certain value
int Date::GetYear() const
{
  return year;
}

// This is a less than operator that compares the year month and day and
// returns true if they are less than and false if they are greater than the other
bool Date::operator < (const Date & D) const
{
  if (year < D.year)
    return true;
  if (year > D.year)
      return false;
  if (month < D.month)
    return true;
  if (month > D.month)
      return false;
  if (day < D.day)
    return true;
  if (day > D.day)
    return false;
  return false;

}

// This is a less than operator that compares the year month and day and
// returns false if they are less than and true if they are greater than the other
bool Date::operator > (const Date & D) const
{
  if (year < D.year)
    return false;
  if (year > D.year)
    return true;
  if (month < D.month)
    return false;
  if (month > D.month)
    return true;
  if (day < D.day)
    return false;
  if (day > D.day)
    return true;
  return false;

}

//This is an overloading function that allows me to input the date in the format
// that I want it to be in
istream & operator >> (istream & ins, Date & D)
{
  char tempchar;
  ins >> D.year;
  ins >> tempchar;
  ins >> D.month;
  ins >> tempchar;
  ins >> D.day;
  return ins;
}

// This is an overloading operator that allows me to output the date in the format
// I want without there being any misplaced values. the format will be mm/dd/yyyy. 
ostream & operator << (ostream & outs, const Date & D)
{
  if (D.month < 10)
    outs << '0';
  outs << D.month << '/';
  if (D.day < 10)
    outs << '0';
  outs << D.day << '/';
  outs << D.year;
  return outs;

}
