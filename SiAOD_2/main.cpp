#include <iostream>
#include <vector>
#include "fill_array.h"
#include "sort_methods.h"
#include "efficency.h"
#include "my_types.h"


int main() {
    std::vector<int> sizes = {
        10
    };
    
    runTest(bubbleSort, sizes);
}