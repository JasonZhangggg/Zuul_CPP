/*
Jason Zhang
Zuul
12/2/2019
*/


#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;
//constructor
Item:: Item(char* newName){
  //set the name
  name = new char [strlen(newName)+1];
  strcpy(name, newName);
}
//get the name
char* Item:: getName(){
  return name;
}
