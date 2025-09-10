//Description: RECURSION_INCEPTION

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"
#include "Dream.h"

using namespace std;

Character::Character(string filename){
    //Assign index to -1 to start before command
    currentIndex = -1; 
    //Open file
    iFile.open(filename);

    //If files opens
    if(iFile.is_open()){
        //Reads recursively
        readFromFile();
    }
}

//Destructor
Character::~Character(){
    //If file opens
    if(iFile.is_open()){
        //Close file
        iFile.close(); 
    }
}

//Stores in reverse order
void Character::readFromFile(){
    string temp;
    
    //Reads info from file
    if(getline(iFile, temp)){
        readFromFile();
        //Add current line
        commands.push_back(temp);
    }
}

//Displays commmands stored in vector
void Character::printCommands(){
    //Commands recieved message
    cout << "The following are the commands received:\n";

    for (size_t i = 0; i < commands.size(); ++i) {
        //Display commands
        cout << commands[i];

        //Remove newline of the last command
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
