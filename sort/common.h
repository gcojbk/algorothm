#pragma once

#include <cassert>
#include <vector>

static void swap(std::vector<int>& arr, unsigned a, unsigned b) {
    assert(a < arr.size() && b < arr.size() && "Swap out range of array.");
    if (a == b) {
        return;
    }
    arr[a] ^= arr[b];
    arr[b] ^= arr[a];
    arr[a] ^= arr[b];
}