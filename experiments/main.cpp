#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <sstream>

std::mutex cout_mutex;

std::stringstream str;

int func1(int n) {

    std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    std::cout << "The first functions" << std::endl;
    for (int i = 0; i < n; ++i) {
        str << "1_1_test1" << std::endl;
        str << "1_2_test1" << std::endl;
        str << "1_3_test1" << std::endl;
    }
    
    return n;
}
std::stringstream str1;
int func2(int n) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::cout << "The second functions" << std::endl;
    for (int i = 0; i < n; ++i) {
        str1 << "2_2_test1" << std::endl;
        str1 << "2_3_test1" << std::endl;
        str1 << "2_4_test1" << std::endl;
    }

    return n;
}

int main()
{
    auto start = std::chrono::steady_clock::now();
    std::thread  t1(func1, 10);
    

    std::thread  t2(func2, 10);
    t1.join();
    std::cout << str.str() << std::endl;
    t2.join();
    std::cout << str1.str() << std::endl;

    
    auto end = std::chrono::steady_clock::now();
    const auto duration = end - start;
    std::cout << "\t\tTime: " << std::chrono::duration<double, std::milli>(duration).count() << " ms\n";

   return 0;
    
}

