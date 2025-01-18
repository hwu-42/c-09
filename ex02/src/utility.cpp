#include "../include/utility.h"

// Convert a string to an integer and return true if successful
bool stringToInt(const std::string& str, int& result) {
    std::istringstream iss(str);
    iss >> result;
    // Check for errors: input must fully convert and not leave extra characters
    return !iss.fail() && iss.eof();
}

// Check if a list is sorted in ascending order
bool isSorted(std::list<int>& numbers) {
    std::list<int>::iterator it = numbers.begin();
    for (long unsigned int i = 0; i < numbers.size() - 1; ++i) {
        if (*it > *(++it)) {
            return false;
        }
    }
    //std::cout << "List is sorted\n";
    return true;
}

int power(int b, int a) {
    int result = 1;
    for (int i = 0; i < a; i++) {
        result *= b;
    }
    return result;
}

void    printList(const std::string message, std::list<int> & l) {
    std::cout << message << std::endl;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

