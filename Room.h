/*
Jason Zhang
Zuul
12/2/2019
*/

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
using namespace std;
class Room
{
 public:
  //declare all of the methods
  Room(char*, char*);
  vector<Item*>* getItems();
  char* getDescription();
  char* getName();
  void removeItem(Item*);
  void addItem(Item*);
  void addExit(char*, Room*);
  map<char*, Room*>* getExits();
 private:
  //declare all of the variables
  vector<Item*>* items;
  char* description;
  map<char*, Room*>* exits;
  char* name;
};
#endif
