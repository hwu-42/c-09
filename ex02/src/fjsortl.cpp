/*Implement Ford-Johnson for list*/

#include "../include/fjsort.h"


/*void insert_mainchain(std::list<int>& small, std::list<int>& big) {
    std::list<int>::iterator it = small.begin();
    for (long unsigned int i = 0; i < small.size(); ++i) {
        if (*it < big.front()) {
            big.push_front(*it);
        }
    }}
// Implement Ford-Johnson for list
void fjsortl(std::list<int>& numbers, long unsigned int n) {
    if (isSorted(numbers)) {
        return;
    }
    std::cout << "Implement Ford-Johnson for list\n";
    std::list<int> big, small;
    std::list<int>::iterator it = numbers.begin();
    for (long unsigned int i = 0; i < n / 2; ++i) {
        int a = *it;
        int b = *(++it);
        big.push_back(std::max(a, b));
        small.push_back(std::min(a, b));
        ++it;
    }
    if (n % 2 == 1) {
        small.push_back(*it);
    }
    fjsortl(big, big.size());
    insert_mainchain(small, big); // insert unsorted small into sorted big
}*/



int binary_sort(std::list<int>& numbers, long unsigned int n, int odd[32]) {
    int round = 0;
    int lenth;
    while (n > 1) {
        lenth = power(2, round);
        std::list<int>::iterator it = numbers.begin();
        for (long unsigned int i = 0; i < n / 2; ++i) {
            int a = *it;
            int b = *(++it);
            if (a > b) {
                std::swap(a, b);
            }
            *it = a;
            *(++it) = b;
            ++it;
        }
        if (n % 2 == 1) {
            odd[round] = *it;
        }
        n = n / 2;
        ++round;
    }

    return round;
}

void insert_mainchain(std::list<int>& numbers, std::list<int>& mainchain) {
    std::cout << "Insert mainchain\n";
}

void fjsortl(std::list<int>& numbers, long unsigned int n) {
    if (isSorted(numbers)) {
        return;
    }
    int odd[32];
    std::cout << "Implement Ford-Johnson for list\n";
    binary_sort(numbers , n, odd);
    std::list<int> mainchain;
    insert_mainchain(numbers, mainchain); // insert unsorted small into sorted big
}
