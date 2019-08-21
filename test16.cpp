/*test16.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Get Grade Distribution for a colleg with letter, satisfactory, and unknown courses in multiple departments
// 
//             make all8 failed
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


TEST_CASE( "Test 16", "[Project01]" ) 
{
  Course C1 = ParseCourse("CS,251,01,Data Structures,15,20,39,11,23,2,0,0,0,5,Lillis"); // Letter
  Course C2 = ParseCourse("CS,301,01,Languages and Automata,10,34,21,8,3,1,0,0,0,2,McCarty"); // Letter
  Course C3 = ParseCourse("CS,499,01,Professional Seminar,0,0,0,0,0,2,1,88,0,0,Hummel"); // Satisfactory
  Course C4 = ParseCourse("CS,699,01,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
    
  Course M1 = ParseCourse("MATH,180,01,Calculus I,38,10,59,21,14,2,0,0,0,2,Bode"); // Letter
  Course M2 = ParseCourse("MATH,181,01,Calculus II,6,43,8,31,6,1,0,0,0,9,Shulman"); // Letter
  Course M3 = ParseCourse("MATH,090,01,Intermediate Algebra,0,0,0,0,0,2,1,79,0,1,Ross"); // Satisfactory
  Course M4 = ParseCourse("MATH,720,01,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,2,Riemann"); // Unknown
    
  Dept C("Computer Science");
  C.Courses.push_back(C1);
  C.Courses.push_back(C2);
  C.Courses.push_back(C3);
  C.Courses.push_back(C4);
    
  Dept M("Math");
  M.Courses.push_back(M1);
  M.Courses.push_back(M2);
  M.Courses.push_back(M3);
  M.Courses.push_back(M4);
    
  College S("STEM");
  S.Depts.push_back(C);
  S.Depts.push_back(M); 
    
  GradeStats G = GetGradeDistribution(S);
  
  REQUIRE(G.N == 420);
  REQUIRE(G.NumA == 69);
  REQUIRE(G.NumB == 107);           
  REQUIRE(G.NumC == 127);
  REQUIRE(G.NumD == 71);
  REQUIRE(G.NumF == 46);
  
  REQUIRE(abs(G.PercentA - 16.4286) < 0.0001);
  REQUIRE(abs(G.PercentB - 25.4762) < 0.0001);
  REQUIRE(abs(G.PercentC - 30.2381) < 0.0001);
  REQUIRE(abs(G.PercentD - 16.9048) < 0.0001);
  REQUIRE(abs(G.PercentF - 10.9524) < 0.0001);

}
