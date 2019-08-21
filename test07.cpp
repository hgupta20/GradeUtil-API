/*test07.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: DFW Rate for a letter course
// 
//             make all4 failed
//             make all5 failed
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


TEST_CASE( "Test 07", "[Project01]" ) 
{
  Course C = ParseCourse("BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington");
    
  REQUIRE(C.Dept == "BIOE");
  REQUIRE(C.Number == 101);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Title == "Intro to Bioengineering");
  REQUIRE(C.Instructor == "Eddington");
  
  REQUIRE(C.NumA == 22);
  REQUIRE(C.NumB == 8);           
  REQUIRE(C.NumC == 2);
  REQUIRE(C.NumD == 1);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 1);
  REQUIRE(C.NumNR == 0);
  REQUIRE(C.NumS == 0);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 5);
    
  
  REQUIRE(C.getGradingType() == Course::Letter);
    
  int DFW = 0;
  int N = 0;
  REQUIRE(abs(GetDFWRate(C, DFW, N) - 15.7895) < 0.001);
  REQUIRE(DFW == 6);
  REQUIRE(N == 38);

}
