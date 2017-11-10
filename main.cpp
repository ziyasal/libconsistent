
#include <iostream>
#include <thread>

#define CONCAT_(a, b) a ## b
#define CONCAT(a, b) CONCAT_(a,b)
#define DEFER(fn) ScopeGuard CONCAT(__defer__, __LINE__) = [&] ( ) { fn ; }

using namespace std;

class ScopeGuard {
public:
    template<class Callable>
    ScopeGuard(Callable &&fn) : fn_(std::forward<Callable>(fn)) {}

    ScopeGuard(ScopeGuard &&other) : fn_(std::move(other.fn_)) {
        other.fn_ = nullptr;
    }

    ~ScopeGuard() {
        // must not throw
        if (fn_) fn_();
    }

    ScopeGuard(const ScopeGuard &) = delete;

    void operator=(const ScopeGuard &) = delete;

private:
    std::function<void()> fn_;
};


mutex mtx;

void print_thread_id(int id) {
    // critical section (exclusive access to std::cout signaled by locking mtx)
    mtx.lock();
    cout << "thread #" << id << '\n';
    mtx.unlock();
}

void deferredFunction(){
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