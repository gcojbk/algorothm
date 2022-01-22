#include <vector>
#include "common.h"

void BubbleSort(std::vector<int>& arr) {
    auto n = arr.size();
    if (n == 0) {
        return;
    }
    for(std::size_t i = 1; i < n; i++) {
        for (std::size_t j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

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

/// FIXME: [4, 5, 1, 7, 9, 4, 6, 6]
void MergeSort(std::vector<int>& arr) {
    arr = {8, 9, 2, 2, 6, 7, 7, 7, 9};
    auto n = arr.size();
    if (n == 0) {
        return;
    }
    sort(arr, 0, arr.size() - 1);
}
