/*gradeutil.cpp*/

//
// <<Harsh Devprakash Gupta>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #02: GradeUtil API
// 

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

#include "gradeutil.h"

using namespace std;


//
// API:
//

// 
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
Course ParseCourse(string csvline)
{
  string Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor; // initialize the variables
  Course input;                                                     // initialize the Course name
  stringstream ss(csvline);                                         // stringstream to read in the file

  //parse line
  getline(ss,Dept, ',');
  getline(ss,Number,',');
  getline(ss,Section, ',');
  getline(ss,Title,',');
  getline(ss,A, ',');
  getline(ss,B,',');
  getline(ss,C, ',');
  getline(ss,D,',');
  getline(ss,F, ',');
  getline(ss,I,',');
  getline(ss,NR, ',');
  getline(ss,S,',');
  getline(ss,U, ',');
  getline(ss,W,',');
  getline(ss,Instructor);
  //   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
  // Assign the variables to the object
  input.Dept=Dept;
  input.Number=stoi(Number);
  input.Section=stoi(Section);
  input.Title=Title;
  input.NumA=stoi(A);
  input.NumB=stoi(B);
  input.NumC=stoi(C);
  input.NumD=stoi(D);
  input.NumF=stoi(F);
  input.NumI=stoi(I);
  input.NumNR=stoi(NR);
  input.NumS=stoi(S);
  input.NumU=stoi(U);
  input.NumW=stoi(W);
  input.Instructor=Instructor;
  //   Dept,Nuber,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
  return input;
  return Course();
}


//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  double NumAW= c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
  double NumDFW= c.NumD + c.NumF + c.NumW;
  double result;

  if (c.getGradingType()== Course::Letter){
    DFW= DFW + NumDFW;
    NumAW= NumAW + c.NumW;
  }
  N=NumAW;
  if (N==0){
    return 0;
  }
  result= ((DFW / NumAW) * 100.0);
  return result;
}
double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  double NumAW= 0;
  double NumDFW= 0;
  double tempAW;
  double result = 0;

  for (Course c : dept.Courses)
  {
    NumDFW = c.NumD + c.NumF + c.NumW;
    NumAW = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;

    if (c.getGradingType()== Course::Letter)
    {

      DFW= DFW + NumDFW;
      tempAW= tempAW + NumAW  + c.NumW;
    }
  }
  N=tempAW;

  if (N==0){
    return 0;
  }
  
  result= ((DFW / tempAW) * 100.0);
  return result;
}

double GetDFWRate(const College &college, int &DFW, int &N)
{
  DFW = 0;
  N = 0;

  //
  // TODO:
  //
  double temp;
  double temp0;
  for (Dept A : college.Depts)
  {
    for (Course S : A.Courses)
    {
      int tempDFW = S.NumD + S.NumF + S.NumW;

      temp0 = S.NumA + S.NumB + S.NumC + S.NumD + S.NumF;
      if (S.getGradingType()==Course::Letter)
      {
        temp = temp + temp0 + S.NumW;
        DFW = DFW + tempDFW;
      }
    }
  }
  N = temp;
  cout << "The DFW is  " << DFW << endl
       << "THe N is " << N;

  return ((DFW / temp) * 100.0);
}


//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
GradeStats GetGradeDistribution(const Course& c)
{
  GradeStats values;
  double tempN = 0;
  if(c.getGradingType()==Course::Letter)
    { //initialize all the values
      values.NumA = c.NumA;
      values.NumB = c.NumB;
      values.NumC = c.NumC;
      values.NumD = c.NumD;
      values.NumF = c.NumF;
      values.N = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;

      //calculate the percentage
      tempN = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
      values.PercentA = (c.NumA / tempN) * 100.0;
      values.PercentB = (c.NumB / tempN) * 100.0;
      values.PercentC = (c.NumC / tempN) * 100.0;
      values.PercentD = (c.NumD / tempN) * 100.0;
      values.PercentF = (c.NumF / tempN) * 100.0;
    }
  else
  {// initialize everything to zero
    values.NumA=0;
    values.NumB=0;
    values.NumC = 0;
    values.NumD = 0;
    values.NumF = 0;
    values.N = 0;
    values.PercentA = 0;
    values.PercentB = 0;
    values.PercentC = 0;
    values.PercentD = 0;
    values.PercentF = 0;

  }
  if (values.N==0)
  {
    return GradeStats(0,0,0,0,0,0,0.0,0.0,0.0,0.0,0.0);
  }

  return values;  
}

GradeStats GetGradeDistribution(const Dept& dept)
{
  GradeStats values;
  double tempN = 0;
  // initialize everything to zero
  /*values.NumA=0;
  values.NumB=0;
  values.NumC = 0;
  values.NumD = 0;
  values.NumF = 0;
  values.N = 0;
  values.PercentA = 0;
  values.PercentB = 0;
  values.PercentC = 0;
  values.PercentD = 0;
  values.PercentF = 0;
  values.PercentA = 0;*/
  for (Course c : dept.Courses)
  {
    if (c.getGradingType()==Course::Letter)
    {
      values.NumA = values.NumA+ c.NumA;
      values.NumB =  values.NumB+ c.NumB;
      values.NumC =  values.NumC+ c.NumC;
      values.NumD =  values.NumD+ c.NumD;
      values.NumF =  values.NumF+ c.NumF;
      values.N = values.N+c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
      tempN = tempN + c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
    }

  }
  if (values.N==0)
  {
    return GradeStats(0,0,0,0,0,0,0.0,0.0,0.0,0.0,0.0);
  }
  values.PercentA = (values.NumA / tempN) * 100.0;
  values.PercentB = (values.NumB / tempN) * 100.0;
  values.PercentC = (values.NumC / tempN) * 100.0;
  values.PercentD = (values.NumD / tempN) * 100.0;
  values.PercentF = (values.NumF / tempN) * 100.0;

  return values;
}

