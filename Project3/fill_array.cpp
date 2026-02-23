#include <iostream>

#include "fill_array.h"


void printChars(char* x, int n) {
    std::cout << "result str ";
    for (int i = 0; i < n; ++i) {
        std::cout << x[i];
    }
    std::cout << std::endl;
}

void parseInt(char* symbs, int number) {
    int i = 0;
    bool is_negative = false;
    if (number < 0) {
        is_negative = true;
        number = -number;
    }

    if (number == 0) {
        symbs[i++] = '0';
    }

    while (number > 0) {
        symbs[i++] = '0' + (number % 10);
        number /= 10;
    }
    symbs[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = symbs[j];
        symbs[j] = symbs[i - 1 - j];
        symbs[i - 1 - j] = temp;
    }

    if (is_negative) {
        for (int j = i; j >= 0; --j) {
            symbs[j + 1] = symbs[j];
        }
        symbs[0] = '-';
        i++;
    }
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