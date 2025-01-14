#include "../include/PmergeMe.hpp"


PmergeMe::PmergeMe() {
    num = 0;
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // Implement copy constructor
    this->num = other.num;
    this->numbersv = other.numbersv;
    this->numbersl = other.numbersl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    // Implement copy assignment
    if (this != &other)
    {
        this->num = other.num;
        this->numbersv = other.numbersv;
        this->numbersl = other.numbersl;
    }
    return *this;
}

int PmergeMe::get_num() {
    return num;
}

void PmergeMe::sortVector() {
    // Implement Ford-Johnson for vector
    std::cout << "Implement Ford-Johnson for vector\n";
}

void PmergeMe::sortList() {
    // Implement Ford-Johnson for list
    std::cout << "Implement Ford-Johnson for list\n";
}

/*
bool PmergeMe::validateInput(const std::string& input) {
    for (char c : input) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}*/

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
        num++;
    }
}

void PmergeMe::printNumbers() const {
    // Implement printNumbers
    std::cout << "Vector:\n";
    for (std::vector<int>::const_iterator it = numbersv.begin(); it != numbersv.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nList:\n";
    for (std::list<int>::const_iterator it = numbersl.begin(); it != numbersl.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}