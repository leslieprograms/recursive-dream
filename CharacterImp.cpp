
// ****************************************************
// CharacterImp.cpp
// Implements Character class methods
// Handles command loading, printing, and recursion logic
// ****************************************************

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"
#include "Dream.h"

using namespace std;

// Constructor: Loads commands from file
Character::Character(string filename){
    currentIndex = -1; // Start before command
    iFile.open(filename);
    if(iFile.is_open()){
        readFromFile(); // Recursively read commands
    }
}

// Destructor: Closes file
Character::~Character(){
    if(iFile.is_open()){
        iFile.close(); 
    }
}

// Recursively stores commands in reverse order
void Character::readFromFile(){
    string temp;
    if(getline(iFile, temp)){
        readFromFile();
        commands.push_back(temp); // Add current line
    }
}

// Prints commands stored in vector
void Character::printCommands(){
    cout << "The following are the commands received:\n";
    for (size_t i = 0; i < commands.size(); ++i) {
        cout << commands[i];
        if (i != commands.size() - 1) {
            cout << "\n";
        }
    }
}

//Reverses string
string Character::reverseString(string command, 
string reverseCommand, int index){
    //If index is less than 0, return an empty string
    if (index < 0){
        return reverseCommand;
    }
    reverseCommand += command[index];
    //Add the current character + recurse
    return reverseString(command, reverseCommand, index - 1);
}

int Character::fibonacci(int num){
    //Base case
    if (num <= 0){
        return 0; 
    }
    //Base case
    if (num == 1){
        return 1;
    }
    
    //Sum of two fibonacci numbers
    return fibonacci(num - 1) + fibonacci(num - 2);
}

//Starts the dream process
void Character::startDreaming(){
    //Next command
    currentIndex++;
    if(currentIndex >= static_cast<int>(commands.size())){
        currentIndex--;
        return;
    }
    
    //Calculate dream level
    int dreamLevel = currentIndex + 1;

    //Get current command
    string command = commands[currentIndex];

    //Reverse command
    string reversed = reverseString
    (command, "", command.size() - 1);
    
    //Create dream object
    Dream *dream = new Dream(fibonacci(dreamLevel), 
    dreamLevel);
    
    if (command == reversed || currentIndex == 
    static_cast<int>(commands.size()) - 1){
        //Free memory 
        delete dream;
        //Back to previous level
        currentIndex--;
        return;
    }

    //Call dream level
    startDreaming();
    
    //Free memory for dream object
    delete dream;

    //Back to previous command
    currentIndex--;
}
