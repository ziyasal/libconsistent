#include <iostream>
#include <utility>

#ifndef LIBCONSISTENT_SCOPEGUARD_H
#define LIBCONSISTENT_SCOPEGUARD_H


#define CONCAT_(a, b) a ## b
#define CONCAT(a, b) CONCAT_(a,b)
#define DEFER(fn) Defer CONCAT(__defer__, __LINE__) = [&] ( ) { fn ; }

class Defer {
public:
    template<class Callable>
    Defer(Callable &&func) : f(std::forward<Callable>(func)) {}

    Defer(Defer &&other) : f(std::move(other.f)) { other.f = nullptr; }

    ~Defer() { try { if (f) f(); } catch (...) {/*catch all*/}}

    Defer(const Defer &) = delete;

    void operator=(const Defer &) = delete;

private:
    std::function<void()> f;
};


#endif //LIBCONSISTENT_SCOPEGUARD_H
