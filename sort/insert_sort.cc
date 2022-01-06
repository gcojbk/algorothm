#include <vector>
#include "common.h"

void InsertSort(std::vector<int>& arr) {
    auto n = arr.size();
    if (n == 0) {
        return;
    }
    for(unsigned i = 0; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if (arr[j] > arr[j - 1]) {
                break;
            }
            swap(arr, j, j-1);
        }
    }
}