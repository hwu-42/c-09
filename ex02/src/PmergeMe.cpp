#include "../include/PmergeMe.hpp"


PmergeMe::PmergeMe() {
    num = 0;
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // Implement copy constructor
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    // Implement copy assignment
    return *this;
}
void PmergeMe::sortVector(std::vector<int>& numbers) {
    // Implement Ford-Johnson for vector
}

void PmergeMe::sortList(std::list<int>& numbers) {
    // Implement Ford-Johnson for list
}

bool PmergeMe::validateInput(const std::string& input) {
    for (char c : input) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

void PmergeMe::fillNumbers(int n) {
    int temp;
    num = n;
    for (int i = 0; i < n; ++i) {
        temp = rand();
        if (std::find(numbersv.begin(), numbersv.end(), temp) != numbersv.end()) {
            --i;
            continue;
        }
        numbersv.push_back(temp);
        numbersl.push_back(temp);
    }
}

void PmergeMe::loadNumbers(int argc, char* argv[]) {
    int temp;
    for (int i = 1; i < argc; ++i) {
        if (!stringToInt(argv[i], temp)) {
            throw std::invalid_argument("Invalid input: " + std::string(argv[i]));
        }
        if (std::find(numbersv.begin(), numbersv.end(), temp) != numbersv.end())
            throw std::invalid_argument("Duplicate input: " + std::string(argv[i]));
        numbersv.push_back(temp);
        numbersl.push_back(temp);
    }
}