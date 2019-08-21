/*test08.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: DFW Rate for a satisfactory course
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


TEST_CASE( "Test 08", "[Project01]" ) 
{
  Course C = ParseCourse("CS,499,01,Professional Seminar,0,0,0,0,0,2,1,88,0,0,Hummel");
  
  REQUIRE(C.Dept == "CS");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Instructor == "Hummel");
  
  REQUIRE(C.NumA == 0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 2);
  REQUIRE(C.NumNR == 1); 
  REQUIRE(C.NumS == 88);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);

  
  REQUIRE(C.getGradingType() == Course::Satisfactory);
    
  int DFW = 0;
  int N = 0;
  REQUIRE(abs(GetDFWRate(C, DFW, N) - 0.0) < 0.001);
  REQUIRE(DFW == 0);
  REQUIRE(N == 0);

}
