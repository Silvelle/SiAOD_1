#include <iostream>
#include <cassert>
#include "unit_tests.h"
#include "cstring"
#include "fill_array.h"
#include "unit_tests.h"
void TestFunc(Function funcPtr) {
    // Test 1 Найден символ
    {   // создаём строку, так как строка c-подобная, то длина + 1
        char* x = new char[6];
        // копируем нужный текст
        strcpy(x, "hello");
        int n = strlen(x);
        char key = 'e';

        n = funcPtr(x, n, key);
        assert(strcmp(x, "hllo") == 0);
        assert(n == 4);
        assert(x[n] == '\0');

        delete[] x;
    }
    // Test 2 Ничего не найдено
    {
        char* x = new char[6];
        strcpy(x, "hello");
        int n = strlen(x);
        char key = 'y';

        n = funcPtr(x, n, key);
        assert(strcmp(x, "hello") == 0);
        assert(n == 5);
        assert(x[n] == '\0');
        delete[] x;
    }
    // Test 3 удаление всех символов
    {
        char* x = new char[5];
        strcpy(x, "aaaa");
        int n = 4;
        char key = 'a';

        n = funcPtr(x, n, key);
        assert(strcmp(x, "") == 0);
        assert(x[n] == '\0');
        delete[] x;
    }

    std::cout << "Tests are OK" << std::endl;
}
void TestParse() {
    {
        int size = 10;
        char* chars = new char[size];
        parseInt(chars, 123456789);
        assert(strcmp(chars, "123456789") == 0);
        delete[] chars;
    }

    {
        int size = 2;
        char* chars = new char[size];
        parseInt(chars, -1);
        assert(strcmp(chars, "-1") == 0);
        assert(strlen(chars) == 2);
    }

}