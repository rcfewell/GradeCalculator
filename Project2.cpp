/*
  Title : Average Calculator 
  File id : Project2.cpp
  Author : Riley Fewell
  Description : This function inputs a file containing grade information. It reads in
  the file into a vector and stores the information that the classes Date.h and Grade.h declared.
  Once all the informationis read into the vector, The sort algorithm is used to sort the information
  in the vecotr by the date. The information is then seperated into categories based on its category
  type. The seperated information is outputted neatly in ascending order by date in there respective
  columns. In each table the possible and received grades are added up and an algorithm manipulates the 
  two numbers to get a percentage for each category. Thos three percentages are then added together to get
  final over all grade which is ouputted with a percentage and a final grade.
*/


// allows the date and grade varibales and functions
// to be used.
#include "Date.h" 
#include "Grade.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


// A prototype of a function to read in the information from a file
void ReadFile (ifstream & ins, vector <Grade> & Grades);
// A prototype of a function to output the information of a file.
void WriteReport (ostream & outs, const vector <Grade> & Grades);
// A prototype of a function to sort the information in the vector 
void GradeSort (vector <Grade> & Grades);
// A prototype of a function that finds the final grade.
string AverageTotal (float TotalAvg);


int main (int argc, char * argv [])
{
  vector <Grade> Grades; // stores the information in a vecotr name Grades

  // Error checking to make sure the file has something in it
  if (argc < 3)
    {
      cout << "Usage: " << argv[0] << " <filename>\n";
      exit (1);
    }

  // inputs the file
  ifstream ins (argv[1]);
  // Error checking to make sure file reads in coreectly
  if (ins.fail())
    {
      cout << "File " << argv[1] << " not found\n";
      exit (1);
    }
  // Function call to Readfile passing the file and the vector 

  ofstream outputFile (argv[2]);

  if (outputFile.fail())
    {
      cout << "File " << argv[2] << " not found\n";
      exit (1);
    }

  ReadFile (ins, Grades);
  // Function call the the sort function passing the vecotr
  GradeSort (Grades);
  // Function call to the write function passing the output and the vector
  WriteReport (outputFile, Grades);
  outputFile.close();
  return 0;
}


void ReadFile (ifstream & ins, vector <Grade> & Grades)  
{
  /*
    Parameters:
    Ins: This is the input file that was inputted containing the information
    Grades: This is the vector that the information is going to sotred into

    Description: This Funtion inputs the file and reads in the information.
    While it's reading in the information it appends it to the end of the Grades
    vector.
   */

  Grade someGrade; // A temporary variable to sotre the information in
  while (ins >> someGrade) // loops while there is still information being inputted
    Grades.push_back (someGrade); // appends the information to the vector
  ins.close ();

}

