/*test20.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Find Courses in a college with letter, satisfactory, and unknown courses by instructor
// 
//             make all10 failed
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


TEST_CASE( "Test 20", "[Project01]" ) 
{
  Course C1 = ParseCourse("CS,480,01,Database Systems,15,20,39,11,25,2,0,0,0,5,Hummel"); // Letter
  Course C2 = ParseCourse("CS,480,02,Database Systems,6,34,17,23,18,2,0,0,0,1,Hummel"); // Letter
  Course C3 = ParseCourse("CS,301,01,Languages and Automata,10,36,21,8,3,1,0,0,0,2,McCarty"); // Letter
  Course C4 = ParseCourse("CS,301,02,Languages and Automata,21,9,13,34,27,1,0,0,0,4,McCarty"); // Letter
  Course C5 = ParseCourse("CS,499,01,Professional Seminar,0,0,0,0,0,2,1,88,0,0,Hummel"); // Satisfactory
  Course C6 = ParseCourse("CS,499,-01,Professional Seminar,0,0,0,0,0,2,1,60,0,0,Hummel"); // Satisfactory
  Course C7 = ParseCourse("CS,699,01,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course C8 = ParseCourse("CS,699,02,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
    
  Course M1 = ParseCourse("MATH,480,01,Applied Differential Equations,38,10,59,21,14,2,0,0,0,2,Abramov"); // Letter
  Course M2 = ParseCourse("MATH,480,02,Applied Differential Equations,11,34,27,6,1,2,0,0,0,3,Abramov"); // Letter
  Course M3 = ParseCourse("MATH,181,01,Calculus II,6,43,8,31,6,1,0,0,0,9,Shulman"); // Letter
  Course M4 = ParseCourse("MATH,90,01,Intermediate Algebra,0,0,0,0,0,2,1,79,0,1,Hummel"); // Satisfactory
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
  
  REQUIRE(FindCourses(S,"").size() == 14);
  REQUIRE(FindCourses(S,"M").size() == 2);
  REQUIRE(FindCourses(S,"McCarty").size() == 2);
  REQUIRE(FindCourses(S,"arty").size() == 0);
  REQUIRE(FindCourses(S,"H").size() == 5);
  REQUIRE(FindCourses(S,"Hummel").size() == 5);
  REQUIRE(FindCourses(S,"mel").size() == 0);
  REQUIRE(FindCourses(S,"T").size() == 3);
  REQUIRE(FindCourses(S,"Turing").size() == 3);
  REQUIRE(FindCourses(S,"uring").size() == 0);
  REQUIRE(FindCourses(S,"A").size() == 2);
  REQUIRE(FindCourses(S,"Abramov").size() == 2);
  REQUIRE(FindCourses(S,"amov").size() == 0);
  REQUIRE(FindCourses(S,"Riemann").size() == 1);
  REQUIRE(FindCourses(S,"mann").size() == 0);
  REQUIRE(FindCourses(S,"R").size() == 1);
  REQUIRE(FindCourses(S,"S").size() == 1);
  REQUIRE(FindCourses(S,"Shulman").size() == 1);
  REQUIRE(FindCourses(S,"man").size() == 0);
    
  REQUIRE(C1.getGradingType() == Course::Letter);
  REQUIRE(C2.getGradingType() == Course::Letter);
  REQUIRE(C3.getGradingType() == Course::Letter);
  REQUIRE(C4.getGradingType() == Course::Letter);
  REQUIRE(C5.getGradingType() == Course::Satisfactory);
  REQUIRE(C6.getGradingType() == Course::Satisfactory);
  REQUIRE(C7.getGradingType() == Course::Unknown);
  REQUIRE(C8.getGradingType() == Course::Unknown);
    
  REQUIRE(M1.getGradingType() == Course::Letter);
  REQUIRE(M2.getGradingType() == Course::Letter);
  REQUIRE(M3.getGradingType() == Course::Letter);
  REQUIRE(M4.getGradingType() == Course::Satisfactory);
  REQUIRE(M5.getGradingType() == Course::Unknown);
  REQUIRE(M6.getGradingType() == Course::Unknown);
    
  vector<Course> c = FindCourses(S,"");
    
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Instructor.compare(c.at(i+1).Instructor) <= 0);
      if(c.at(i).Instructor.compare(c.at(i+1).Instructor) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }
}
