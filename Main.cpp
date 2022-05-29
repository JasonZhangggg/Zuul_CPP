/*
Jason Zhang
12/2/2019
Zuul
*/

#include <iostream>
#include <vector>
#include <cstring>
#include "Item.h"
#include "Room.h"
using namespace std;

void grab(vector<Item*>*, Room*);
void drop(vector<Item*>*, Room*);
Room* go(Room*);

int main(){
  //create a map of the board
  map<char*, Room*>* mm = new map<char*, Room*>;
  //add all the locations and their descriptions to the map
  (*mm)["Power plant"] = new Room("Power plant", "A nuclear power plant that generates the cities electricity. The air is very dusty.");
  (*mm)["McDonalds"] = new Room("McDonalds", "The delicious smell of burgers floats over to your nose.");
  (*mm)["Gym"] = new Room("Gym", "Where you exercise.");
  (*mm)["Electronic store"] = new Room("Electronic store", "Full of expensive electronics. You dont want to break anything.");
  (*mm)["Townhall"] = new Room("Townhall", "Where the mayor lives.");
  (*mm)["Elementary school"] = new Room("Elementary school", "Full of loud children throwing food.");
  (*mm)["High school"] = new Room("High school", "Half the students are yelling at eachother, the other half on their phone.");
  (*mm)["Middle school"] = new Room("Middle school", "All the students are in class.");
  (*mm)["DMV"] = new Room("DMV", "You enter and get told the line is 10 hours long");
  (*mm)["Hospital"] = new Room("Hospital", "You hear a cough.");
  (*mm)["Expo center"] = new Room("Expo center", "The large facility is empty.");
  (*mm)["Grocery store"] = new Room("Grocery store", "Full of fresh and cheap foods");
  (*mm)["Dentist"] = new Room("Dentist", "The help desk is empty. Nothing to see");
  (*mm)["Pub"] = new Room("Pub", "Bang! You see two drunk people fighting");
  (*mm)["Movie theater"] = new Room("Movie theater", "A very old movie is playing");

  //add all of the exits
  (*mm)["Power plant"] -> addExit("SOUTH", (*mm)["McDonalds"]);
  (*mm)["McDonalds"] -> addExit("SOUTH", (*mm)["Gym"]);
  (*mm)["McDonalds"] -> addExit("EAST", (*mm)["Electronic store"]);
  (*mm)["Gym"]->addExit("NORTH", (*mm)["McDonalds"]);
  (*mm)["Electronic store"]->addExit("WEST", (*mm)["McDonalds"]);
  (*mm)["Electronic store"]->addExit("EAST", (*mm)["Townhall"]);
  (*mm)["Townhall"]->addExit("WEST", (*mm)["Electronic store"]);
  (*mm)["Townhall"]->addExit("SOUTH", (*mm)["Elementary school"]);
  (*mm)["Townhall"]->addExit("EAST", (*mm)["Expo center"]);
  (*mm)["Elementary school"]->addExit("NORTH", (*mm)["Townhall"]);	
  (*mm)["Elementary school"]->addExit("SOUTH", (*mm)["Middle school"]);
  (*mm)["Middle school"]->addExit("NORTH", (*mm)["Elementary school"]);
  (*mm)["Middle school"]->addExit("EAST", (*mm)["Hospital"]);
  (*mm)["Middle school"]->addExit("SOUTH", (*mm)["DMV"]);
  (*mm)["Middle school"]->addExit("WEST", (*mm)["High school"]);
  (*mm)["High school"]->addExit("EAST", (*mm)["Middle school"]);
  (*mm)["DMV"]->addExit("NORTH", (*mm)["Middle school"]);
  (*mm)["Hospital"]->addExit("WEST", (*mm)["Middle school"]);
  (*mm)["Expo center"]->addExit("WEST", (*mm)["Townhall"]);
  (*mm)["Expo center"]->addExit("NORTH", (*mm)["Dentist"]);
  (*mm)["Expo center"]->addExit("EAST", (*mm)["Grocery store"]);
  (*mm)["Grocery store"]->addExit("WEST", (*mm)["Expo center"]);
  (*mm)["Dentist"]->addExit("SOUTH", (*mm)["Expo center"]);
  (*mm)["Dentist"]->addExit("NORTH", (*mm)["Pub"]);
  (*mm)["Pub"]->addExit("SOUTH", (*mm)["Dentist"]);
  (*mm)["Pub"]->addExit("WEST", (*mm)["Movie theater"]);
  (*mm)["Movie theater"]->addExit("EAST", (*mm)["Pub"]);
  (*mm)["DMV"]->addItem(new Item("waiting ticket"));
  (*mm)["Electronic store"] -> addItem(new Item("computer"));
  (*mm)["Grocery store"] -> addItem(new Item("apple"));
  (*mm)["McDonalds"] -> addItem(new Item("burger"));
  (*mm)["Hospital"] -> addItem(new Item("medicine"));
  char blank[80] = "";
  //give instructions
  cout<<"Mayor: Hello! I am the mayor of this town. If you do not mind, could you do a task for me?(press enter to continue)"<<endl;
  //once they press enter continue
  cin.getline(blank, 999);
  cout<<"Mayor: I need you to get a waiting ticket from the DMV, my son needs it for his permit!"<<endl;
  cin.getline(blank, 999);
  cout<<"Mayor: I also need you to grab a new computer from the electronic store."<<endl;
  cin.getline(blank, 999);
  cout<<"Mayor: Also if you don't mind, go to the grocery store and get an apple."<<endl;
  cin.getline(blank, 999);
  cout<<"Mayor: Also get a burger from McDonalds for I am very hungry"<<endl;
  cin.getline(blank, 999);
  cout<<"Mayor: Finaly, could you grab me some medicine. My wife is sick."<<endl;
  cin.getline(blank, 999);
  cout<<"Once you are done, just return here, the townhall! Again, thank you!"<<endl;
  cin.getline(blank, 999);
  //current room
  Room* current = (*mm)["Townhall"];
  //your inventory
  vector<Item*>* inventory = new vector<Item*>;
  while(true){
    Room* test = (*mm)["Middle school"];
    //if the user got all of the items and returned to the townhall they win
    if(strcmp(current->getName(), "Townhall") == 0 && inventory->size() == 5){
      cout<<"You win!"<<endl;
      return 0;
    }
    //print the current room the user is in
    cout<<"You are currently in a: "<<current->getName()<<endl;
    cout<<"Description: "<<current->getDescription()<<endl;
    //iterate through the current rooms exits and print all of them
    map<char*, Room*>* exits = current -> getExits();
    cout<<"Exits: "<<endl;
    map<char*, Room*>::iterator ei;
    for(ei = exits->begin(); ei!=exits->end(); ei++){
      cout<<ei->first<<" has " <<ei->second->getName()<<endl;
    }
    cout<<endl;
    //iterate through the items in the room and print them
    cout<<"Items in this room: ";
    vector<Item*>* items = current->getItems();
    vector<Item*>::iterator ii;
    for(ii = items->begin(); ii!=items->end();ii++){
      cout<<(*ii)->getName()<<", ";
    }
    cout<<endl;
    //iterate through the items in your inventory and print them
    cout<<"Your inventory has: ";
    vector<Item*>::iterator inventoryi;
    for(inventoryi = inventory->begin(); inventoryi!=inventory->end(); inventoryi++){
      cout<<(*inventoryi)->getName()<<", ";
    }
    cout<<endl;
    //take in the user input
    cout<<"Would you like to GRAB, DROP, GO, or QUIT"<<endl;
    char input[80];
    cin.getline(input, sizeof(input));
    for(int i = 0; i<sizeof(input); i++){
      input[i] = toupper(input[i]);
    }
    //if they called grab, then grab
    if(strcmp(input, "GRAB") == 0){
      grab(inventory, current);
    }
    //if they called drop, then drop
    else if(strcmp(input, "DROP") == 0){
      drop(inventory, current);
    }
    //if they called go, then go
    else if(strcmp(input, "GO") == 0){
      //set current room the the room the user wanted to move into
      current = go(current);
    }
    //if they called quite, then quit
    else if(strcmp(input, "QUIT") == 0){
      return 0;
    }
    else{
      cout<<"Please type GO, DROP, GRAB, or QUIT"<<endl;
    }
    cout<<"_________________________________________________________"<<endl;
  }
}

