
#ifndef CHARACTER_H
#define CHARACTER_H

// ****************************************************
// Character.h
// Declares Character class
// Handles command loading, recursion, and dream sequence
// ****************************************************

#include "Dream.h"
#include <fstream>
#include <vector>
using namespace std;

class Character {
private:
    int currentIndex;      // Current command index
    ifstream iFile;        // File stream for commands
    vector<string> commands; // Stores commands

public:
    Character(string filename); // Constructor
    void readFromFile();        // Recursively read commands
    string reverseString(string command, string reverseCommand, int index); // Reverse string recursively
    void printCommands();       // Print commands
    void startDreaming();       // Start recursive dream sequence
    int fibonacci(int n);       // Calculate Fibonacci recursively
    ~Character();               // Destructor
};

#endif