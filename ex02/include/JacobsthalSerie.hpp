#pragma once
#include <iostream>
#include <list>
#include <stdexcept>

class Jacobsthal {
private:
    std::list<int> numbers; // Stores Jacobsthal numbers
    std::list<int>::iterator it; // Iterator for traversal
    std::list<int> pace;
    std::list<int>::iterator pi;

    // Helper function to calculate Jacobsthal numbers
    int calculateJacobsthal(int n) const;

public:
    // Default constructor
    Jacobsthal();

    // Parameterized constructor
    Jacobsthal(int max);

    // Copy constructor
    Jacobsthal(const Jacobsthal& other);

    // Copy assignment operator
    Jacobsthal& operator=(const Jacobsthal& other);

    // Destructor
    ~Jacobsthal();

    // Reset the iterator to the beginning of the list
    void reset();

    void resetPace();

    // Return the current value and move the iterator to the next element
    int next();
    int nextPace();
    // Print all Jacobsthal numbers (for debugging purposes)
    void printNumbers() const;
    void printPace() const;
};