void grab(vector<Item*>*inventory, Room* room){
  //ask what the user wants to grab
  cout<<"What item would you like to grab?"<<endl;
  char input[80];
  cin.getline(input, sizeof(input));
  for(int i = 0; i<sizeof(input); i++){
    input[i] = tolower(input[i]);
  }
  //iterate through the items in the room to see if it exists
  vector<Item*>* items = room -> getItems();
  vector<Item*>::iterator i;
  for(i = items->begin(); i!= items->end(); i++){
    if(strcmp((*i)->getName(), input) == 0){
      //remove the item from the room and add it to the inventory
      room->removeItem(*i);
      inventory->push_back(new Item(input));
      cout<<"The item has been added to your inventory"<<endl;
      return;
    }
  }
  cout<<"The item was not found"<<endl;
}
Room* go(Room* room){
  //ask user where they want to go
  char input[80];
  cout<<"What direction would you like to go?"<<endl;
  cin.getline(input, sizeof(input));
  for(int i = 0; i<sizeof(input); i++){
    input[i] = toupper(input[i]);
  }
  //iterate through the exits and see if the room exists
  map<char*, Room*>* exits = room->getExits();
  map<char*, Room*>::iterator i;
  for(i = exits->begin(); i!= exits->end(); i++){
    if(strcmp(input, i->first) == 0){
      //return the room
      cout<<"Moved into the "<<i->second->getName()<<endl;
      return i->second;
    }
  }
  cout<<"Could not find that exit"<<endl;
  return room;
}

void drop(vector<Item*>*inventory, Room* room){
  //ask user what item they want to drop
  cout<<"What item would you like to drop?"<<endl;
  char input[80];
  cin.getline(input, sizeof(input));
  for(int i = 0; i<sizeof(input); i++){
    input[i] = tolower(input[i]);
  }
  //iterate through your inventory to see if the item exists
  vector<Item*>::iterator i;
  for(i = inventory->begin(); i!= inventory->end(); i++){
    if(strcmp((*i)->getName(), input) == 0){
      //remove the item from your inventory
      delete *i;
      i = inventory->erase(i);
      //add it to the room
      room->addItem(new Item(input));
      cout<<"The item has been droped"<<endl;
      return;
    }
  }
  cout<<"The item was not found"<<endl;
}
