#include <iostream>
#include <vector>
#include "fill_array.h"
#include "sort_methods.h"
#include "efficency.h"
#include "my_types.h"


int main() {
    std::vector<int> sizes = {
        100, 200, 500, 1000, 2000,
        5000, 10000, 100000,
        200000, 500000, 1000000
    };
    


    runTest(selectionSort, sizes);
    runTest2(selectionSort, sizes);
    runTest3(bubbleSort, sizes);
}