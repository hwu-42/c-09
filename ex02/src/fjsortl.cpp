/*Implement Ford-Johnson for list*/

#include "../include/fjsort.h"


void insert_mainchain(std::list<int>& small, std::list<int>& big) {
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
}