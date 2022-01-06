#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

extern void BubbleSort(std::vector<int>& arr);
extern void SelectSort(std::vector<int>& arr);
extern void InsertSort(std::vector<int>& arr);
extern void MergeSort(std::vector<int>& arr);

std::vector<int> generateArray() {
    unsigned len = rand() % 10;
    std::vector<int> res;
    for (unsigned i = 0; i < len; i++) {
        res.push_back(rand() % 10);
    }
    return res;
}

void showArray(const std::vector<int> arr) {
    std::cout << "[";
    for (auto x : arr) {
        std::cout << x << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char** argv) {
    srand( (unsigned)time( NULL ) );
    for (unsigned i = 0; i < 1; i++) {
        auto arr = generateArray();
        auto ori = arr;
        auto bubbleArr = ori;
        auto selectArr = ori;
        auto insertArr = ori;
        auto mergeArr = ori;

        std::sort(arr.begin(), arr.end());
        BubbleSort(bubbleArr);
        SelectSort(selectArr);
        InsertSort(insertArr);
        MergeSort(mergeArr);

        if (bubbleArr != arr) {
            showArray(ori);
            showArray(arr);
            showArray(bubbleArr);
            printf("bubble sort failed\n");
        }

        if (selectArr != arr) {
            showArray(ori);
            showArray(arr);
            showArray(selectArr);
            printf("select sort failed\n");
        }

        if (insertArr != arr) {
            showArray(ori);
            showArray(arr);
            showArray(insertArr);
            printf("select sort failed\n");
        }

        if (mergeArr != arr) {
            showArray(ori);
            showArray(arr);
            showArray(mergeArr);
            printf("merge sort failed\n");
        }    
    }

    return 0;
}
