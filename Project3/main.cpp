#include <iostream>
#include <cassert>
#include <cstring>
#include <random>
#include <ctime>
#include <chrono>
#include <vector>

#include "methods.h"
#include "fill_array.h"
#include "unit_tests.h"
#include "effectiveness_tests.h"

int main() {
    std::vector<int> sizes = { 100, 200, 500, 1000, 2000, 5000, 10000 };



}

#if 0
std::cout << "The first algorithm===================" << std::endl;

for (int SIZE : sizes) {
    std::cout << "THE SIZE: " << SIZE << std::endl;
    RunTest(delFirstMethod, SIZE, 'a');
    RunTest(delFirstMethod, SIZE, 'b');
    RunTest(delFirstMethod, SIZE, 'c');
    std::cout << std::endl;
}

std::cout << "The second algorithm====================" << std::endl;

for (int SIZE : sizes) {
    std::cout << "THE SIZE: " << SIZE << std::endl;
    RunTest(delOtherMethod, SIZE, 'a');
    RunTest(delOtherMethod, SIZE, 'b');
    RunTest(delOtherMethod, SIZE, 'c');
    std::cout << std::endl;
}
#endif 0

#if 0
int countCmps;
int countMoves;

std::cout << "WROST CASE" << std::endl;
std::cout << "str: " << *ptr << "key = " << key << std::endl;
std::cout << "Started len: " << SIZE << std::endl;
SIZE = delFirstMethod(ptr, 6, key, countCmps, countMoves);
std::cout << "Amount of comprasions: " << countCmps << std::endl;
std::cout << "Amount of memory moves: " << countMoves << std::endl;
std::cout << "Amount of critical movments: " << countMoves + countCmps << std::endl;
std::cout << "Result size: " << SIZE << std::endl;

printChars(ptr, SIZE);

std::cout << std::endl;
//std:: cin >> n;
strcpy(ptr, "hello!");
key = 'y';
std::cout << "BEST CASE" << std::endl;
std::cout << "str: " << *ptr << "key = " << key << std::endl;
std::cout << "Started len " << SIZE << std::endl;
SIZE = delFirstMethod(ptr, 6, key, countCmps, countMoves);
std::cout << "Amount of comprasions: " << countCmps << std::endl;
std::cout << "Amount of memory moves: " << countMoves << std::endl;
std::cout << "Result size " << SIZE << std::endl;

printChars(ptr, SIZE);

std::cout << std::endl;

strcpy(ptr, "abacad");
key = 'a';
SIZE = 6;
std::cout << "AVERAGE CASE" << std::endl;
std::cout << "str: " << *ptr << "key = " << key << std::endl;
std::cout << "Started len " << SIZE << std::endl;
SIZE = delFirstMethod(ptr, 6, key, countCmps, countMoves);
std::cout << "Amount of comprasions: " << countCmps << std::endl;
std::cout << "Amount of memory moves: " << countMoves << std::endl;
std::cout << "Amount of critical movments: " << countMoves + countCmps << std::endl;
std::cout << "Result size: " << SIZE << std::endl;

printChars(ptr, SIZE);
std::cout << std::endl;
#endif

#if 0 
void TestFunc() {
    // Test 1              
    {   //              ,                c-        ,          + 1
        char* x = new char[6];
        //                      
        strcpy(x, "hello");
        int n = strlen(x);
        char key = 'e';

        n = delFirstMethod(x, n, key);
        assert(strcmp(x, "hllo") == 0);
        assert(n == 4);
        assert(x[n] == '\0');

        delete[] x;
    }
    // Test 2                  
    {
        char* x = new char[6];
        strcpy(x, "hello");
        int n = strlen(x);
        char key = 'y';

        n = delFirstMethod(x, n, key);
        assert(strcmp(x, "hello") == 0);
        assert(n == 5);
        assert(x[n] == '\0');
        delete[] x;
    }
    // Test 3                       
    {
        char* x = new char[5];
        strcpy(x, "aaaa");
        int n = 4;
        char key = 'a';

        n = delFirstMethod(x, n, key);
        assert(strcmp(x, "") == 0);
        assert(x[n] == '\0');
        delete[] x;
    }

    std::cout << "Tests are OK" << std::endl;
}
#endif 0