#include <iostream>

#include "../include/PmergeMe.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctime>

bool stringToInt(const std::string& str, int& result) {
    std::istringstream iss(str);
    iss >> result;

    // Check for errors: input must fully convert and not leave extra characters
    return !iss.fail() && iss.eof();
}

void load_numbers(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (!PmergeMe::validateInput(argv[i])) {
            throw std::invalid_argument("Invalid input: " + std::string(argv[i]));
        }
    }
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided.\n";
        return 1;
    }
    PmergeMe sorter;
    if (argc == 3 && std::string(argv[1]) == "fill") {
        int num;
        if (!stringToInt(argv[2], num)) {
            std::cerr << "Error: Invalid input.\n";
            return 1;
        }
        srand(time(0));
        sorter.fillNumbers(num);
    }
    else {
        try {
            load_numbers(argc, argv);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }
    }
    std::vector<int> vec;
    std::list<int> lst;

    try {
        for (int i = 1; i < argc; ++i) {
            if (!PmergeMe::validateInput(argv[i])) {
                throw std::invalid_argument("Invalid input: " + std::string(argv[i]));
            }
            int num = std::atoi(argv[i]);
            vec.push_back(num);
            lst.push_back(num);
        }

        std::cout << "Before: ";
        for (const int& num : vec) std::cout << num << " ";
        std::cout << "\n";

        PmergeMe sorter;

        // Sort using vector
        clock_t startVec = clock();
        sorter.sortVector(vec);
        clock_t endVec = clock();

        // Sort using list
        clock_t startList = clock();
        sorter.sortList(lst);
        clock_t endList = clock();

        std::cout << "After: ";
        for (const int& num : vec) std::cout << num << " ";
        std::cout << "\n";

        double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
        double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << vec.size() 
                  << " elements with std::vector: " << timeVec << "s\n";
        std::cout << "Time to process a range of " << lst.size() 
                  << " elements with std::list: " << timeList << "s\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
