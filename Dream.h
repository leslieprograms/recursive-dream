
#ifndef DREAM_H
#define DREAM_H

// ****************************************************
// Dream.h
// Declares Dream class
// Manages dream levels and dynamic memory allocation
// ****************************************************

class Dream {
private:
    int dreamLevel; // Current dream level
    int *ptr;       // Pointer to dynamically allocated array

public:
    Dream(int numElements, int value); // Constructor
    ~Dream();                          // Destructor
};

#endif