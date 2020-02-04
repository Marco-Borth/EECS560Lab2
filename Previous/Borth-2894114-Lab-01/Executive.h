/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 1 Program
 * Description:  Executive Class is defined.
 * Date: 2/8/19
 *
 ---------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <stdexcept>
using namespace std;

class Executive
{
private:
	string file;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre main.cpp must construct Executive object.
* @param name of the file where course info. is stored into.
* @post Executive object is constructed.
*/
	Executive(const string filename);
};
#endif
