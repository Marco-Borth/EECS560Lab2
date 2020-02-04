/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 1 Program
 * Description:  Executive Class creates and runs driver class: ClassRegister.
 * Date: 2/8/19
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "ClassRegister.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Create Executive and Course Objects.
Executive::Executive(const string filename)
{
	file = filename;
}

void Executive::run()
{
	ClassRegister userInterface(file);
	userInterface.run();
}
