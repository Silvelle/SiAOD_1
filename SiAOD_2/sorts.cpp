#include "sort_methods.h"
#include <utility>
#include <iostream>
void selectionSort(int* a, int length) {
    size_t countCmps = 0;     
    size_t countMoves = 0;    

    for (int i = 0; ++countCmps && i < length - 1; ++i) {
        countMoves++;          // инициализация i = 0
        countMoves++;          // инкремент i++

        int min = i;
        countMoves++;          // присваивание min = i

            countMoves++;      // инициализация j = i + 1
        for (int j = i + 1; ++countCmps && j < length; ++j) {
            countMoves++;      // инкремент j++

            countCmps++;       // сравнение a[j] < a[min]
            if (a[j] < a[min]) {
                min = j;
                countMoves++;  // присваивание min = j
            }
        }

        countCmps++;           // сравнение min != i
        if (min != i) {
            std::swap(a[i], a[min]);
            countMoves += 3;   // swap = 3 присваивания
        }
    }

    std::cout << "\t\tC: " << countCmps << " ";
    std::cout << "\t\tM: " << countMoves << " ";
    std::cout << "\t\tT: " << countMoves + countCmps << " ";
}

void bubbleSort(int* a, int length) {
    size_t countCmps = 0;
    size_t countMoves = 0;

        ++countMoves;               // инициализация j = 1
    for (int j = 1; ++countCmps && j < length - 1; ++j) {
        ++countMoves;               // инкремент j++

            ++countMoves;           // инициализация i = 0
        for (int i = 0; ++countCmps && i < length - 1 - j; ++i) {
            ++countMoves;           // инкремент i++

            ++countCmps;
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                countMoves += 3;    // swap = 3 присваивания
            }
        }
    }

    std::cout << "\t\tC: " << countCmps << " ";
    std::cout << "\t\tM: " << countMoves << " ";
    std::cout << "\t\tT: " << countMoves + countCmps << " ";
}