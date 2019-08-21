/*test05.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: GradeStats creation and proper data assignment
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


TEST_CASE( "Test 05", "[Project01]" ) 
{
  GradeStats G(10,2,2,2,2,2,0.2,0.2,0.2,0.2,0.2);
           
  REQUIRE(G.N == 10);
  REQUIRE(G.NumA == 2);
  REQUIRE(G.NumB == 2);           
  REQUIRE(G.NumC == 2);
  REQUIRE(G.NumD == 2);
  REQUIRE(G.NumF == 2);
  
  REQUIRE(G.PercentA == 0.2);
  REQUIRE(G.PercentB == 0.2);           
  REQUIRE(G.PercentC == 0.2);
  REQUIRE(G.PercentD == 0.2);
  REQUIRE(G.PercentF == 0.2);  

}
