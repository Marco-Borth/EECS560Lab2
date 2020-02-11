/* -----------------------------------------------------------------------------
*
* File Name:  Player.h
* Author: Marco Borth
* Assignment:   EECS-560 Lab 2 - Implementation of Hash Table
* Description:  Player Class is defined.
* Date: 2/4/20
*
---------------------------------------------------------------------------- */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <stdexcept>
using namespace std;

class Player
{
private:
  string name;
  int goalRecord;

public:
/*
* @pre none.
* @param alias must be a string value.
* @post name is set to alias.
*/
  void setName(string alias);

/*
* @pre none.
* @post return name value.
*/
  string getName() const;

/*
* @pre none.
* @param number must be a positive int value.
* @post goalRecord is set to number.
*/
  void setGoalRecord(int number);

/*
* @pre none.
* @post return goalRecord.
*/
  int getGoalRecord() const;

  Player();

  ~Player();

  Player(string alias, int goals);
};
#endif