GradeStats GetGradeDistribution(const College& college)
{
  GradeStats values;
  double tempN=0;
  // initialize everything to zero
  /*values.NumA=0;
  values.NumB=0;
  values.NumC = 0;
  values.NumD = 0;
  values.NumF = 0;
  values.N = 0;
  values.PercentA = 0;
  values.PercentB = 0;
  values.PercentC = 0;
  values.PercentD = 0;
  values.PercentF = 0;
  values.PercentA = 0;*/
  for (Dept a : college.Depts)
    {
    for (Course c : a.Courses)
      {
        if (c.getGradingType()==Course::Letter)
        {
          values.NumA = values.NumA+ c.NumA;
          values.NumB =  values.NumB+ c.NumB;
          values.NumC =  values.NumC+ c.NumC;
          values.NumD =  values.NumD+ c.NumD;
          values.NumF =  values.NumF+ c.NumF;
          values.N = values.N+c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
          tempN = tempN + c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
        }

      }
    }
  if (values.N==0)
    {
      return GradeStats(0,0,0,0,0,0,0.0,0.0,0.0,0.0,0.0);
    }
  values.PercentA = (values.NumA / tempN) * 100.0;
  values.PercentB = (values.NumB / tempN) * 100.0;
  values.PercentC = (values.NumC / tempN) * 100.0;
  values.PercentD = (values.NumD / tempN) * 100.0;
  values.PercentF = (values.NumF / tempN) * 100.0;
  
  return values;
}


//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
  vector<Course>  courses;
  
  for(Course c : dept.Courses)
    {

      if(c.Number==courseNumber) // compare if the number matches
      {
        courses.push_back(c); // push back inthe vector
      }

    }
  sort(courses.begin(),courses.end(),
  [](Course c1, Course c2)
    {
      if(c1.Section<c2.Section) // compare by section
      {
        return true;
      }
      else{
        return false;
      }
    }
    
    );

  
  return courses;
}


//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.
//
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
  vector<Course>  courses;

  int length= 0; // for length of instructor prefix

  for(Course c : dept.Courses)
  {
    length= instructorPrefix.length(); // instructor prefix length
    if(c.Instructor.compare(0,length,instructorPrefix)==0) // compare the length 
    {
      courses.push_back(c); // push back into the vector

    }
    
  }
  sort(courses.begin(),courses.end(),
  [](Course c1, Course c2)
    {
        if(c1.Number<c2.Number)         // compare by Number
          {
            return true;
          }
        else if(c1.Number>c2.Number)   // compare by Number
          {
            return false;
          }
        else
          {
            if(c1.Section<c2.Section) // compare by sections
              {
                return true;          // return true
              }
            else
              {
                return false;           // else return false
              }
          }
    }
  );


  return courses;
}


//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, int courseNumber)
{
  vector<Course>  courses;

  for(Dept a : college.Depts)
  {

    for(Course c : a.Courses)
    {

      if(c.Number == courseNumber)
      {

        courses.push_back(c);

      }

    }

  }
  sort(courses.begin(),courses.end(),
  [](Course c1, Course c2)
    {
        if(c1.Dept<c2.Dept)         // compare by Dept
          {
            return true;
          }
        else if(c1.Dept>c2.Dept)   // compare by Dept
          {
            return false;
          }
        else
          {
            if(c1.Number<c2.Number)         // compare by Number
              {
                return true;
              }
            else if(c1.Number>c2.Number)   // compare by Number
              {
                return false;
              }
            else
              {
                if(c1.Section<c2.Section) // compare by sections
                  {
                    return true;          // return true
                  }
                else
                  {
                    return false;           // else return false
                  }
              }
          }
    }
  );

  return courses;
}


//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by instructor, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
  vector<Course>  courses;
  int length= 0;
  for(Dept a : college.Depts)
  {
    for(Course c : a.Courses)
    {
      length= instructorPrefix.length();
      if(c.Instructor.compare(0,length, instructorPrefix)==0)
      {

        courses.push_back(c);

      }

    }
  }

  sort(courses.begin(),courses.end(),
  [](Course c1, Course c2)
    {
      if(c1.Instructor<c2.Instructor)
        {
          return true;
        }
      else if(c1.Instructor>c2.Instructor)
        {
          return false;
        }
      else
        {
          if(c1.Number<c2.Number) // compare by numbers
            {
              return true; 
            }
          else if (c1.Number>c2.Number)  // compare by Number
            {
              return false;
            }
          else
          {
             if(c1.Section<c2.Section)  // compare by section
                {
                   return true;
                }
                else
                {
                   return false;
                 }
          }
        }
    }
    );


  return courses;
}
