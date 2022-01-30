// Author: Maks Mishin
// Date: 1/30/2022

#ifndef LEARNING_ALGORITHMS_BINARY_SEARCH_H
#define LEARNING_ALGORITHMS_BINARY_SEARCH_H

#include <vector>

/*
 * Implementation of linear binary search for integer numbers
 * requirement - list should be sorted
 */
int binarySearch(const std::vector<int>& list, int item) {
    int low = 0,
            high = list.size() - 1,
            mid, guess;

    while (low <= high) {
        mid = (low + high) / 2;
        guess = list[mid];
        if (guess == item) {
            return mid;
        }
        if (guess > item) {
            high = mid - 1;
        }
        if (guess < item) {
            low = mid + 1;
        }
    }
    return -1;
}

/*
 * Implementation of recursive binary search for integer numbers
 * requirement - list should be sorted
 */
int recursiveBinarySearch(const std::vector<int>& list, int item, int min, int max) {
    if (max < min)
        return -1;

    int mid = (max + min) / 2;
    if (list[mid] == item)
        return mid;
    if (list[mid] > item)
        return recursiveBinarySearch(list, item, min, mid - 1);
    if (list[mid] < item)
        return recursiveBinarySearch(list, item, mid + 1, max);
    return -1;
}

#endif //LEARNING_ALGORITHMS_BINARY_SEARCH_H
