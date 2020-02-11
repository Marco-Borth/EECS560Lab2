/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 2 - Implementation of Hash Table
 * Description:  Operator Class will either run the Interactive program for a Hash Table
 * Date: 2/4/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

Operator::Operator(string filename){
  file = filename;
  srtInput = "\0";
  intInput = "\0";
  playerName = "\0";
  playerGoalRecord = 0;
}

void Operator::printCommands() {
  cout << "Please choose one of the following commands:\n\n";
  cout << "1. AddPlayer\n";
  cout << "2. RemovePlayer\n";
  cout << "3. PrintPlayersList\n";
  cout << "4. PlayerWithGoalCountEqualTo(g)\n";
  cout << "5. PlayerWithNumGoalsGreaterThan(h)\n";
  cout << "6. PlayerWithNumGoalsLessThan(i)\n";
  cout << "7. Exit\n\n> ";
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Hash Table Program!\n\n";
  int value = 0;
  ifstream inFile;
  hashTableLength = 5;

  LinkedList<Player> hashTable[hashTableLength];

  //Open File.
  inFile.open(file);

  if (!inFile.is_open()) {
    cout << "File name not valid!\n";
  } else {
    while (!inFile.eof( )) {
      inFile >> srtInput >> intInput;

      string strParser = "\0";

      for (int i = 0; i < srtInput.length(); i++) {
        if(srtInput.at(i) != ':')
        strParser = strParser + srtInput.at(i);
      }

      playerName = strParser;
      strParser = "\0";

      for (int i = 0; i < intInput.length(); i++) {
        if(intInput.at(i) == '0' || intInput.at(i) == '1' || intInput.at(i) == '2' || intInput.at(i) == '3' || intInput.at(i) == '4'
        || intInput.at(i) == '5' || intInput.at(i) == '6' || intInput.at(i) == '7' || intInput.at(i) == '8' || intInput.at(i) == '9')
          strParser = strParser + intInput.at(i);
      }

      playerGoalRecord = stoi(strParser);
      strParser = "\0";

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
      } else {
        int index = 0;
        index = playerGoalRecord % hashTableLength;

        hashTable[index].insert(hashTable[index].getLength() + 1, Player(playerName, playerGoalRecord));
      }
    }
  }

  // Close File.
  inFile.close();

  do {
    printCommands();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printCommands();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. AddPlayer - Complete, but prone to input errors!
        if (option == 1) {
          cout << "\nPreparing to Insert a New Record...\n";

          cout << "\nEnter the record to be inserted:\n\n> ";
          cin >> srtInput;

          string strParser = "\0";

          for (int i = 0; i < srtInput.length(); i++) {
            if(srtInput.at(i) != ':')
            strParser = strParser + srtInput.at(i);
          }

          playerName = strParser;
          strParser = "\0";

          cin >> playerGoalRecord;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nEnter the record to be inserted:\n\n> ";
              cin >> srtInput;

              string strParser = "\0";

              for (int i = 0; i < srtInput.length(); i++) {
                if(srtInput.at(i) != ':')
                strParser = strParser + srtInput.at(i);
              }

              playerName = strParser;
              strParser = "\0";

              cin >> playerGoalRecord;
            } else {
              try {
                cout << "\nInserting " << playerName << " into the records...\n";

                bool isFound = false;

                for(int i = 0; i < hashTableLength; i++) {
                  if (hashTable[i].getLength() > 0) {
                    for (int j = 1; j <= hashTable[i].getLength(); j++) {
                      if (hashTable[i].getEntry(j).getName() == playerName && hashTable[i].getEntry(j).getGoalRecord() == playerGoalRecord) {
                        isFound = true;
                      }
                    }
                  }
                }

                if(isFound)
                  cout << "ERROR! Duplicate Entry Found. Player Record was not successfully inserted.\n\n";
                else {
                  int index = 0;
                  index = playerGoalRecord % hashTableLength;

                  hashTable[index].insert(hashTable[index].getLength() + 1, Player(playerName, playerGoalRecord));

                  cout << "Player Record was successfully inserted.\n\n";
                }
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Position!\n\n";
              }

              break;
            }
          }
        }
        // 2. RemovePlayer - Complete!
        else if (option == 2) {
          cout << "\nPreparing to Delete a Record...\n";

          int value;
          cout << "\nEnter a record with required goals to be removed:\n\n> ";
          cin >> value;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nEnter a record with required goals to be removed:\n\n> ";
              cin >> value;
            } else {
              try {
                cout << "\nDeleting any player found with " << value << " goals recorded from this list...\n\n";

                bool isFound = false;
                int index = 0;
                int position = 0;

                for(int i = 0; i < hashTableLength; i++) {
                  if (hashTable[i].getLength() > 0) {
                    for (int j = 1; j <= hashTable[i].getLength(); j++) {
                      if (hashTable[i].getEntry(j).getGoalRecord() == value) {
                        index = i;
                        position = j;
                        isFound = true;
                      }
                    }
                  }
                }

                if(!isFound)
                  cout << "ERROR! No Record Found.\n\n";
                else {
                  hashTable[index].remove(position);

                  cout << "Player Record was successfully inserted.\n\n";
                }
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Position!\n\n";
              }

              break;
            }
          }
        }
        // 3. PrintPlayersList - Complete!
        else if (option == 3) {
          cout << "\nPrinting List of Players...\n\n";

          for(int i = 0; i < hashTableLength; i++) {
            cout << i << ":";
            try {
              if (hashTable[i].getLength() > 0) {
                for (int j = 1; j <= hashTable[i].getLength(); j++) {
                  cout << " -> ";
                  cout << hashTable[i].getEntry(j).getName() << " " << hashTable[i].getEntry(j).getGoalRecord();
                }
              }
            } catch (runtime_error) {
              cout << "\nERROR! Invalid Position!\n\n";
            }
            cout << "\n";
          }
          cout << "\n";
        }
        // 4. PlayerWithGoalCountEqualTo(g) - Complete!
        else if (option == 4) {
          cout << "\nPrinting List of Players with the same goal count...\n";

          cout << "\nEnter the goal count:\n\n> ";
          cin >> value;

          bool isFound = false;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nEnter the goal count:\n\n> ";
              cin >> value;
            } else {
              for(int i = 0; i < hashTableLength; i++) {
                try {
                  if (hashTable[i].getLength() > 0) {
                    for (int j = 1; j <= hashTable[i].getLength(); j++) {
                      if (hashTable[i].getEntry(j).getGoalRecord() == value) {
                        cout << hashTable[i].getEntry(j).getName() << ", ";
                        isFound = true;
                      }
                    }
                  }
                } catch (runtime_error) {
                  cout << "\nERROR! Invalid Position!\n\n";
                }
              }
              if(!isFound)
                cout << "There is no player with "<< value << " goals found.";
              cout << "\n\n";

              break;
            }
          }
        }
        // 5. PlayerWithNumGoalsGreaterThan(h) - Complete!
        else if (option == 5) {
          cout << "\nPrinting List of Players with same goal count or higher...\n";

          cout << "\nEnter the goal count:\n\n> ";
          cin >> value;

          bool isFound = false;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nEnter the goal count:\n\n> ";
              cin >> value;
            } else {
              for(int i = 0; i < hashTableLength; i++) {
                try {
                  if (hashTable[i].getLength() > 0) {
                    for (int j = 1; j <= hashTable[i].getLength(); j++) {
                      if (hashTable[i].getEntry(j).getGoalRecord() >= value) {
                        cout << hashTable[i].getEntry(j).getName() << ", ";
                        isFound = true;
                      }
                    }
                  }
                } catch (runtime_error) {
                  cout << "\nERROR! Invalid Position!\n\n";
                }
              }
              if(!isFound)
                cout << "There is no player with "<< value << ", or more, goals found.";
              cout << "\n\n";

              break;
            }
          }
        }
        // 6. PlayerWithNumGoalsLessThan(i) - Complete!
        else if (option == 6) {
          cout << "\nPrinting List of Players with the smae goal count or lower...\n";

          cout << "\nEnter the goal count:\n\n> ";
          cin >> value;

          bool isFound = false;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nEnter the goal count:\n\n> ";
              cin >> value;
            } else {
              for(int i = 0; i < hashTableLength; i++) {
                try {
                  if (hashTable[i].getLength() > 0) {
                    for (int j = 1; j <= hashTable[i].getLength(); j++) {
                      if (hashTable[i].getEntry(j).getGoalRecord() <= value) {
                        cout << hashTable[i].getEntry(j).getName() << ", ";
                        isFound = true;
                      }
                    }
                  }
                } catch (runtime_error) {
                  cout << "\nERROR! Invalid Position!\n\n";
                }
              }
              if(!isFound)
                cout << "There is no player with "<< value << ", or less, goals found.";
              cout << "\n\n";

              break;
            }
          }
        }
        // 7. Exit - Complete!
        else if (option == 7) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 7);

  for (int i = 0; i < hashTableLength; i++)
    hashTable[i].~LinkedList();

  srtInput = "\0";
  intInput = "\0";
  playerName = "\0";
  playerGoalRecord = 0;
  value = 0;

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}
