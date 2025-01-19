#pragma once

#include <iostream>

#include "../include/PmergeMe.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include "common.h"

bool stringToInt(const std::string& str, int& result);
bool isSorted(std::list<int>& numbers);
bool isSorted(std::vector<int>& numbers);
int power(int b, int a);
void    printList(const std::string message, std::list<int> & l);
void    printVector(const std::string message, std::vector<int> & l);

template <typename Iterator>
Iterator advancen(Iterator it, int steps);

template <typename Iterator>
Iterator backn(Iterator it, int steps);

#include "advancen.tpp"