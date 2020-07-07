#include <iostream>
#include <thread>

void func() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 1 in thread id: " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in thread id: " << std::this_thread::get_id() << std::endl;
}


int main() {
    std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;
    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "Cores available = " << nCores << std::endl;
    
    // create thread
    std::thread t(func);
    // wait for thread to finish
    //t.join();

    // detach thread and continue with main
    t.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Done work 1 in main" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Done work 2 in main" << std::endl;

    return 0;
}
