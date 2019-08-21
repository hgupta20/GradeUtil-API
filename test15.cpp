/*test15.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Get Grade Distribution for a department with letter, satisfactory, and unknown courses
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


TEST_CASE( "Test 15", "[Project01]" ) 
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
  
  GradeStats G = GetGradeDistribution(D);
  
  REQUIRE(G.N == 188);
  REQUIRE(G.NumA == 25);
  REQUIRE(G.NumB == 56);           
  REQUIRE(G.NumC == 60);
  REQUIRE(G.NumD == 19);
  REQUIRE(G.NumF == 28);
  
  REQUIRE(abs(G.PercentA - 13.2979) < 0.001);
  REQUIRE(abs(G.PercentB - 29.7872) < 0.001);
  REQUIRE(abs(G.PercentC - 31.9149) < 0.001);
  REQUIRE(abs(G.PercentD - 10.1064) < 0.001);
  REQUIRE(abs(G.PercentF - 14.8936) < 0.001);

}
