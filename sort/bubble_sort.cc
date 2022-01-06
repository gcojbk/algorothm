#include <vector>
#include "common.h"

void BubbleSort(std::vector<int>& arr) {
    auto n = arr.size();
    if (n == 0) {
        return;
    }
    for(size_t i = 1; i < n; i++) {
        for (size_t j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}