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