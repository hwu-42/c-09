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

void binaryInsert(List& mainchain, List& numbers, LI it1start, LI it1end) {
    LI it2start = mainchain.begin();
    LI it2end = advancen(it2start, 1);
    while (it2end != mainchain.end()) {
        if (*it1start < *it2start) {
            mainchain.splice(it2start, numbers, it1start, it1end);
            return;
        }
        it2start = it2end;
        it2end = advancen(it2start, 1);
    }
    mainchain.splice(mainchain.end(), numbers, it1start, it1end);
}

void insertLeftlumps(List& numbers, List& mainchain, int lump, int lenth, Jacobsthal& ja) {
    
    while (lump > 0) {
        int i = ja.nextPace();
        if (i > lump)
            i = lump;
        LI it1start = advancen(numbers.begin(), (i - 1) * lenth);
        LI it1end = advancen(it1start, lenth);
        while (true) {
            binaryInsert(mainchain, numbers, it1start, it1end);
            i--;
            lump--;
            if (i == 0)
                break;
            else
                it1start = backn(it1end, lenth);
        }
    }
}

void insert_mainchain(List& numbers, List& mainchain, int round, int odd[32]) {
    round--;
    
    //std::cout << "Insert mainchain\n";
    Jacobsthal ja(numbers.size());
    ja.printPace();
    int lenth;
    int lump = 1;
    LI it1start;
    LI it1end;
    int i = 0;
    //ja.printNumbers();
    //std::cout << std::endl;
    //ja.printPace();
    //std::cout << std::endl;
        /*LI it1start = numbers.begin();
        LI it1end = advancen(it1start, lenth);
        std::cout << "it1start1: " << *it1start << " it1end: " << *it1end << std::endl;
        mainchain.splice(mainchain.begin(), numbers, it1start, it1end);
        std::cout << "it1start2: " << *it1start << " it1end: " << *it1end << std::endl;
        printList("mainchain:\n", mainchain);
        printList("numbers:\n", numbers);
        it1start = advancen(numbers.begin(),lenth);
        it1end = advancen(it1start, lenth);*/

    //for (;round > -1; round--) {
        i = 1;
        lenth = power(2, round);
        int lumpleft = lump - 1 + odd[round];//this is the number of unsorted lumps left after moving sorted lumps to mainchain
        lump = lump * 2 + odd[round];
        it1start = numbers.begin();
        it1end = advancen(it1start, lenth);
        mainchain.splice(mainchain.end(), numbers, it1start, it1end);
        i++;
        while (i < lump) {
            it1start = it1end;
            it1end = advancen(it1start, lenth);
            if (i % 2 == 0)
                mainchain.splice(mainchain.end(), numbers, it1start, it1end);
            i++;
        }
        std::cout << "round: " << round << std::endl;
        std::cout << "lenth: " << lenth << std::endl;
        std::cout << "lump: " << lump << std::endl;
        std::cout << "after move soted to mainchain: " << std::endl;
        printList("mainchain:\n", mainchain);
        printList("numbers:\n", numbers);
        insertLeftlumps(numbers, mainchain, lumpleft, lenth, ja); 
        ja.resetPace();
        std::cout << "after insert left lumps: " << std::endl;
        printList("mainchain:\n", mainchain);
        printList("numbers:\n", numbers);
        numbers.splice(numbers.begin(), mainchain);
        std::cout << "after move back numbers: " << std::endl;
        printList("mainchain:\n", mainchain);
        printList("numbers:\n", numbers);
    //}
    (void)mainchain;
    (void)round;
    (void)odd;
    (void)lump;
    (void)lenth;
    (void)it1start;
    (void)it1end;
    (void)lumpleft;
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
