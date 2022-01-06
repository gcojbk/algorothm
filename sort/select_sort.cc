#include <vector>
#include "common.h"

void SelectSort(std::vector<int>& arr) {
    auto n = arr.size();
    if (n == 0) {
        return;
    }
    for (unsigned i = 0; i < n - 1; i++) {
        unsigned min = arr[i];
        unsigned minIndex = i;
        for(unsigned j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
}