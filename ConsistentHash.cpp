
#include "ConsistentHash.h"

using namespace std;

template<class T>
void ConsistentHash<T>::Add(const T &node) {

    cout << "Add" << endl;

}

template<class T>
void ConsistentHash<T>::Remove(const T &node) {
    cout << "Remove" << endl;

}

template<class T>
ConsistentHash<T>::ConsistentHash() = default;

template<class T>
ConsistentHash<T>::~ConsistentHash() = default;


