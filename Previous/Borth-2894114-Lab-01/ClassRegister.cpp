/* -----------------------------------------------------------------------------
 *
 * File Name:  ClassRegister.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 1 Program
 * Description:  ClassRegister run method and operations are defined.
 * Date: 2/8/19
 *
 ---------------------------------------------------------------------------- */

#include "ClassRegister.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ClassRegister::ClassRegister(const string filename)
{
	file = filename;
	ifstream inFile;

	//Open File.
	inFile.open(file);

	if (!inFile.is_open())
	{
		cout << "File name not valid!\n";
	}
	inFile >> numberOfClasses;
	enrollment = new Course[numberOfClasses];
	for (int i = 0; i < numberOfClasses; i++)
	{
		string code;
		int number;
		int size;
		int* student;

		inFile >> code >> number >> size;

		enrollment[i].setDepartmentCode(code);
		enrollment[i].setCourseNumber(number);
		enrollment[i].setSize(size);

		student = new int[size];
		for (int j = 0; j < size; j++)
		{
			inFile >> student[j];
			enrollment[i].setStudent(j, student[j]);
		}
	}

	// Close File.
	inFile.close();
}


void ClassRegister::run()
{
  cout << "\nWelcome to Schedule of Classes!\n\n";

  do {
    cout << "Select User Option:\n\n";

    cout << "1. Print all courses.\n";
    cout << "2. Print all courses for a department.\n";
    cout << "3. Print roster for a course.\n";
    cout << "4. Print largest class.\n";
    cout << "5. Swap two classes.\n";
    cout << "6. Print schedule for student.\n";
    cout << "7. Exit Program.\n\n";

    cout << "Option: ";
    cin >> option;

    if (option == 1)
    {
      cout << "\nPrinting all courses....\n\n";
      printAllCourses();
      cout << "\n";
    }
    else if (option == 2)
    {
      string code;
      cout << "\nSelect Department.\n";
      cout << "Department Code: ";
      cin >> code;

      cout << "\nPrinting department courses....\n\n";
      printDepartmentCourses(code);
      cout << "\n";
    }
    else if (option == 3)
    {
      string code;
      int courseNumber;
      cout << "\nEnter Course\n";
      cout << "Course: ";
      cin >> code >> courseNumber;

      cout << "\nPrinting " << code << " " << courseNumber << " course roster....\n\n";
      printCourseRoster(code, courseNumber);
      cout << "\n";
    }
    else if (option == 4)
    {
      cout << "\nPrinting largest class....\n\n";
      printLargestClass();
      cout << "\n";
    }
    else if (option == 5)
    {
      string code1, code2;
      int courseNumber1, courseNumber2;
			cout << "\nEnter First Course\n";
      cout << "First Course: ";
      cin >> code1 >> courseNumber1;

			cout << "\nEnter Second Course\n";
      cout << "Second Course: ";
      cin >> code2 >> courseNumber2;

      cout << "\nSwapping Selected Classes " << code1 << " " << courseNumber1 << " and " << code2 << " " << courseNumber2 << "....\n\n";
      swapClasses(enrollment, code1, courseNumber1, code2, courseNumber2);
      cout << "\n";
    }
    else if (option == 6)
    {
      int studentNumber;
      cout << "\nEnter Student ID\n";
      cout << "Student ID: ";
      cin >> studentNumber;

      cout << "\nPrinting classes student number " << studentNumber << " is enrolled intoxs....\n\n";
      printStudentSchedule(studentNumber);
      cout << "\n";
    }
    else if (option == 7)
    {
      cout << "\nClosing Program...\n";
    }
    else
    {
      cout << "\nInvalid Option...\n\n";
    }
  } while(option != 7);

  cout << "\nHave a nice day!...\n\n";
}

// Option 1. Print all courses
void ClassRegister::printAllCourses()
{
  for (int i = 0; i < numberOfClasses; i++)
  {
    cout << enrollment[i].getDepartmentCode()<< " ";
    cout << enrollment[i].getCourseNumber() << "\n";
  }
}

// Option 2. Print all courses for a department.
void ClassRegister::printDepartmentCourses(string department)
{
    for (int i = 0; i < numberOfClasses; i++)
    {
      if (enrollment[i].getDepartmentCode() == department)
      {
        cout << enrollment[i].getDepartmentCode()<< " ";
        cout << enrollment[i].getCourseNumber() << "\n";
      }
    }
}

