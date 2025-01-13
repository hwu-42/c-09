#pragma once

#include <vector>
#include <list>
#include <string>

class PmergeMe {
private:
    int num;
    std::vector<int> numbersv;
    std::list<int> numbersl;

    void merge(std::vector<int>& numbers, std::vector<int>& left, std::vector<int>& right);
    void merge(std::list<int>& numbers, std::list<int>& left, std::list<int>& right);
public:
    PmergeMe();
    ~PmergeMe();

    void fillNumbers(int n);

    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);


    void sortVector(std::vector<int>& numbers);
    void sortList(std::list<int>& numbers);

    static bool validateInput(const std::string& input);
};
