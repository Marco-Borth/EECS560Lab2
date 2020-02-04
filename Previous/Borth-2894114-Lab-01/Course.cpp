/* -----------------------------------------------------------------------------
*
* File Name:  Course.cpp
* Author: Marco Borth
* Assignment:   EECS-268 Lab 1 Program
* Description:  Course set and get methods defined here.
* Date: 2/8/19
*
---------------------------------------------------------------------------- */

#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

Course::Course()
{

}

void Course::setDepartmentCode(string code)
{
  if(code.length() > 0)
  {
    departmentCode = code;
  }
}

string Course::getDepartmentCode() const
{
  return(departmentCode);
}

void Course::setCourseNumber(int number)
{
  if(number > 0)
  {
    courseNumber = number;
  }
}

int Course::getCourseNumber() const
{
  return(courseNumber);
}

void Course::setSize(int numberEnrolled)
{
  if(numberEnrolled > 0)
  {
    size = numberEnrolled;
		student = new int[numberEnrolled];
  }
}

int Course::getSize() const
{
  return(size);
}

void Course::setStudent(int position, int IDNumber)
{
  if(IDNumber > 0)
  {
    student[position] = IDNumber;
  }
}

int Course::getStudent(int position) const
{
  return(student[position]);
}
