/*
Jason Zhang
Zuul
12/2/2019
*/
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;
//constructor
Room::Room(char* newName, char* newDescription){
  //declare name and description
  name = new char [strlen(newName)+1]; 
  description = new char [strlen(newDescription)+1];
  strcpy(description, newDescription);
  strcpy(name, newName);
  exits = new map<char*, Room*>();
  items = new vector<Item*>();
}
//get the rooms description
char* Room::getDescription(){
  return description;
}
//get the rooms items
vector<Item*>* Room::getItems(){
  return items;
}
//add items into the room
void Room::addItem(Item* item){
  items->push_back(item);
}
//get the rooms name
char* Room:: getName(){
  return name;
}
//remove a item
void Room::removeItem(Item* item){
  //iterate through and remove the item
  vector<Item*>::iterator i;
  for(i=items->begin(); i!= items->end();i++){
    if(strcmp((*i)->getName(), item->getName()) == 0){
      delete *i;
      i = items->erase(i);
      return;
    }
  }
}
//add a exit to the map
void Room::addExit(char* dir, Room* room){
  (*exits)[dir] = room;
}
//get all of the exits
map<char*, Room*>* Room::getExits(){
  return exits;
}
