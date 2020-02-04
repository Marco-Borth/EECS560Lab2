/* -----------------------------------------------------------------------------
*
* File Name:  Course.h
* Author: Marco Borth
* Assignment:   EECS-268 Lab 1 Program
* Description:  Course Class is defined, this is the class for each course defined in the given file.
* Date: 2/8/19
*
---------------------------------------------------------------------------- */

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <stdexcept>
using namespace std;

class Course
{
private:
  string departmentCode;
  int courseNumber;
  int size;
  int* student;

public:
/*
* @pre none.
* @param code must be a string value.
* @post departmentCode is set to code.
*/
  void setDepartmentCode(string code);

/*
* @pre none.
* @post return departmentCode value.
*/
  string getDepartmentCode() const;

/*
* @pre none.
* @param number must be a positive int value.
* @post courseNumber is set to number.
*/
  void setCourseNumber(int number);

/*
* @pre none.
* @post return courseNumber.
*/
  int getCourseNumber() const;

/*
* @pre none.
* @param numberEnrolled must be greater than 0.
* @post classEnrollment is set to numberEnrolled, array of student is created from the given size.
*/
  void setSize(int numberEnrolled);

/*
* @pre none.
* @post return.
*/
  int getSize() const;

/*
* @pre array of student is created from setSize.
* @param position must be a valid number between 0 and classEnrollment, IDNumber must be a postive int value.
* @post student ID number is set within a given position in the array of student.
*/
  void setStudent(int position, int IDNumber);

/*
* @pre array of student is created from setSize.
* @param position must be a valid number between 0 and classEnrollment.
* @post return student ID number from aray of student.
*/
  int getStudent(int position) const;

  Course();
};
#endif
