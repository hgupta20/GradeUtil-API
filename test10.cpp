/*test10.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: DFW Rate for a a department with letter, satisfactory, and unknown courses
// 
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 10", "[Project01]" ) 
{
  Course C1 = ParseCourse("CS,251,01,Data Structures,15,20,39,11,25,2,0,0,0,5,Lillis"); // Letter
  Course C2 = ParseCourse("CS,301,01,Languages and Automata,10,36,21,8,3,1,0,0,0,2,McCarty"); // Letter
  Course C3 = ParseCourse("CS,499,01,Professional Seminar,0,0,0,0,0,2,1,88,0,0,Hummel"); // Satisfactory
  Course C4 = ParseCourse("CS,699,01,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
    
  Dept D("Computer Science");
  D.Courses.push_back(C1);
  D.Courses.push_back(C2);
  D.Courses.push_back(C3);
  D.Courses.push_back(C4);
  
  int DFW = 0;
  int N = 0;
  REQUIRE(abs(GetDFWRate(D, DFW, N) - 27.6923) < 0.001);
  REQUIRE(DFW == 54);
  REQUIRE(N == 195);

}
