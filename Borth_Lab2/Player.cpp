/* -----------------------------------------------------------------------------
*
* File Name:  Course.cpp
* Author: Marco Borth
* Assignment:   EECS-560 Lab 2 - Implementation of Hash Table
* Description:  Player set and get methods defined here.
* Date: 2/4/20
*
---------------------------------------------------------------------------- */

#include "Player.h"
#include <string>
using namespace std;

Player::Player(){}

Player::Player(string alias, int goals) {
  name = alias;
  goalRecord = goals;
}

void Player::setName(string alias) {
  if(alias.length() > 0) {
    name = alias;
  }
}

string Player::getName() const {
  return(name);
}

void Player::setGoalRecord(int number) {
  if(number > 0) {
    goalRecord = number;
  }
}

int Player::getGoalRecord() const {
  return(goalRecord);
}
