/*
  Title: Average Calculator
  File id: Grade.h
  Author: Riley Fewell
  Description : implements the functions and variable for the grade class
*/

#ifndef GRADE_H
#define GRADE_H

#include "Date.h"
#include <iostream>

using namespace std;

class Grade
{
	public:
		Grade ();
		Grade (const Grade & G);
		Grade & operator = (const Grade & G);
		~Grade ();
		void SetCategory (char inCategory);
		void SetName (string inName);
		void SetDate (Date inDate);
		void SetPossible (int inPossible);
		void SetReceived (int inReceived);
		char GetCategory () const;
		string GetName () const;
		Date GetDate () const;
		int GetPossible () const;
		float GetReceived () const;
		bool operator < (const Grade & G) const;
		friend istream & operator >> (istream & ins, Grade & G);
		friend ostream & operator << (ostream & outs, const Grade & G);
	private:
		char category;
		string name;
		Date date;
		int possible;
		float received;
};

#endif
