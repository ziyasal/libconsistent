#ifndef LIBCONSISTENT_CONSISTENT_H
#define LIBCONSISTENT_CONSISTENT_H

#include <iostream>
#include <map>
#include <set>
#include "Host.h"

using namespace std;

//typedef std::map<std::string, Host*> HostMap;
//typedef std::pair<std::string, Host*> HostPair;

class Consistent {

public:
    Consistent();

    ~Consistent();

    void insert(string host);

private:
    map<uint64_t, string> *grade_list; //hosts     map[uint64]string
    set<uint64_t> *sortedSet;            //sortedSet []uint64
    map<string, Host *> *loadMap;         //loadMap   map[string]*Host

    uint64_t totalLoad;                 //totalLoad int64
    mutex mtx;
};


#endif //LIBCONSISTENT_CONSISTENT_H
