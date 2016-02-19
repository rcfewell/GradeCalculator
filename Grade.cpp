/*
  Title : Average Calculator
  File id: Grade.h
  Author : Riley Fewell
  Description : Implements the Functions from the Grade.h file
*/

#include "Date.h"
#include "Grade.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// This is a default constructor that sets the values of the variable
Grade::Grade ()
{
  category = ' ';
  name = " ";
  date = date;
  possible = 0;
  received = 0.0;
}

// This is a copy constructor that copies the information from one variable to another
Grade::Grade (const Grade & G)
{
  category = G.category;
  date = G.date;
  possible = G.possible;
  received = G.received;
  name = G.name;
}

// This is an equals operator that determines whether two variables are equal
// If they aren't then it sets the variable to the new inputted value
Grade & Grade::operator = (const Grade & G)
{
  if (this == &G)
    return *this;
  category = G.category;
  date = G.date;
  possible = G.possible;
  received = G.received;
  name = G.name;

  return *this;
}

//This is a destructor function
Grade::~Grade()
{
}

// This sets the value of the category variable to a new category
void Grade::SetCategory (char inCategory)
{
  category = inCategory;
}

// This sets the value of the name variable to a new name
void Grade::SetName (string inName)
{
  name = inName;
}

// This sets the value of the date variable to a new date
void Grade::SetDate (Date inDate)
{
  date = inDate;
}

// This sets the value of the possible variable to a new possible
void Grade::SetPossible (int inPossible)
{
  possible = inPossible;
}

// This sets the value of the received variable to a new received
void Grade::SetReceived (int inReceived)
{
  received = inReceived;
}

// This function allows for the application to access the category variable
char Grade::GetCategory () const
{
  return category;
}

// This function allows for the application to access the name variable
string Grade::GetName () const
{
  return name;
}

// This function allows for the application to access the date variable
Date Grade::GetDate () const
{
  return date;
}

// This function allows for the application to access the possible variable
int Grade::GetPossible () const
{
  return possible;
}

// This function allows for the application to access the received variable
float Grade::GetReceived () const
{
  return received;
}

//This is a less than operator that compares two values for the category variable
// if they are equal it returns the date that is less than the other date
// if they are not equal it returns the other date.
bool Grade::operator < (const Grade & G) const
{
  if (category == G.category)
    {
      if (date.GetYear () == G.date.GetYear () && 
	  date.GetMonth () == G.date.GetMonth () &&
	  date.GetDay () == G.date.GetDay ())
	return (name < G.name);
      else
	return (date < G.date);
    }
  return (category < G.category);

}

//This is an overloader function that allows me to overload what is being read in to the vector
// from the file
istream & operator >> (istream & ins, Grade & G)
{
  char temptype;
  char tempChar;
  string tempString;
  ins >> temptype;
  if (ins.fail())
    return ins;
  G.category = temptype;
  ins >> G.date;
  ins >> G.possible;
  ins >> G.received;
  ins >> tempChar;
  getline (ins, tempString);
  G.name = tempChar + tempString;
  return ins;
}

//This is an overloader function that allows me to output in the format I want the
// output to be in.
ostream & operator << (ostream & outs, const Grade & G)
{
  outs.precision (1);
  outs << setw (20) << left << fixed << G.name;
  outs << G.date;
  outs << setw (12) << right << G.received;
  outs << setw (12) << right << G.possible;
  return outs;
}
