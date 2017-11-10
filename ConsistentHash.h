#ifndef LIBCONSISTENT_CONSISTENTHASH_H
#define LIBCONSISTENT_CONSISTENTHASH_H

#include <iostream>
#include <map>
#include <set>

using namespace std;

template<class T>
class ConsistentHash {

public:
    ConsistentHash();

    ~ConsistentHash();

    void Add(const T &node);

    void Remove(const T &node);
};


#endif //LIBCONSISTENT_CONSISTENTHASH_H
