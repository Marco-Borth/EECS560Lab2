/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.h
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 2 - Implementation of Hash Table
 * Description:  Operator Class is defined.
 * Date: 2/4/20
 *
 ---------------------------------------------------------------------------- */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "LinkedList.h"
#include "Player.h"
#include <string>
#include <stdexcept>
using namespace std;

class Operator
{
private:
  int option;
  int hashTableLength;
  LinkedList<Player>* hashTable;
  string file;
  string fileInputInt;
  string playerName;
  int playerGoalRecord;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

  void printCommands();

  void insertPlayer();

/*
* @pre filename is a string.
* @post Operator object is constructed, file == filename.
*/
  Operator(string filename);
};
#endif