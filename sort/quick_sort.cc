#include <vector>
#include "common.h"

static void partition(std::vector<int>& arr, int left, int right, int& lRes, int& rRes) {
    int less = left - 1;
    int cur = left;
    int more = right;
    int key = arr[right];
    while (cur < more) {
        if (arr[cur] < key) {
            swap(arr, ++less, cur++);
        } else if (arr[cur] > key) {
            swap(arr, --more, cur);
        } else {
            cur++;
        }
    }
    swap(arr, more, right);
    lRes = less;
    rRes = more;
}

static void quicksort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int lres, rres;
        partition(arr, left, right, lres, rres);
        quicksort(arr, left, lres - 1);
        quicksort(arr, rres + 1, right);
    }
}

void QuickSort(std::vector<int>& arr) {
    auto n = arr.size();
    if (n == 0) {
        return;
    }
    quicksort(arr, 0, arr.size() - 1);
}
