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

void Operator::insertPlayer() {
  cout << "\nPreparing to Insert a Player...\n";

  //int index = 0;

  //myList.insert(1, value);
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Hash Table Program!\n\n";
  int value = 0;
  ifstream inFile;
  Player* newPlayer = nullptr;
  hashTableLength = 5;

  LinkedList<Player> hashTable[hashTableLength];

  //hashTable = LinkedList<Player*>[hashTableLength] table ;

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

        newPlayer = new Player();

        newPlayer->setName(playerName);
        newPlayer->setGoalRecord(playerGoalRecord);

        hashTable[index].insert(1, Player(playerName, playerGoalRecord));

        newPlayer = nullptr;
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
        // 1. AddPlayer
        if (option == 1) {
          cout << "\nPreparing to Insert a New Element...\n";

          /*
          int value;
          cout << "\nChoose a number to be inserted:\n\n> ";
          cin >> value;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nChoose a number to be inserted:\n\n> ";
              cin >> value;
            } else {
              try {
                cout << "\nInserting " << value << " at the front of the list...\n";
                //myList.insert(1, value);
                cout << value << " is inserted.\n\n";
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Position!\n\n";
              }

              break;
            }
          }
          */
        }
        // 2. RemovePlayer
        else if (option == 2) {
          /*
          if (myList.getLength() > 0) {
            cout << "\nPreparing to Delete a Listed Element...\n";

            int value;
            cout << "\nChoose a number to be deleted from the list:\n\n> ";
            cin >> value;

            while(1) {
              if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\n\nERROR! Invalid entry!\n\n";
                cout << "\nChoose a number to be deleted from the list:\n\n> ";
                cin >> value;
              } else {
                try {
                  cout << "\nDeleting " << value << " from this list...\n\n";
                  int position = 1;

                  bool isFound = false;
                  while (position <= myList.getLength()) {
                    if (myList.getEntry(position) == value) {
                      myList.remove(position);
                      isFound = true;
                      break;
                    }
                    position++;
                  }

                  if(!isFound)
                    cout << value << " is NOT found in the list.\n\n";
                  else
                    cout << "The last occurrence of " << value << " has been deleted from the list.\n\n";
                } catch (runtime_error) {
                  cout << "\nERROR! Invalid Position!\n\n";
                }

                break;
              }
            }
          } else {
            cout << "\nERROR! List is Empty.\n\n";
          }
          */
        }
        // 3. PrintPlayersList - Complete!
        else if (option == 3) {
          cout << "\nPrinting List of Players...\n\n";

          for(int i = 0; i < hashTableLength; i++)
          {
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
        // 4. PlayerWithGoalCountEqualTo(g)
        else if (option == 4) {
          cout << "\nPrinting List of Elements...\n";

          /*
          try {
            if (myList.getLength() > 0) {
              cout << "List: ";
              for (int i = 1; i <= myList.getLength(); i++) {
                cout << myList.getEntry(i) << " ";
              }
              cout << "\n\n";
            } else {
              cout << "\nCannot print list.\nList is Empty.\n\n";
            }
          } catch (runtime_error) {
            cout << "\nERROR! Invalid Position!\n\n";
          }
          */
        }
        // 5. PlayerWithNumGoalsGreaterThan(h)
        else if (option == 5) {
          cout << "\nPrinting List of Elements...\n";

          /*
          try {
            if (myList.getLength() > 0) {
              cout << "List: ";
              for (int i = 1; i <= myList.getLength(); i++) {
                cout << myList.getEntry(i) << " ";
              }
              cout << "\n\n";
            } else {
              cout << "\nCannot print list.\nList is Empty.\n\n";
            }
          } catch (runtime_error) {
            cout << "\nERROR! Invalid Position!\n\n";
          }
          */
        }
        // 6. PlayerWithNumGoalsLessThan(i)
        else if (option == 6) {
          cout << "\nPrinting List of Elements...\n";

          /*
          try {
            if (myList.getLength() > 0) {
              cout << "List: ";
              for (int i = 1; i <= myList.getLength(); i++) {
                cout << myList.getEntry(i) << " ";
              }
              cout << "\n\n";
            } else {
              cout << "\nCannot print list.\nList is Empty.\n\n";
            }
          } catch (runtime_error) {
            cout << "\nERROR! Invalid Position!\n\n";
          }
          */
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
  //hashTable.clear();

  value = 0;

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}
