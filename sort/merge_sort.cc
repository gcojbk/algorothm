#include <vector>
#include "common.h"

static void merge(std::vector<int>& arr, unsigned left, unsigned mid, unsigned right) {
    std::vector<int> tmp(right - left + 1);
    unsigned i = left, j = mid + 1;
    unsigned p = 0;
    while (i <= mid && j <= right) {
        tmp[p++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) {
        tmp[p++] = arr[i++];
    }
    while (j <= right) {
        tmp[p++] = arr[j++];
    }
    
    for (unsigned k = 0; k < tmp.size(); k++) {
        arr[left + k] = tmp[k];
    }
}

static void sort(std::vector<int>& arr, unsigned left, unsigned right) {
    if (left >= right) {
        return;
    }
    unsigned mid = left + ((right - left) >> 1);
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
} 

void MergeSort(std::vector<int>& arr) {
    auto n = arr.size();
    if (n == 0) {
        return;
    }
    sort(arr, 0, arr.size() - 1);
}
