#include <chrono>
#include <iostream>
#include <vector>
#include "efficency.h"
#include "fill_array.h"
#include <thread>
#include <mutex>

std::mutex cout_mutex;

void measureTime(Function funcPtr, int* nums, int size) {
    auto start = std::chrono::steady_clock::now();
    funcPtr(nums, size);
    auto end = std::chrono::steady_clock::now();

    const auto duration = end - start;
    std::cout << "\t\tTime: " << std::chrono::duration<double, std::milli>(duration).count() << " ms\n";
    std::cout << "\t\tTime: " << std::chrono::duration<double>(duration).count() << " s\n";
}

void variousCaseTest(Function funcPtr, const std::vector<int>& data) {
    std::lock_guard<std::mutex> lock(cout_mutex);
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
    std::lock_guard<std::mutex> lock(cout_mutex);
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
    std::lock_guard<std::mutex> lock(cout_mutex);
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


void runTest(Function funcPtr_1, Function funcPtr_2, const std::vector<int>& data) {
    std::cout << "I.\tTEST FOR SELECTION SORT" << std::endl;
    std::cout << "selectionSort1" << std::endl;
    std::thread t1(variousCaseTest, funcPtr_1, data);
    t1.join();
    std::cout << "selectionSort2" << std::endl;
    std::thread t2(grownCaseTest, funcPtr_1, data);
    t2.join();
    std::cout << "selectionSort3" << std::endl;
    std::thread t3(downCaseTest, funcPtr_1, data);
    t3.join();

    std::cout << "II.\tTEST FOR BUBBLE SORT" << std::endl;
    std::cout << "buubleSort1" << std::endl;
    std::thread t4(variousCaseTest, funcPtr_2, data);
    t4.join();
    std::cout << "buubleSort2" << std::endl;
    std::thread t5(grownCaseTest, funcPtr_2, data);
    t5.join();
    std::cout << "buubleSort3" << std::endl;
    std::thread t6(downCaseTest, funcPtr_2, data);
    t6.join();

}
