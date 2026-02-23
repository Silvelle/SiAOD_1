#include <chrono>
#include <iostream>
#include <vector>
#include "effectiveness_tests.h"
#include "fill_array.h"

void measureTime(Function funcPtr, char* chr, int n, char key) {
    auto start = std::chrono::steady_clock::now();
    n = funcPtr(chr, n, key);
    auto end = std::chrono::steady_clock::now();

    const auto duration = end - start;
    std::cout << "\t\tTime: " << std::chrono::duration<double, std::milli>(duration).count() << " ms\n";
}


void worstCaseTest(Function funcPtr, const std::vector<int>& data) {
    std::cout << "Worst case: every character has been changed" << std::endl;
    for (int size : data) {
        char* chars = new char[size + 1];
        chars[size] = '\0';
        char key = 'a';
        fillArray(chars, size, key);
        std::cout << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr, chars, size, key);
        delete[] chars;
        chars = nullptr;
    }
    std::cout << "The end of test" << std::endl;
    std::cout << std::endl;
}

void mediumCaseBothTest(Function funcPtr_1, Function funcPtr_2, const std::vector<int>& data) {
    std::cout << "Medium case the half of symbols deleted: " << std::endl;
    for (int size : data) {
        char* chars = new char[size + 1];
        chars[size] = '\0';
        mediumfillArray(chars, size, 0, 9, '1');


        std::cout << "SIZE OF ARRAY: " << size << std::endl;
        std::cout << "FIRST ALGORITHM: " << std::endl;
        measureTime(funcPtr_1, chars, size, '1');
        std::cout << std::endl;
        std::cout << "SECOND ALGORITHM: " << std::endl;
        measureTime(funcPtr_2, chars, size, '1');

        delete[] chars;
        chars = nullptr;
    }
    std::cout << "The end of test" << std::endl;
    std::cout << std::endl;
}

void bestCaseTest(Function funcPtr_1, const std::vector<int>& data) {
    std::cout << "Best case: no one chars was deleted" << std::endl;
    for (int size : data) {
        char* chars = new char[size + 1];
        chars[size] = '\0';
        fillArray(chars, size, 'a');

        char key = 'a';
        std::cout << "SIZE OF ARRAY: " << size << std::endl;
        measureTime(funcPtr_1, chars, size, '1');
        delete[] chars;
        chars = nullptr;
    }
    std::cout << "The end of test" << std::endl;
    std::cout << std::endl;
}



void runTest(Function funcPtr_1, Function funcPtr_2, const std::vector<int>& data) {
    std::cout << "FIRST ALGORITHM: " << std::endl;
    worstCaseTest(funcPtr_1, data);

    std::cout << "SECOND ALGORITHM: " << std::endl;
    worstCaseTest(funcPtr_2, data);

    std::cout << "===" << std::endl;
    std::cout << "FIRST ALGORITHM: " << std::endl;
    bestCaseTest(funcPtr_1, data);
    std::cout << "SECOND ALGORITHM: " << std::endl;
    bestCaseTest(funcPtr_2, data);

    std::cout << "===" << std::endl;

    mediumCaseBothTest(funcPtr_1, funcPtr_2, data);
}