void WriteReport (ostream & outs, const vector <Grade> & Grades)
{
  /*
    Parameters: 
    outs: This allows the function to output information
    Grades: This is the vector that the information is being stored in
 
    Description: Intakes the information from the vector. It sorts through it and 
    and seperates the information into different categories. It outputs the information
    in seperate, neatly organized tables. It finds the percentages for each category group
    and also the final percentage and grade.
  */


  int LHTotalPossible = 0; // Total for the lab and homeowrk possible scores
  float LHTotalReceived = 0; // Total for the lab and homeowrk received scores

  int PTotalPossible = 0;  // Total for the Project possible scores
  float PTotalReceived = 0; // Total for the project received scores

  int QETotalPossible = 0; // Total for the quiz and exam possible scores
  float QETotalReceived = 0; // Total for the quiz and exam received scores

      
  // The table headers for the Labs and Homework 
  outs << setw (20) << left << "Labs and Homework";
  outs << setw (10) << "Date";
  outs << setw (12) << right << "Received";
  outs << setw (12) << right << "Possible" << endl;

  
  // Loops over the vector to output the information
  for (int i = 0; i < Grades.size(); ++i)
    {
      // it only outputs the information from the vector that has and L or H category
      if (Grades[i].GetCategory () == 'L' || Grades[i].GetCategory () == 'H')
	{
	  //outputs the lab and homework information
	  outs << Grades[i] << endl;
	  // adds up the total lab and homework scores possible and received
	  LHTotalPossible += Grades[i].GetPossible ();
	  LHTotalReceived += Grades[i].GetReceived ();
	}
    }
      
  
  // finds the lab and homework percentage
  float LHAvg = LHTotalReceived / LHTotalPossible;

  // out puts the totals and percentage for the labs and homework
  outs << setw (30) << left << "Labs and Homework Totals";
  outs << setw (12) << right << LHTotalReceived;
  outs << setw (12) << LHTotalPossible;
  outs << setw (10) << LHAvg * 100 << '%' << endl;

  // The table headers for the projects
  outs << '\n';
  outs << setw (20) << left << "Projects";
  outs << setw (10) << "Date";
  outs << setw (12) << right << "Received";
  outs << setw (12)<< "Possible" << endl;

  // loops over all the information in the vector until its done
  for (int i = 0; i < Grades.size(); ++i)
    {
      // Only ouputs the information whose category is a P
      if (Grades[i].GetCategory () == 'P')
	{
	  // outputs the information for the Projects
	  // and adds up the possible and received points for the projects
	  outs << Grades[i] << endl;
	  PTotalPossible += Grades[i].GetPossible ();
	  PTotalReceived += Grades[i].GetReceived ();
	}
    }
  // finds the percent for the projects
  float PAvg = PTotalReceived / PTotalPossible;
  
  // Ouputs the total points received, possible and percentage for the projects
  outs << setw (30) << left << "Project Totals";
  outs << setw (12) << right << PTotalReceived;
  outs << setw (12) << PTotalPossible;
  outs << setw (10) << PAvg * 100 << '%' << endl;
  

  // The header for the Quiz and Exams
  outs << '\n';
  outs << setw (20) << left << "Quiz and Exams";
  outs << setw (10) << "Date";
  outs << setw (12) << right << "Received";
  outs << setw (12) << "Possible" << endl;

  // loops over the information in the vector
  for (int i = 0; i < Grades.size(); ++i)
    {
      // Only outputs the information that has a category of Q and T
      if (Grades[i].GetCategory () == 'Q' || Grades[i].GetCategory () == 'T')
	{
	  // outputs the information and adds up the total possible
	  // and received poiints
	  outs << Grades[i] << endl;
	  QETotalPossible += Grades[i].GetPossible ();
	  QETotalReceived += Grades[i].GetReceived ();
	}
    }
  
  // finds the percentage for the quiz and exams
  float QEAvg = QETotalReceived / QETotalPossible;
  
  // outputs the total points reveiced, possible and the 
  // percentage for the quiz and exams
  outs << setw (30) << left << "Quiz and Exams Totals";
  outs << setw (12) << right << QETotalReceived;
  outs << setw (12) << QETotalPossible;
  outs << setw (10) << QEAvg * 100 << '%' << endl << endl;
  

  float NewLHAvg = LHAvg * 0.2;// finds the correct percentage for labs and homework
  float NewPAvg = PAvg * 0.3;// finds the correct percentage for the projects
  float NewQEAvg = QEAvg * 0.5;// finds the correct percentage for the quiz and exams
  float TotalAvg = (NewLHAvg + NewPAvg + NewQEAvg) * 100;// finds the final overall percentage


  // outputs the final percent and letter grade received.
  outs << setw (18) << left << "Overall Percentage: " <<
    TotalAvg << '%' << "  " << "Grade: " << AverageTotal (TotalAvg)<< endl;

      
}

void GradeSort (vector <Grade> & Grades)
{
  /*
    Parameters
    Grades: This is the vector the information is being stored in

    Description: This function intakes the information from the vecotr
    and sorts it in ascending order by the date.
   */

  // the sort algorithm
  sort (Grades.begin(), Grades.end());
}

string AverageTotal (float TotalAvg)
{
  /*
    Parameters:
    TotalAvg: The final percentage grade of all the work provided from the input file

    Description: This function intakes the final percentage.
    It then determines what letter grade should be assigned based off the percentage
   */

  // declares a new variable that will contain the letter grade 
  string FinalGrade;

  // determines what letter grade should be received
  // based off of specific grading specifications.
  if (TotalAvg >= 93.0)
    FinalGrade = "A";
  else if (TotalAvg >= 90.0)
    FinalGrade = "A-";
  else if (TotalAvg >= 87.0)
    FinalGrade = "B+";
  else if (TotalAvg >= 83.0)
    FinalGrade = "B";
  else if (TotalAvg >= 80.0)
    FinalGrade = "B-";
  else if (TotalAvg >= 77.0)
    FinalGrade = "C+";
  else if (TotalAvg >= 73.0)
    FinalGrade = "C";
  else if (TotalAvg >= 70.0)
    FinalGrade = "C-";
  else if (TotalAvg >= 67.0)
    FinalGrade = "D+";
  else if (TotalAvg >= 63.0)
    FinalGrade = "D";
  else if (TotalAvg >= 60.0)
    FinalGrade = "D-";
  else
    FinalGrade = "F";

  return FinalGrade;
  

}
