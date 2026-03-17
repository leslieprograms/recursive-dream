
// ****************************************************
// DreamImp.cpp
// Implements Dream class methods
// Manages dream levels and dynamic memory allocation
// ****************************************************

#include <iostream>
#include "Dream.h"

using namespace std;

// Constructor: Allocates memory and displays dream level
Dream::Dream(int numElements, int value) : dreamLevel(value){
    cout << "Start of Dream level: " << dreamLevel << "\n";
    ptr = new int[numElements];
    for (int i = 0; i < numElements; i++){
        ptr[i] = dreamLevel;
    }
    cout << "         Dynamically allocating " << numElements << " elements.\n";
    cout << "\n";
}

// Destructor: Frees memory and displays end of dream level
Dream::~Dream(){
    if (dreamLevel == 1) {
        cout << "End of Dream level: " << dreamLevel;
    } else {
        cout << "End of Dream level: " << dreamLevel << "\n";
    }
    delete[] ptr;
    ptr = nullptr;
}
