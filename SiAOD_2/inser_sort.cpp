#include "selection_sort.h"
#include <utility>
void selectionSort(int* a, int length) {
    for (int i = 0; i < length - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < length; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(a[i], a[min]);
        }
    }
}

void bubbleSort(int *a, int length) {
    for (int j = 1; j < length - 1; ++j) {
        for (int i = 0; i < length - 1 -j; ++i) {
            if (a[i] > a[i+1]) 
            {
                std::swap(a[i], a[i+1]);
            }
        }
    }
}