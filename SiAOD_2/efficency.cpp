#include <chrono>
#include <iostream>
#include <vector>
#include "efficency.h"
#include "fill_array.h"

void measureTime(Function funcPtr, int* nums, int size) {
    auto start = std::chrono::steady_clock::now();
    funcPtr(nums, size);
    auto end = std::chrono::steady_clock::now();

    const auto duration = end - start;
    std::cout << "\t\tTime: " << std::chrono::duration<double, std::milli>(duration).count() << " ms\n";
    std::cout << "\t\tTime: " << std::chrono::duration<double>(duration).count() << " s\n";
}

void variousCaseTest(Function funcPtr, const std::vector<int>& data) {
    std::cout << "Test for random nums: " << std::endl;
    for (int size : data) {
        int* nums = new int[size];
        fillArray(nums, size);
        std::cout << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr, nums, size);
        delete[] nums;
        nums = nullptr;
    }
    std::cout << "The end of test" << std::endl;
    std::cout << std::endl;
}

void grownCaseTest(Function funcPtr, const std::vector<int>& data) {
    std::cout << "Test for grown nums: " << std::endl;
    for (int size : data) {
        int* nums = new int[size];
        fillGrownArray(nums, size);
        std::cout << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr, nums, size);
        delete[] nums;
        nums = nullptr;
    }
    std::cout << "The end of test" << std::endl;
    std::cout << std::endl;
}

void downCaseTest(Function funcPtr, const std::vector<int>& data) {
    std::cout << "Test for down nums: " << std::endl;
    for (int size : data) {
        int* nums = new int[size];
        fillDownArray(nums, size);
        std::cout << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr, nums, size);
        delete[] nums;
        nums = nullptr;
    }
    std::cout << "The end of test" << std::endl;
    std::cout << std::endl;
}

//void runTest(Function funcPtr_1, const std::vector<int>& data) {
//    std::cout << "Test for first algorithm" << std::endl;
//    variousCaseTest(funcPtr_1, data);
//}

void runTest2(Function funcPtr_1, const std::vector<int>& data) {
    std::cout << "SELECTION_SORT Test for down nums" << std::endl;
    downCaseTest(funcPtr_1, data);
    std::cout << "SELECTION_SORT Test for grown algorithm" << std::endl;
    grownCaseTest(funcPtr_1, data);
}

void runTest3(Function funcPtr_1, const std::vector<int>& data) {
     std::cout << "BUBBLE_SORT Test for various nums" << std::endl;
    variousCaseTest(funcPtr_1, data);
    std::cout << "BUBBLE_SORT Test for down nums" << std::endl;
//    downCaseTest(funcPtr_1, data);
    std::cout << "BUBBLE_SORT Test for grown algorithm" << std::endl;
    grownCaseTest(funcPtr_1, data);
}