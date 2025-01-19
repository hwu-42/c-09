#include "utility.h"

template <typename Iterator>
Iterator advancen(Iterator it, int steps) {
    while (steps-- > 0) {
        ++it;
    }
    return it;
}

template <typename Iterator>
Iterator backn(Iterator it, int steps) {
    while (steps-- > 0) {
        --it;
    }
    return it;
}