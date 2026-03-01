#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex cout_mutex;

int func1(int n) {

    std::lock_guard<std::mutex> lock(cout_mutex);
    std::this_thread::sleep_for(std::chrono::milliseconds(15000));
    std::cout << "The first functions" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "1_1_test1" << std::endl;
        std::cout << "1_2_test1" << std::endl;
        std::cout << "1_3_test1" << std::endl;
    }
    
    return n;
}

int func2(int n) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "The second functions" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    for (int i = 0; i < n; ++i) {
        std::cout << "2_2_test1" << std::endl;
        std::cout << "2_3_test1" << std::endl;
        std::cout << "2_4_test1" << std::endl;
    }

    return n;
}

int main()
{
    auto start = std::chrono::steady_clock::now();
    std::thread  t1(func1, 10);
    t1.join();

    std::thread  t2(func2, 10);
    t2.join();

    
    auto end = std::chrono::steady_clock::now();
    const auto duration = end - start;
    std::cout << "\t\tTime: " << std::chrono::duration<double, std::milli>(duration).count() << " ms\n";

   return 0;
    
}

