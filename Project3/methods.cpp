#include "methods.h"
#include <iostream>

int delOtherMethod(char* x, int n, char key) {
    int countCmps = 0;
    int countMoves = 0;

    ++countMoves;
    //инициализация j
    int j = 0;
    //инициализация i
    ++countMoves;
    for (int i = 0; ++countCmps && i < n; ++i) {
        // присваивание 
        ++countMoves;
        x[j] = x[i];

        ++countCmps;
        if (x[i] != key) {
            // инкремент j
            ++countMoves;
            ++j;
        }
        // увеличение i
        ++countMoves;
    }

    ++countCmps;
    if (x[0] == key) {
        ++countMoves;
        x[j] = '\0';
        ++countMoves;
        n = 0;
    }
    else {
        ++countMoves;
        x[j] = '\0';
        ++countMoves;
        n = j;
    }
    std::cout << "\t\tC: " << countCmps << " ";
    std::cout << "\t\tM: " << countMoves << " ";
    std::cout << "\t\tT: " << countMoves + countCmps << " ";
    std::cout << std::endl;
    return n;
}

int delFirstMethod(char* x, int n, char key) {
    int countCmps = 0;
    int countMoves = 0;

    ++countMoves;
    int i = 0;

    while (++countCmps && i < n) {
        ++countCmps;
        if (x[i] == key) {
            // инициализация j
            ++countMoves;
            for (int j = i; ++countCmps && j < n-1; ++j) {
            // присваивание
                ++countMoves;
                x[j] = x[j + 1];
                //инкремент j
                ++countMoves;
            }
            // декремент n
            ++countMoves;
            --n;
        }
        else {
            // инкремент i
            ++countMoves;
            ++i;
        }
    }
    // окончание строки, ставим нулевой символ
    ++countMoves;
    x[n] = '\0';
    std::cout << "\t\tC: " << countCmps << " ";
    std::cout << "\t\tM: " << countMoves << " ";
    std::cout << "\t\tT: " << countMoves + countCmps << " ";
    std::cout << std::endl;
    return n;
}
