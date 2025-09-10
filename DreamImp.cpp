//Description: RECURSION_INCEPTION

#include <iostream>
#include "Dream.h"

using namespace std; 

//Constructor
Dream::Dream(int numElements, int value) : dreamLevel(value){
    //Start of dream level message 
    cout << "Start of Dream level: " << dreamLevel << "\n";

    //Array of integers 
    ptr = new int[numElements];
    
    //For loop to assign each element
    for (int i = 0; i < numElements; i++){
        //Assign each element with dream level
        ptr[i] = dreamLevel; 
    }
    //Allocated Message
    cout << "         Dynamically allocating " << numElements 
    << " elements.\n";

    cout << "\n";
}

//Destructor
Dream::~Dream(){
    //Check dream level and display message
    if (dreamLevel == 1) {
        //No newline with dream level: 1
        cout << "End of Dream level: " << dreamLevel;
    } else {
        cout << "End of Dream level: " << dreamLevel << "\n";
    }

    //Free memory
    delete[] ptr; 
    //Set pointer to null 
    ptr = nullptr; 
}
