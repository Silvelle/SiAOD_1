#include "methods.h"
#include <iostream>

int delOtherMethod(char* x, int n, char key) {
    int countCmps = 0;
    int countMoves = 0;
    int j = 0;
    ++countCmps;
    for (int i = 0; i < n; ++i) {
        ++countCmps;
        ++countMoves;
        x[j] = x[i];
        ++countCmps;
        if (x[i] != key) {
            ++countCmps;
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
    return n;
}

int delFirstMethod(char* x, int n, char key) {
    int countCmps = 0;
    int countMoves = 0;
    int i = 0;
    ++countCmps;
    while (i < n) {
        ++countCmps;
        ++countCmps;
        if (x[i] == key) {
            ++countCmps;
            for (int j = i; j < n; ++j) {
                ++countCmps;
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

    return n;
}
