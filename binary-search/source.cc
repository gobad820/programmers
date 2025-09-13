#include <iostream>
#include <vector>

using std::size_t;
using std::vector;

int binarySearch(vector<int> v, int target) {
    size_t left = 0;
    size_t right = v.size() - 1;
    size_t mid = left + (right - left) / 2;

    if (v[mid] == target) {
        return mid;
    } else if (v[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}

/**
 *  Time complexity : lgN
 */