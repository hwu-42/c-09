#pragma once

#include <vector>
#include <list>
#include <string>
#include "utility.h"
#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <ctime>
#include "fjsort.h"
#include "common.h"

class PmergeMe {
private:
    long unsigned int num;
    std::vector<int> numbersv;
    std::list<int> numbersl;

    //void merge(std::vector<int>& numbers, std::vector<int>& left, std::vector<int>& right);
    //void merge(std::list<int>& numbers, std::list<int>& left, std::list<int>& right);
public:
    PmergeMe();
    ~PmergeMe();

    void printNumbers() const;

    void fillNumbers(int n);

    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    int get_num();

    void sortVector();
    void sortList();

    //static bool validateInput(const std::string& input);
    void loadNumbers(int argc, char* argv[]);
};
