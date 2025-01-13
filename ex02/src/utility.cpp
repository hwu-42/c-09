#include "../include/utility.h"

bool stringToInt(const std::string& str, int& result) {
    std::istringstream iss(str);
    iss >> result;

    // Check for errors: input must fully convert and not leave extra characters
    return !iss.fail() && iss.eof();
}