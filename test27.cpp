/*test22.cpp*/

//
// <<Omar Salas>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Find Courses in a college with unknown course by course number
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


TEST_CASE( "Test 22", "[Project01]" ) 
{
  Course C10 = ParseCourse("CS,699,01,First,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course C9 = ParseCourse("CS,699,02,Second,0,0,0,0,0,2,1,0,0,0,Turing"); // Letter
  Course C1 = ParseCourse("CS,480,01,Database Systems,15,20,39,11,25,2,0,0,0,5,Hummel"); // Letter
  Course C2 = ParseCourse("CS,480,02,Database Systems,6,34,17,23,18,2,0,0,0,1,Hummel"); // Letter
  Course C3 = ParseCourse("CS,301,01,Languages and Automata,10,36,21,8,3,1,0,0,0,2,McCarty"); // Letter
  Course C4 = ParseCourse("CS,301,02,Languages and Automata,21,9,13,34,27,1,0,0,0,4,McCarty"); // Letter
  Course C5 = ParseCourse("CS,499,01,Professional Seminar,0,0,0,0,0,2,1,88,0,0,Hummel"); // Satisfactory
  Course C6 = ParseCourse("CS,499,-01,Professional Seminar,0,0,0,0,0,2,1,60,0,0,Hummel"); // Satisfactory
  Course C7 = ParseCourse("CS,699,01,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course C8 = ParseCourse("CS,699,02,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
    
  Course M1 = ParseCourse("MATH,699,01,Hello,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course M2 = ParseCourse("MATH,699,04,Arock,0,0,0,0,0,2,1,0,0,0,Turing"); // Letter
  Course M3 = ParseCourse("MATH,480,01,Applied Differential Equations,38,10,59,21,14,2,0,0,0,2,Abramov"); // Letter
  Course M4 = ParseCourse("MATH,480,02,Applied Differential Equations,11,34,27,6,1,2,0,0,0,3,Abramov"); // Letter
  Course M5 = ParseCourse("MATH,181,01,Calculus II,6,43,8,31,6,1,0,0,0,9,Shulman"); // Letter
  Course M6 = ParseCourse("MATH,90,01,Intermediate Algebra,0,0,0,0,0,2,1,79,0,1,Hummel"); // Satisfactory
  Course M7 = ParseCourse("MATH,301,01,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,5,Riemann"); // Unknown  
  Course M8 = ParseCourse("MATH,720,02,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,2,Turing"); // Unknown    
    
  Course S1 = ParseCourse("Science,699,07,CS,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course S2 = ParseCourse("Science,699,01,P = NP,0,0,0,0,0,2,1,0,0,0,Turing"); // Letter
  Course S3 = ParseCourse("Science,480,01,Applied Differential Equations,38,10,59,21,14,2,0,0,0,2,Abramov"); // Letter
  Course S4 = ParseCourse("Science,480,02,Applied Differential Equations,11,34,27,6,1,2,0,0,0,3,Abramov"); // Letter
  Course S5 = ParseCourse("Science,181,01,Calculus II,6,43,8,31,6,1,0,0,0,9,Shulman"); // Letter
  Course S6 = ParseCourse("Science,90,01,Intermediate Algebra,0,0,0,0,0,2,1,79,0,1,Hummel"); // Satisfactory
  Course S7 = ParseCourse("Science,499,01,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,5,Riemann"); // Unknown  
  Course S8 = ParseCourse("Science,720,02,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,2,Turing"); // Unknown    
    
  Course E1 = ParseCourse("English,699,05,Ethics,0,0,0,0,0,2,1,0,0,0,Turing"); // Unknown
  Course E2 = ParseCourse("English,699,01,Pole,0,0,0,0,0,2,1,0,0,0,Turing"); // Letter
  Course E3 = ParseCourse("English,480,01,Applied Differential Equations,38,10,59,21,14,2,0,0,0,2,Abramov"); // Letter
  Course E4 = ParseCourse("English,480,02,Applied Differential Equations,11,34,27,6,1,2,0,0,0,3,Abramov"); // Letter
  Course E5 = ParseCourse("English,181,01,Calculus II,6,43,8,31,6,1,0,0,0,9,Shulman"); // Letter
  Course E6 = ParseCourse("English,90,01,Intermediate Algebra,0,0,0,0,0,2,1,79,0,1,Hummel"); // Satisfactory
  Course E7 = ParseCourse("English,181,01,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,5,Riemann"); // Unknown  
  Course E8 = ParseCourse("English,720,02,Riemann Hypothesis,0,0,0,0,0,2,1,0,0,2,Turing"); // Unknown    

    
  Dept C("Computer Science");
  C.Courses.push_back(C1);
  C.Courses.push_back(C2);
  C.Courses.push_back(C3);
  C.Courses.push_back(C4);
  C.Courses.push_back(C5);
  C.Courses.push_back(C6);
  C.Courses.push_back(C7);
  C.Courses.push_back(C8);
  C.Courses.push_back(C9);
  C.Courses.push_back(C10);
    
  Dept M("Math");
  M.Courses.push_back(M1);
  M.Courses.push_back(M2);
  M.Courses.push_back(M3);
  M.Courses.push_back(M4);
  M.Courses.push_back(M5);
  M.Courses.push_back(M6);
  M.Courses.push_back(M7);
  M.Courses.push_back(M8);
    
  Dept S("Science");
  S.Courses.push_back(S1);
  S.Courses.push_back(S2);
  S.Courses.push_back(S3);
  S.Courses.push_back(S4);
  S.Courses.push_back(S5);
  S.Courses.push_back(S6);
  S.Courses.push_back(S7);
  S.Courses.push_back(S8);
    
  Dept E("English");
  E.Courses.push_back(E1);
  E.Courses.push_back(E2);
  E.Courses.push_back(E3);
  E.Courses.push_back(E4);
  E.Courses.push_back(E5);
  E.Courses.push_back(E6);
  E.Courses.push_back(E7);
  E.Courses.push_back(E8);
    
  College U("All");
  U.Depts.push_back(C);
  U.Depts.push_back(M);
  U.Depts.push_back(S);
  U.Depts.push_back(E);
  
  vector<Course> c;
    
  REQUIRE(FindCourses(U,699).size() == 10);
  c = FindCourses(U,699);
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Dept.compare(c.at(i+1).Dept) <= 0);
      if(c.at(i).Dept.compare(c.at(i+1).Dept) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }
    
  REQUIRE(FindCourses(U,480).size() == 8);
  c = FindCourses(U,480);
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Dept.compare(c.at(i+1).Dept) <= 0);
      if(c.at(i).Dept.compare(c.at(i+1).Dept) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }
    
  REQUIRE(FindCourses(U,301).size() == 3);
  c = FindCourses(U,301);
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Dept.compare(c.at(i+1).Dept) <= 0);
      if(c.at(i).Dept.compare(c.at(i+1).Dept) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }
    
  REQUIRE(FindCourses(U,499).size() == 3);
  c = FindCourses(U,499);
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Dept.compare(c.at(i+1).Dept) <= 0);
      if(c.at(i).Dept.compare(c.at(i+1).Dept) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }
   
  REQUIRE(FindCourses(U,181).size() == 4);
  c = FindCourses(U,181);
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Dept.compare(c.at(i+1).Dept) <= 0);
      if(c.at(i).Dept.compare(c.at(i+1).Dept) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }
    
  REQUIRE(FindCourses(U,90).size() == 3);
  c = FindCourses(U,90);
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Dept.compare(c.at(i+1).Dept) <= 0);
      if(c.at(i).Dept.compare(c.at(i+1).Dept) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }
    
  REQUIRE(FindCourses(U,720).size() == 3);
  c = FindCourses(U,720);
  for(int i = 0; i < c.size() - 1;i++){
      REQUIRE(c.at(i).Dept.compare(c.at(i+1).Dept) <= 0);
      if(c.at(i).Dept.compare(c.at(i+1).Dept) == 0){
          REQUIRE(c.at(i).Number <= c.at(i+1).Number);
          if(c.at(i).Number == c.at(i+1).Number){
              REQUIRE(c.at(i).Section <= c.at(i+1).Section);
          }
      }
  }

}
