/*Implement Ford-Johnson for list*/

#include "../include/fjsort.h"

int binary_sort(std::list<int>& numbers, long unsigned int n, int odd[32]) {
    int round = 0;
    int lenth;
    while (n > 1) {
        lenth = power(2, round);
        LI it1start = numbers.begin();
        LI it1end = advancen(it1start, lenth - 1);
        LI it2start = advancen(it1end, 1);
        LI it2end = advancen(it2start, lenth - 1);
        LI it3start = advancen(it2end, 1);
        for (long unsigned int i = 0; i < n / 2; ++i) {
            if (*it1end > *it2end)
                numbers.splice(it1start, numbers, it2start, it3start);
            it1start = it3start;
            it1end = advancen(it1start, lenth - 1);
            it2start = advancen(it1end, 1);
            it2end = advancen(it2start, lenth - 1);
            it3start = advancen(it2end, 1);
        }
        if (n % 2 == 1)
            odd[round] = 1;
        else
            odd[round] = 0;
        n = n / 2;
        ++round;
    }
    return round;
}

void insert_mainchain(List& numbers, List& mainchain, int round, int odd[32]) {
    round--;
    int lenth = power(2, round);
    int lump = 2 + odd[round];
    //std::cout << "Insert mainchain\n";
    Jacobsthal ja(numbers.size());
    //ja.printNumbers();
    //std::cout << std::endl;
    //ja.printPace();
    //std::cout << std::endl;
        LI it1start = numbers.begin();
        LI it1end = advancen(it1start, lenth);
        std::cout << "it1start1: " << *it1start << " it1end: " << *it1end << std::endl;
        mainchain.splice(mainchain.begin(), numbers, it1start, it1end);
        std::cout << "it1start2: " << *it1start << " it1end: " << *it1end << std::endl;
        printList("mainchain:\n", mainchain);
        printList("numbers:\n", numbers);
        it1start = advancen(numbers.begin(),lenth);
        it1end = advancen(it1start, lenth);

    /*for (;round > -1; round--) {
        LI it1start = numbers.begin();
        LI it1end = advancen(it1start, lenth);
        mainchain.splice(mainchain.begin(), numbers, it1start, it1end);

    }*/
    (void)mainchain;
    (void)round;
    (void)odd;
    (void)lump;
}

void fjsortl(std::list<int>& numbers, long unsigned int n) {
    if (isSorted(numbers)) {
        return;
    }
    int odd[32];
    std::cout << "Implement Ford-Johnson for list\n";
    int round = binary_sort(numbers , n, odd);
    std::cout << "round: " << round << std::endl;
    std::cout << "odd: ";
    for (int i = 0; i < round; ++i) {
        std::cout << odd[i] << " ";
    }
    std::cout << "after binary_sort:\n";
    for (LI it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::list<int> mainchain;
    insert_mainchain(numbers, mainchain, round, odd); // insert unsorted small into sorted big
}
