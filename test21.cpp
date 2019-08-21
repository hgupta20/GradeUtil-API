/*test21.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Find Courses in a college with unknown course by course number
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


TEST_CASE( "Test 21", "[Project01]" ) 
{
  Course C1 = ParseCourse(" ,0,00, ,0,0,0,0,0,0,0,0,0,0, "); // Letter

    
  Dept C("Computer Science");
  C.Courses.push_back(C1);
    
  College S("STEM");
  S.Depts.push_back(C);
  
  REQUIRE(FindCourses(S,251).size() == 0);
  REQUIRE(FindCourses(S,301).size() == 0);
  REQUIRE(FindCourses(S,499).size() == 0);


}
