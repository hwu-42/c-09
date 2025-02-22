#include "../include/PmergeMe.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctime>





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
            sorter.loadNumbers(argc, argv);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }
    }

    std::cout << "Before sorting:\n";
    sorter.printNumbers();
    std::cout << std::endl;

    try {
        // Sort using vector
        clock_t startVec = clock();
        sorter.sortVector();
        clock_t endVec = clock();

        // Sort using list
        clock_t startList = clock();
        sorter.sortList();
        clock_t endList = clock();

        std::cout << "After:\n";
        sorter.printNumbers();
        std::cout << "\n";

        double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
        double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << sorter.get_num() 
                  << " elements with std::vector: " << timeVec << "s\n";
        std::cout << "Time to process a range of " << sorter.get_num() 
                  << " elements with std::list: " << timeList << "s\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
