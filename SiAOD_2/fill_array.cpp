#include "fill_array.h"

void fillArray(int* nums, int n) {
    for (int i = 0; i < n; ++i) {
        nums[i] = rand() % 100;
    }
}

void fillGrownArray(int* nums, int n) {
    for (int i = 0; i < n; ++i) {
        nums[i] = i;
    }
}

void fillDownArray(int* nums, int n) {
    for (int i = 0; i < n; ++i) {
        nums[i] = n - i;
    }
}

void printArray(int* nums, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}