// File:	Student.h
// Author(s): Sebastian Sopola 		
//Description: Header file for Student.h 
 

#ifndef STUDENT_H
#define STUDENT_H

// built-in libraries for specific use
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// determine size of student name
#define NAMESIZE 30

// determine size of user answer
#define ANSWERSIZE 4

// determine student id size
#define IDSIZE 7



// declare functions we wish to share for other files to use
bool presentChoice();
int totalStudents();
struct student * createArray();
int askInformation();
void showStudentInformation();
int changeStudentInfo();
float averageGpa(struct student *memoryPointer, int totalStudents);
void showAverage(float average);
void readFromFile();
void testFunction();


#endif 
