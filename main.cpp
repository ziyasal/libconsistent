
#include <iostream>
#include <thread>
#include "scopeguard/ScopeGuard.h"

using namespace std;

mutex mtx;

void print_thread_id(int id) {
    // critical section (exclusive access to std::cout signaled by locking mtx)
    mtx.lock();
    cout << "thread #" << id << '\n';
    mtx.unlock();
}

void deferredFunction() {
    cout << "i'm deferred" << endl;
}

int main() {

    DEFER(deferredFunction());

    std::thread threads[20];

    for (int i = 0; i < 20; ++i)
        threads[i] = std::thread(print_thread_id, i + 1);

    for (auto &th : threads) th.join();

    return 0;
}