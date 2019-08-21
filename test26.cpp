/*test23.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Course creation and getGradingType function
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


TEST_CASE( "Test 23", "[Project01]" ) 
{
  Course A("CS", "Seminar", 341, 02, "Hummel", 0, 0, 0, 0, 0, 50, 0, 0, 0, 1);
  Course B("CS", "1", 341, 07, "Hummel", 0, 0, 0, 0, 0, 2, 0, 0, 0, 1);
  
  Course D("CS", "3", 341, 04, "Hummel", 0, 0, 0, 0, 0, 22, 0, 0, 0, 1);
  Course E("CS", "4", 341, 05, "Hummel", 0, 0, 0, 0, 0, 101, 0, 0, 0, 1);

  Dept R("First");
  Dept S("Second");
  R.Courses.push_back(A);
  R.Courses.push_back(B);
  S.Courses.push_back(D);
  S.Courses.push_back(E);
    
  College U("Coll");
  U.Depts.push_back(R);
  U.Depts.push_back(S);
  
  vector<Course> c = FindCourses(U,341);
  
  int i;
  
  for(i = 0; i < c.size(); i++){
      if(i==0){
          REQUIRE(c.at(i).Dept == "CS");
          REQUIRE(c.at(i).Title == "Seminar");
          REQUIRE(c.at(i).Number == 341);
          REQUIRE(c.at(i).Section == 02);
          REQUIRE(c.at(i).Instructor == "Hummel");

          REQUIRE(c.at(i).NumA == 0);
          REQUIRE(c.at(i).NumB == 0);           
          REQUIRE(c.at(i).NumC == 0);
          REQUIRE(c.at(i).NumD == 0);
          REQUIRE(c.at(i).NumF == 0);

          REQUIRE(c.at(i).NumI == 50);
          REQUIRE(c.at(i).NumS == 0);           
          REQUIRE(c.at(i).NumU == 0);
          REQUIRE(c.at(i).NumW == 0);
          REQUIRE(c.at(i).NumNR == 1); 
      }else if(i==1){
          REQUIRE(c.at(i).Dept == "CS");
          REQUIRE(c.at(i).Title == "3");
          REQUIRE(c.at(i).Number == 341);
          REQUIRE(c.at(i).Section == 04);
          REQUIRE(c.at(i).Instructor == "Hummel");

          REQUIRE(c.at(i).NumA == 0);
          REQUIRE(c.at(i).NumB == 0);           
          REQUIRE(c.at(i).NumC == 0);
          REQUIRE(c.at(i).NumD == 0);
          REQUIRE(c.at(i).NumF == 0);

          REQUIRE(c.at(i).NumI == 22);
          REQUIRE(c.at(i).NumS == 0);           
          REQUIRE(c.at(i).NumU == 0);
          REQUIRE(c.at(i).NumW == 0);
          REQUIRE(c.at(i).NumNR == 1);
      }else if(i==2){
          REQUIRE(c.at(i).Dept == "CS");
          REQUIRE(c.at(i).Title == "4");
          REQUIRE(c.at(i).Number == 341);
          REQUIRE(c.at(i).Section == 05);
          REQUIRE(c.at(i).Instructor == "Hummel");

          REQUIRE(c.at(i).NumA == 0);
          REQUIRE(c.at(i).NumB == 0);           
          REQUIRE(c.at(i).NumC == 0);
          REQUIRE(c.at(i).NumD == 0);
          REQUIRE(c.at(i).NumF == 0);

          REQUIRE(c.at(i).NumI == 101);
          REQUIRE(c.at(i).NumS == 0);           
          REQUIRE(c.at(i).NumU == 0);
          REQUIRE(c.at(i).NumW == 0);
          REQUIRE(c.at(i).NumNR == 1);
      }else if(i==3){
          REQUIRE(c.at(i).Dept == "CS");
          REQUIRE(c.at(i).Title == "1");
          REQUIRE(c.at(i).Number == 341);
          REQUIRE(c.at(i).Section == 07);
          REQUIRE(c.at(i).Instructor == "Hummel");

          REQUIRE(c.at(i).NumA == 0);
          REQUIRE(c.at(i).NumB == 0);           
          REQUIRE(c.at(i).NumC == 0);
          REQUIRE(c.at(i).NumD == 0);
          REQUIRE(c.at(i).NumF == 0);

          REQUIRE(c.at(i).NumI == 2);
          REQUIRE(c.at(i).NumS == 0);           
          REQUIRE(c.at(i).NumU == 0);
          REQUIRE(c.at(i).NumW == 0);
          REQUIRE(c.at(i).NumNR == 1);
      }
  }
   
}
