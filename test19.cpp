/*test19.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Find Courses in a college with letter, satisfactory, and unknown courses by course number
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


TEST_CASE( "Test 19", "[Project01]" ) 
{
  Course C1 = ParseCourse("CS,480,01,Database Systems,15,20,39,11,25,2,0,0,0,5,Hummel"); // Letter
  Course C2 = ParseCourse("CS,480,02,Database Systems,6,34,17,23,18,2,0,0,0,1,Hummel"); // Letter
  Course C3 = ParseCourse("CS,301,01,Languages and Automata,10,36,21,8,3,1,0,0,0,2,McCarty"); // Letter
  Course C4 = ParseCourse("CS,301,02,Languages and Automata,21,9,13,34,27,1,0,0,0,4,McCarty"); // Letter
  Course C5 = ParseCourse("CS,499,01,Professional Seminar,0,0,0,0,0,2,1,88,0,0,Hummel"); // Satisfactory
  Course C6 = ParseCourse("CS,499,02,Professional Seminar,0,0,0,0,0,2,1,60,0,0,Hummel"); // Satisfactory
  Course C7 = ParseCourse("CS,699,01,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course C8 = ParseCourse("CS,699,02,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
    
  Course M1 = ParseCourse("MATH,480,01,Applied Differential Equations,38,10,59,21,14,2,0,0,0,2,Abramov"); // Letter
  Course M2 = ParseCourse("MATH,480,02,Applied Differential Equations,11,34,27,6,1,2,0,0,0,3,Abramov"); // Letter
  Course M3 = ParseCourse("MATH,181,01,Calculus II,6,43,8,31,6,1,0,0,0,9,Shulman"); // Letter
  Course M4 = ParseCourse("MATH,90,01,Intermediate Algebra,0,0,0,0,0,2,1,79,0,1,McCarty"); // Satisfactory
  Course M5 = ParseCourse("MATH,720,01,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,5,Riemann"); // Unknown  
  Course M6 = ParseCourse("MATH,720,02,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,2,Turing"); // Unknown    
    
    
  Dept C("Computer Science");
  C.Courses.push_back(C1);
  C.Courses.push_back(C2);
  C.Courses.push_back(C3);
  C.Courses.push_back(C4);
  C.Courses.push_back(C5);
  C.Courses.push_back(C6);
  C.Courses.push_back(C7);
  C.Courses.push_back(C8);
    
  Dept M("Math");
  M.Courses.push_back(M1);
  M.Courses.push_back(M2);
  M.Courses.push_back(M3);
  M.Courses.push_back(M4);
  M.Courses.push_back(M5);
  M.Courses.push_back(M6);
    
  College S("STEM");
  S.Depts.push_back(C);
  S.Depts.push_back(M); 
  
  REQUIRE(FindCourses(S,251).size() == 0);
  REQUIRE(FindCourses(S,301).size() == 2);
  REQUIRE(FindCourses(S,499).size() == 2);
  REQUIRE(FindCourses(S,699).size() == 2);
  REQUIRE(FindCourses(S,480).size() == 4);
  REQUIRE(FindCourses(S,181).size() == 1);
  REQUIRE(FindCourses(S,90).size() == 1);
  REQUIRE(FindCourses(S,720).size() == 2);

}
