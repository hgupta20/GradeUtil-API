/*test18.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Find Courses in a department with letter, satisfactory, and unknown courses by instructor
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


TEST_CASE( "Test 18", "[Project01]" ) 
{
  Course C1 = ParseCourse("CS,251,01,Data Structures,15,20,39,11,25,2,0,0,0,5,Lillis"); // Letter
  Course C2 = ParseCourse("CS,251,02,Data Structures,6,34,17,23,18,2,0,0,0,1,McCarty"); // Letter
  Course C3 = ParseCourse("CS,301,01,Languages and Automata,10,36,21,8,3,1,0,0,0,2,McCarty"); // Letter
  Course C4 = ParseCourse("CS,301,02,Languages and Automata,21,9,13,34,27,1,0,0,0,4,Lillis"); // Letter
  Course C5 = ParseCourse("CS,499,01,Professional Seminar,0,0,0,0,0,2,1,88,0,0,Hummel"); // Satisfactory
  Course C6 = ParseCourse("CS,499,02,Professional Seminar,0,0,0,0,0,2,1,60,0,0,Hummel"); // Satisfactory
  Course C7 = ParseCourse("CS,499,02,Professional Seminar,0,0,0,0,0,2,1,39,0,0,Troy"); // Satisfactory
  Course C8 = ParseCourse("CS,699,01,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course C9 = ParseCourse("CS,699,02,P = NP,0,0,0,0,0,2,1,0,0,0,Troy"); // Unknown
  Course C10 = ParseCourse("CS,480,01,Database Systems,15,20,39,11,25,2,0,0,0,5,Hummel"); // Letter
  Course C11 = ParseCourse("CS,480,02,Database Systems,6,34,17,23,18,2,0,0,0,1,Theys"); // Letter
    
  Dept D("Computer Science");
  D.Courses.push_back(C1);
  D.Courses.push_back(C2);
  D.Courses.push_back(C3);
  D.Courses.push_back(C4);
  D.Courses.push_back(C5);
  D.Courses.push_back(C6);
  D.Courses.push_back(C7);
  D.Courses.push_back(C8);
  D.Courses.push_back(C9);
  D.Courses.push_back(C10);
  D.Courses.push_back(C11);
  
  REQUIRE(FindCourses(D,"").size() == 11);
  REQUIRE(FindCourses(D,"L").size() == 2);
  REQUIRE(FindCourses(D,"Lillis").size() == 2);
  REQUIRE(FindCourses(D,"lis").size() == 0);
  REQUIRE(FindCourses(D,"M").size() == 2);
  REQUIRE(FindCourses(D,"McCarty").size() == 2);
  REQUIRE(FindCourses(D,"arty").size() == 0);
  REQUIRE(FindCourses(D,"H").size() == 3);
  REQUIRE(FindCourses(D,"Hummel").size() == 3);
  REQUIRE(FindCourses(D,"mel").size() == 0);
  REQUIRE(FindCourses(D,"T").size() == 4);
  REQUIRE(FindCourses(D,"Turing").size() == 1);
  REQUIRE(FindCourses(D,"uring").size() == 0);
  REQUIRE(FindCourses(D,"Troy").size() == 2);
  REQUIRE(FindCourses(D,"roy").size() == 0);
  REQUIRE(FindCourses(D,"Theys").size() == 1);
  REQUIRE(FindCourses(D,"eys").size() == 0);
  REQUIRE(FindCourses(D,"oy").size() == 0);
    
  vector<Course> c = FindCourses(D,"T");
    
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Number <= c.at(i+1).Number);
  }

}
