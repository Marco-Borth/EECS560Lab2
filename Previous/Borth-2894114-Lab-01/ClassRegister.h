/* -----------------------------------------------------------------------------
 *
 * File Name:  ClassRegister.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 1 Program
 * Description:  ClassRegister Class is defined, this is the class for the interactive course directory.
 * Date: 2/8/19
 *
 ---------------------------------------------------------------------------- */

#ifndef CLASSREGISTER_H
#define CLASSREGISTER_H

#include "Course.h"
#include <string>
#include <stdexcept>
using namespace std;

class ClassRegister
{
private:
  string file;
  int numberOfClasses;
  Course* enrollment;
  int option;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre Executive.cpp must construct ClassRegister object.
* @post ClassRegister object is constructed.
*/
  ClassRegister(const string filename);

/**
* @pre array of courses is created from given file.
* @post prints all courses from the given file.
*/
  void printAllCourses();

/**
* @pre array of courses is created from given file.
* @param string department must be a valid string equal to Course::departmentCode.
* @post prints all courses with the same department code.
*/
	void printDepartmentCourses(string department);

/**
* @pre array of courses is created from given file.
* @param parameters must be valid string and int equal to Course::departmentCode & Code::courseNumber respectively.
* @post prints all student IDs within the provided course.
*/
	void printCourseRoster(string department, int number);

/**
* @pre array of courses is created from given file.
* @post prints the name of, and the number of students, within the largest course.
*/
	void printLargestClass();

/**
* @pre array of courses is created from given file.
* @param original copies the contents of the courses array created.
* @post two courses selected will be swapped.
*/
  void swapClasses(Course*& original, string firstCode, int firstNumber, string secondCode, int secondNumber);

/**
* @pre array of courses is created from given file.
* @param studentID must be a valid int equal to Course::student[index].
* @post prints all courses in which the student is scheduled into.
*/
	void printStudentSchedule(int studentID);
};
#endif
