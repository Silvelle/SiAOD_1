#include "sort_methods.h"
#include <utility>
#include <iostream>
void selectionSort(int* a, int length) {
    size_t countCmps = 0;
    size_t countMoves = 0;
    for (int i = 0; ++countCmps && i < length - 1; ++i) {
        int min = i;
        for (int j = i + 1; ++countCmps && j < length; ++j) {            
            countCmps++;
            if (a[j] < a[min]) {
                min = j;
            }
        }
        countCmps++;
        if (min != i) {
            countMoves += 3;
            std::swap(a[i], a[min]);
        }
    }
    std::cout << "\t\tC: " << countCmps << " ";
    std::cout << "\t\tM: " << countMoves << " ";
    std::cout << "\t\tT: " << countMoves + countCmps << " ";
}

void bubbleSort(int *a, int length) {
    int countCmps = 0;
    int countMoves = 0;
    for (int j = 1; ++countCmps && j < length - 1; ++j) {
        for (int i = 0; ++countCmps && i < length - 1 - j; ++i) {
            ++countCmps;
            if (a[i] > a[i+1]) 
            {
                countMoves += 3;
                std::swap(a[i], a[i+1]);
            }
        }
    }
    std::cout << "\t\tC: " << countCmps << " ";
    std::cout << "\t\tM: " << countMoves << " ";
    std::cout << "\t\tT: " << countMoves + countCmps << " ";
}