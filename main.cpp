#include <iostream>
#include <thread>
#include "Defer.h"

std::mutex mtx;

void print_thread_id(int id) {
    mtx.lock();
    std::cout << "thread #" << id << '\n';
    mtx.unlock();
}

void deferredFunction() {
    std::cout << "i'm deferred" << std::endl;
}

int main() {

    DEFER(deferredFunction());

    std::thread threads[20];

    for (int i = 0; i < 20; ++i)
        threads[i] = std::thread(print_thread_id, i + 1);

    for (auto &th : threads) th.join();

    return 0;
}
