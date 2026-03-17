
// ****************************************************
// Recursive Dream - main.cpp
// Entry point for the project
// Demonstrates recursion, file I/O, and OOP
// ****************************************************

#include "Character.h"
#include <iostream>
using namespace std;

int main() {
    // Create a Character object and load commands from file
    Character Dom("commands.txt");
    cout << endl << endl;

    // Print commands in reverse order
    Dom.printCommands();
    cout << endl << endl;

    // Start recursive dream sequence
    cout << "Calling startDreaming() function from main.." << endl;
    Dom.startDreaming();
    cout << endl;
}