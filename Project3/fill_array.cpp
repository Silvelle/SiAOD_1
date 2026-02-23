#include <iostream>

#include "fill_array.h"


void printChars(char* x, int n) {
    std::cout << "result str ";
    for (int i = 0; i < n; ++i) {
        std::cout << x[i];
    }
    std::cout << std::endl;
}



void mediumfillArray(char* symbs, int SIZE, int min, int max, char key) {
    int keyCount = SIZE / 2;

    for (int i = 0; i < keyCount; ++i)
        symbs[i] = key;

    for (int i = keyCount; i < SIZE; ++i)
        symbs[i] = '0' + (rand() % (max - min + 1) + min);

    for (int i = 0; i < SIZE; ++i) {
        int j = rand() % SIZE;
        char temp = symbs[i];
        symbs[i] = symbs[j];
        symbs[j] = temp;
    }

    symbs[SIZE] = '\0';
}

void fillArray(char* symbs, int SIZE, int min, int max) {
    for (int i = 0; i < SIZE; ++i) {
        int value = rand() % (max - min + 1) + min;
        symbs[i] = '0' + value;
    }

    symbs[SIZE] = '\0';
}

void fillArray(char* symbs, int SIZE, char key) {
    for (int i = 0; i < SIZE; ++i) {
        symbs[i] = key;
    }
    symbs[SIZE] = '\0';
}