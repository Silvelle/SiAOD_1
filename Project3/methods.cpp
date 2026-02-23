#include "methods.h"
#include <iostream>

int delOtherMethod(char* x, int n, char key) {
    int countCmps = 0;
    int countMoves = 0;
    int j = 0;
    for (int i = 0; ++countCmps && i < n; ++i) {
        ++countMoves;
        x[j] = x[i];
        ++countCmps;
        if (x[i] != key) {
            ++j;
        }
    }
    ++countCmps;
    if (x[0] == key)
    {
        x[j] = '\0';
        n = 0;
    }
    else
    {
        x[j] = '\0';
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
    int i = 0;

    while (++countCmps && i < n) {
        ++countCmps;
        if (x[i] == key) {
            
            for (int j = i; ++countCmps && j < n; ++j) {
                ++countMoves;
                x[j] = x[j + 1];
            }
            --n;
        }
        else {
            ++i;
        }
    }
    std::cout << "\t\tC: " << countCmps << " ";
    std::cout << "\t\tM: " << countMoves << " ";
    std::cout << "\t\tT: " << countMoves + countCmps << " ";
    std::cout << std::endl;
    return n;
}
