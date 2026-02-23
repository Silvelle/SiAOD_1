#include <chrono>
#include <iostream>
#include "effectiveness_tests.h"
#include "fill_array.h"

void measureTime(Function funcPtr, char* chr, int n, char key) {
    auto start = std::chrono::steady_clock::now();
    n = funcPtr(chr, n, key);
    auto end = std::chrono::steady_clock::now();

    const auto duration = end - start;
    std::cout << "Time: " << std::chrono::duration<double, std::milli>(duration).count() << " ms\n";
}

void RunTest(Function funcPtr, int size, char typeOfTest) {
    char* chars = new char[size + 1];
    char key = 'a';
    switch (typeOfTest) {
    case 'a':
        std::cout << "Worst case: every character has been changed" << std::endl;
        fillArray(chars, size, key);
        measureTime(funcPtr, chars, size, key);
        break;
    case 'b':
        std::cout << "Medium case: the half of symbols has been changed" << std::endl;
        fillArray(chars, size);
        measureTime(funcPtr, chars, size, '1');
        break;
    case 'c':
        std::cout << "Doesnt change" << std::endl;
        fillArray(chars, size, key);
        measureTime(funcPtr, chars, size, 'z');
        break;
    }
}
