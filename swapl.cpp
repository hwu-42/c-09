#include <iostream>
#include <list>

// Helper function to advance an iterator by a given number of steps
template <typename Iterator>
Iterator advance(Iterator it, int steps) {
    while (steps-- > 0) {
        ++it;
    }
    return it;
}

void    printList(const std::string message, std::list<int> & l) {
    std::cout << message << std::endl;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int swapl(std::list<int> myList, std::list<int>::iterator firstStart, std::list<int>::iterator firstEnd, std::list<int>::iterator secondStart, std::list<int>::iterator secondEnd) {
    // Splice the second block to the beginning
    std::list<int>::iterator temp = secondStart;
    temp--;
    std::cout << *firstStart << " " << *firstEnd << " " << *secondStart << " " << *secondEnd <<  " " << *temp <<std::endl;
    myList.splice(firstStart, myList, secondStart, secondEnd);
    std::cout << *firstStart << " " << *firstEnd << " " << *secondStart << " " << *secondEnd <<  " " << *temp <<std::endl;
    printList("Modified List:", myList);
    temp++;
    myList.splice(temp, myList, firstStart, firstEnd);
    return 0;
}

int main() {
    std::list<int> myList;

    // Populate the list with 200 elements
    for (int i = 1; i <= 60; ++i) {
        myList.push_back(i);
    }

    // Print the original list
    printList("Original List:", myList);

    // Define iterators to identify the ranges
    std::list<int>::iterator firstStart = myList.begin();
    //firstStart = advance(firstStart, 10);  // Start of the first 100 nodes
    std::list<int>::iterator firstEnd = advance(firstStart, 1);  // End of the first 100 nodes
    std::list<int>::iterator secondStart = advance(firstEnd, 1);              // Start of the second 100 nodes
    std::list<int>::iterator secondEnd = advance(secondStart, 1); // End of the second 100 nodes
    swapl(myList, firstStart, firstEnd, secondStart, secondEnd);
    printList("after swap:", myList);

}