// Option 3. Print roster for a course.
void ClassRegister::printCourseRoster(string department, int number)
{
  for (int i = 0; i < numberOfClasses; i++)
  {
    if ((enrollment[i].getDepartmentCode() == department) && (enrollment[i].getCourseNumber() == number))
    {
      for (int j = 0; j < enrollment[i].getSize(); j++)
      {
        cout << enrollment[i].getStudent(j);

        if (j != enrollment[i].getSize() - 1)
        {
          cout << ", ";
        }
        else
        {
          cout << "\n";
        }
      }
    }
  }
}

// Option 4. Print largest class.
void ClassRegister::printLargestClass()
{
  int largestClassIndex = 0;
  int classSize = 0;

  for (int i = 0; i < numberOfClasses; i++)
  {
    if (classSize < enrollment[i].getSize())
    {
      classSize = enrollment[i].getSize();
      largestClassIndex = i;
    }
  }

  cout << enrollment[largestClassIndex].getDepartmentCode() << " ";
	cout << enrollment[largestClassIndex].getCourseNumber() << " ";
	cout << enrollment[largestClassIndex].getSize() << "\n";
}

// Option 5. Swap two classes
void ClassRegister::swapClasses(Course*& original, string firstCode, int firstNumber, string secondCode, int secondNumber)
{
	string tempDepartmentCode1, tempDepartmentCode2;
  int tempCourseNumber1, tempCourseNumber2;
  int tempSize1, tempSize2;
  int* tempStudent1 = nullptr;
	int* tempStudent2 = nullptr;

	// Copying parameter courses to temporary variables initialized.
	for (int i = 0; i < numberOfClasses; i++)
	{
		// First Course Copied to first temp variables.
		if ((original[i].getDepartmentCode() == firstCode) && (original[i].getCourseNumber() == firstNumber))
		{
			tempDepartmentCode1 = original[i].getDepartmentCode();
			tempCourseNumber1 = original[i].getCourseNumber();
			tempSize1 = original[i].getSize();

			tempStudent1 = new int[tempSize1];
			for (int j = 0; j < original[i].getSize(); j++)
			{
				tempStudent1[j] = original[i].getStudent(j);
			}
		}
		// Second Course Copied to second temp variables.
		else if ((original[i].getDepartmentCode() == secondCode) && (original[i].getCourseNumber() == secondNumber))
		{
			tempDepartmentCode2 = original[i].getDepartmentCode();
			tempCourseNumber2 = original[i].getCourseNumber();
			tempSize2 = original[i].getSize();

			tempStudent2 = new int[tempSize2];
			for (int j = 0; j < original[i].getSize(); j++)
			{
				tempStudent2[j] = original[i].getStudent(j);
			}
		}
	}

	// Eror Handling for invalid course entries
	if (((tempDepartmentCode1 != firstCode) && (tempCourseNumber1 != firstNumber)) || ((tempDepartmentCode2 != secondCode) && (tempCourseNumber2 != secondNumber)))
	{
		cout << "ERROR!\nCannot swap courses....\n";
	}
	else
	{
		// Swapping Courses begins.
		for (int i = 0; i < numberOfClasses; i++)
		{
			// First Course swapped with second temp variables.
			if ((original[i].getDepartmentCode() == firstCode) && (original[i].getCourseNumber() == firstNumber))
			{
				enrollment[i].setDepartmentCode(tempDepartmentCode2);
				enrollment[i].setCourseNumber(tempCourseNumber2);
				enrollment[i].setSize(tempSize2);

				for (int j = 0; j < enrollment[i].getSize(); j++)
				{
					enrollment[i].setStudent(j, tempStudent2[j]);
				}
			}
			// Second Course swapped with first temp variables.
			else if ((original[i].getDepartmentCode() == secondCode) && (original[i].getCourseNumber() == secondNumber))
			{
				enrollment[i].setDepartmentCode(tempDepartmentCode1);
				enrollment[i].setCourseNumber(tempCourseNumber1);
				enrollment[i].setSize(tempSize1);

				for (int j = 0; j < enrollment[i].getSize(); j++)
				{
					enrollment[i].setStudent(j, tempStudent1[j]);
				}
			}
		}
		cout << "Swapping Courses Completed.\n";
	}
}

// Option 6. Print schedule for student.
void ClassRegister::printStudentSchedule(int studentID)
{
  for (int i = 0; i < numberOfClasses; i++)
  {
    for (int j = 0; j < enrollment[i].getSize(); j++)
    {
      if (enrollment[i].getStudent(j) == studentID)
      {
        cout << enrollment[i].getDepartmentCode()<< " ";
        cout << enrollment[i].getCourseNumber() << "\n";
      }
    }
  }
}
