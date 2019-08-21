/*test12.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Get Grade Distribution for a letter course
// 
//             make all7 failed
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


TEST_CASE( "Test 12", "[Project01]" ) 
{
  Course C = ParseCourse("BIOE,101,01,Intro to Bioengineering,22,8,2,1,5,1,0,0,0,5,Eddington");

  GradeStats G = GetGradeDistribution(C);
  
  REQUIRE(G.N == 38);
  REQUIRE(G.NumA == 22);
  REQUIRE(G.NumB == 8);           
  REQUIRE(G.NumC == 2);
  REQUIRE(G.NumD == 1);
  REQUIRE(G.NumF == 5);
  
  REQUIRE(abs(G.PercentA - 57.895) < 0.001);
  REQUIRE(abs(G.PercentB - 21.053) < 0.001);
  REQUIRE(abs(G.PercentC - 5.2632) < 0.001);
  REQUIRE(abs(G.PercentD - 2.6316) < 0.001);
  REQUIRE(abs(G.PercentF - 13.158) < 0.001);

}
