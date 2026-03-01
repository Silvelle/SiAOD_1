#include <chrono>
#include <iostream>
#include <vector>
#include "efficency.h"
#include "fill_array.h"
#include <thread>
#include <mutex>

std::mutex cout_mutex;

void measureTime(Function funcPtr, int* nums, int size, std::stringstream& ss) {
    auto start = std::chrono::steady_clock::now();
    funcPtr(nums, size, ss);
    auto end = std::chrono::steady_clock::now();

    const auto duration = end - start;
    ss << "\t\tTime: " << std::chrono::duration<double, std::milli>(duration).count() << " ms\n";
    ss << "\t\tTime: " << std::chrono::duration<double>(duration).count() << " s\n";
}

void variousCaseTest(Function funcPtr, const std::vector<int>& data, std::stringstream& ss) {
    ss << "Test for random nums: " << std::endl;
    for (int size : data) {
        int* nums = new int[size];
        fillArray(nums, size);
        ss << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr, nums, size, ss);
        delete[] nums;
        nums = nullptr;
    }
    ss << "The end of test" << std::endl;
    ss << std::endl;
}

void grownCaseTest(Function funcPtr, const std::vector<int>& data, std::stringstream& ss) {
    ss << "Test for grown nums: " << std::endl;
    for (int size : data) {
        int* nums = new int[size];
        fillGrownArray(nums, size);
        ss << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr, nums, size, ss);
        delete[] nums;
        nums = nullptr;
    }
    ss << "The end of test" << std::endl;
    ss << std::endl;
}

void downCaseTest(Function funcPtr, const std::vector<int>& data, std::stringstream& ss) {
    ss << "Test for down nums: " << std::endl;
    for (int size : data) {
        int* nums = new int[size];
        fillDownArray(nums, size);
        ss << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr, nums, size, ss);
        delete[] nums;
        nums = nullptr;
    }
    ss << "The end of test" << std::endl;
    ss << std::endl;
}

//void runTest(Function funcPtr_1, const std::vector<int>& data) {
//    std::cout << "Test for first algorithm" << std::endl;
//    variousCaseTest(funcPtr_1, data);
//}


void runTest(Function funcPtr_1, Function funcPtr_2, const std::vector<int>& data) {
    std::cout << "I.\tTEST FOR SELECTION SORT" << std::endl;
    std::stringstream ss1;
    std::thread t1(variousCaseTest, funcPtr_1, data, ss1);

    std::stringstream ss2;
    std::thread t2(grownCaseTest, funcPtr_1, data, ss2);

    std::stringstream ss3;
    std::thread t3(downCaseTest, funcPtr_1, data, ss3);


    std::cout << "II.\tTEST FOR BUBBLE SORT" << std::endl;
    std::stringstream ss4;
    std::thread t4(variousCaseTest, funcPtr_2, data, ss4);


    std::stringstream ss5;
    std::thread t5(grownCaseTest, funcPtr_2, data, ss5);


    std::stringstream ss6;
    std::thread t6(downCaseTest, funcPtr_2, data, ss6);

    t1.join();
    std::cout << ss1.str() << std::endl;
    t2.join();
    std::cout << ss2.str() << std::endl;
    t3.join();
    std::cout << ss3.str() << std::endl;
    t4.join();
    std::cout << ss4.str() << std::endl;
    t5.join();
    std::cout << ss5.str() << std::endl;
    t6.join();
    std::cout << ss6.str() << std::endl;

}
