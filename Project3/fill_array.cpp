#include <iostream>
#include "fill_array.h"


void printChars(char* x, int n) {
    std::cout << "result str ";
    for (int i = 0; i < n; ++i) {
        std::cout << x[i];
    }
    std::cout << std::endl;
}

void fillArray(char* symbs, int SIZE) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        //symbs[i] = '0' + (rand() % 10);
        if (i % 2 == 0) {
            symbs[i] = '0';
        }
        else {
            symbs[i] = '1';
        }
    }
    symbs[SIZE] = '\0';
}

void fillArray(char* symbs, int SIZE, char key) {
    for (int i = 0; i < SIZE; ++i) {
        symbs[i] = key;
    }
}