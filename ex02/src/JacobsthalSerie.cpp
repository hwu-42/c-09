#include "../include/JacobsthalSerie.hpp"


int Jacobsthal::calculateJacobsthal(int n) const {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return calculateJacobsthal(n - 1) + 2 * calculateJacobsthal(n - 2);
}


// Default constructor
Jacobsthal::Jacobsthal() : numbers(), it(numbers.end()), pace(), pi(pace.end()){}

// Parameterized constructor
Jacobsthal::Jacobsthal(int max) : numbers(), it(numbers.end()), pace(), pi(pace.end()) {
    for (int i = 0; ; ++i) {
        int value = calculateJacobsthal(i);
        if (value > max) break;
        numbers.push_back(value);
    }
    reset(); // Initialize the iterator to the start
    it++;
    int i = *it;
    it++;
    for (; it != numbers.end(); ++it) {
        pace.push_back(*it - i);
        i = *it;
    }
    resetPace();
    reset();
}

// Copy constructor
Jacobsthal::Jacobsthal(const Jacobsthal& other) : numbers(other.numbers), it(numbers.begin()) {
    std::list<int>::const_iterator otherIt = other.numbers.begin();
    for (; otherIt != other.it; ++otherIt, ++it);
    for (std::list<int>::const_iterator it = other.pace.begin(); it != other.pace.end(); ++it) {
        pace.push_back(*it);
    }
    reset();
    resetPace();
}

// Copy assignment operator
Jacobsthal& Jacobsthal::operator=(const Jacobsthal& other) {
    if (this != &other) {
        numbers = other.numbers;
        pace = other.pace;
        reset();
        resetPace();
    }
    return *this;
}

// Destructor
Jacobsthal::~Jacobsthal() {}

// Reset the iterator to the beginning of the list
void Jacobsthal::reset() {
    it = numbers.begin();
}

// Return the current value and move the iterator to the next element
int Jacobsthal::next() {
    if (it == numbers.end()) {
        throw std::out_of_range("Iterator has reached the end of the list");
    }
    return *(it++);
}

int Jacobsthal::nextPace() {
    if (pi == pace.end()) {
        throw std::out_of_range("Iterator has reached the end of the list");
    }
    return *(pi++);
}

// Print all Jacobsthal numbers (for debugging purposes)
void Jacobsthal::printNumbers() const {
    std::cout << "Jacobsthal numbers: ";
    std::list<int>::const_iterator it = numbers.begin();
    for (; it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Jacobsthal::resetPace() {
    pi = pace.begin();
}

void Jacobsthal::printPace() const {
    std::cout << "Pace: ";
    std::list<int>::const_iterator it = pace.begin();
    for (; it != pace.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
