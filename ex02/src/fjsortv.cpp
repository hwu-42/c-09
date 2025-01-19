/*Implement Ford-Johnson for vector*/

#include "../include/fjsort.h"



/*void splicev(Vector& mainchain, VI position, Vector& numbers, VI itstart, VI itend) {
    // Check if the range is valid
    if (itstart == itend) {
        return; // Nothing to splice if the range is empty
    }

    // Step 1: Create a temporary vector to store the elements to be spliced
    Vector temp(itstart, itend);

    // Step 2: Erase the elements from the source vector (numbers)
    numbers.erase(itstart, itend);

    // Step 3: Insert the copied elements into the target vector (mainchain)
    mainchain.insert(position, temp.begin(), temp.end());
}

void splicev(Vector& mainchain, VI position, Vector& numbers) {
    // Step 1: Create a temporary vector to store the elements to be spliced
    Vector temp(numbers.begin(), numbers.end());

    // Step 2: Erase the elements from the source vector (numbers)
    numbers.clear();

    // Step 3: Insert the copied elements into the target vector (mainchain)
    mainchain.insert(position, temp.begin(), temp.end());
}*/

void swapv(Vector& numbers, int start1, int start2, int lenth) {
    int temp[lenth];
    for (int i = 0; i < lenth; ++i) {
        temp[i] = numbers[start1 + i];
    }
    for (int i = 0; i < lenth; ++i) {
        numbers[start1 + i] = numbers[start2 + i];
        numbers[start2 + i] = temp[i];
    }
}

int binary_sort_vector(std::vector<int>& numbers, long unsigned int n, int odd[32]) {
    int round = 0;
    int lenth;
    while (n > 1) {
        lenth = power(2, round);
        int start1 = 0;
        int end1 = lenth - 1;
        int start2 = lenth;
        int end2 = 2 * lenth - 1;
        for (long unsigned int i = 0; i < n / 2; ++i) {
            if (numbers[end1] > numbers[end2])
                swapv(numbers, start1, start2, lenth);
            start1 += lenth * 2;
            end1 += lenth * 2;
            start2 += lenth * 2;
            end2 += lenth * 2;
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

void binaryInsert(Vector& mainchain, Vector& numbers, VI it1start, VI it1end, int lenth) {
    //std::cout << "binaryInsert:\nit1start: " << *it1start << " it1end: " << *it1end << std::endl;
    VI it = mainchain.begin();
    int l = mainchain.size();
    int lump = l / lenth - 1;
    int i;
    int start = 0;
    int end = lump;
    //it1end--;
    int value = *(it1end - 1);
    //it1end++;
    if (value < *(it + lenth - 1)) {
        //splicev(mainchain, it, numbers, it1start, it1end);
        mainchain.insert(mainchain.begin(), it1start, it1end);
        numbers.erase(it1start, it1end);
        return;
    }

    if (value > *(mainchain.end() - 1)) {
        //splicev(mainchain, mainchain.end(), numbers, it1start, it1end);
        mainchain.insert(mainchain.end(), it1start, it1end);
        numbers.erase(it1start, it1end);
        return;
    }
    
    VI itm;
    while (end - start > 1) {
        i = (start + end) / 2;
        itm = it + i * lenth + lenth - 1;
        if (value < *itm)
            end = i;
        else
            start = i;
    }
    it = it + end * lenth;
    //splicev(mainchain, it, numbers, it1start, it1end);
    mainchain.insert(it, it1start, it1end);
    numbers.erase(it1start, it1end);
}

void insertLeftlumps(Vector& numbers, Vector& mainchain, int lump, int lenth, Jacobsthal& ja) {
    
    while (lump > 0) {
        int i = ja.nextPace();
        if (i > lump)
            i = lump;
        VI it1start = numbers.begin() + (i - 1) * lenth;
        VI it1end = it1start + lenth;
        while (true) {
            binaryInsert(mainchain, numbers, it1start, it1end, lenth);
            i--;
            lump--;
            if (i == 0)
                break;
            else {
                it1start = numbers.begin() + (i - 1) * lenth;
                it1end = it1start + lenth;
            }
        }
    }
}

void insert_mainchain(Vector& numbers, Vector& mainchain, int round, int odd[32]) {
    round--;
    Jacobsthal ja(numbers.size());
    //ja.printPace();
    int lenth;
    int lump = 1;
    VI it1start;
    VI it1end;
    //int start1;
    //int end1;
    int i = 0;
    for (;round > -1; round--) {
        //std::cout << "round: " << round << "***********************" << std::endl;
        i = 0;
        lenth = power(2, round);
        int lumpleft = lump - 1 + odd[round];//this is the number of unsorted lumps left after moving sorted lumps to mainchain
        lump = lump * 2 + odd[round];
        it1start = numbers.begin();
        it1end = advancen(it1start, lenth);
        //start1 = 0;
        //end1 = lenth - 1;
        //splicev(mainchain, mainchain.end(), numbers, it1start, it1end);
        mainchain.insert(mainchain.end(), it1start, it1end);
        numbers.erase(it1start, it1end);
        //i++;
        while (i < lump / 2) {
            it1start = numbers.begin() + lenth * i;
            it1end = it1start + lenth;
            mainchain.insert(mainchain.end(), it1start, it1end);
            numbers.erase(it1start, it1end);
            i++;
        }
        //std::cout << "round: " << round << std::endl;
        //std::cout << "lenth: " << lenth << std::endl;
        //std::cout << "lump: " << lump << std::endl;
        //std::cout << "after move sorted to mainchain: " << std::endl;
        //printVector("mainchain:\n", mainchain);
        //printVector("numbers:\n", numbers);
        insertLeftlumps(numbers, mainchain, lumpleft, lenth, ja); 
        ja.resetPace();
        //std::cout << "after insert left lumps: " << std::endl;
        //printVector("mainchain:\n", mainchain);
        //printVector("numbers:\n", numbers);
        //splicev(numbers, numbers.begin(), mainchain);
        numbers.insert(numbers.begin(), mainchain.begin(), mainchain.end());
        mainchain.clear();
        //std::cout << "after move back numbers: " << std::endl;
        //printVector("mainchain:\n", mainchain);
        //printVector("numbers:\n", numbers);
    }
}

void fjsortv(std::vector<int>& numbers, long unsigned int n) {
    if (isSorted(numbers)) {
        return;
    }
    int odd[32];
    //std::cout << "Implement Ford-Johnson for vector\n";
    int round = binary_sort_vector(numbers , n, odd);
    //std::cout << "round: " << round << std::endl;
    //std::cout << "odd: ";
    /*for (int i = 0; i < round; ++i) {
        std::cout << odd[i] << " ";
    }*/
    //std::cout << std::endl;
    //std::cout << "after binary_sort:\n";
    /*for (VI it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/
    std::vector<int> mainchain;
    insert_mainchain(numbers, mainchain, round, odd); // insert unsorted small into sorted big
}
