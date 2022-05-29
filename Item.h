/*
Jason Zhang
Zuul
12/2/2019
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item{
 // methods and constructor
 public:
  Item(char*);
  char* getName();
 private:
  //variables
  char* name;
};
#endif
