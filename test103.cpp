/*test03.cpp*/

//
// <<Harsh Devprakash Gupta>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases:
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


TEST_CASE( "Test 103", "[Project01]" ) 
{
  Course H= ParseCourse ("BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington");
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor           
  REQUIRE(H.Dept == "BIOE");
  REQUIRE(H.Title == "Intro to Bioengineering");
  REQUIRE(H.Number == 101);
  REQUIRE(H.Section == 01);
  REQUIRE(H.Instructor == "Eddington");
  
  REQUIRE(H.NumA == 22);
  REQUIRE(H.NumB == 8);           
  REQUIRE(H.NumC == 2);
  REQUIRE(H.NumD == 1);
  REQUIRE(H.NumF == 0);
  
  REQUIRE(H.NumI == 1);
  REQUIRE(H.NumS == 0);           
  REQUIRE(H.NumU == 0);
  REQUIRE(H.NumW == 5);
  REQUIRE(H.NumNR == 0);  
  
}
