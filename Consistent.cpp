
#include "Consistent.h"

Consistent::Consistent() {
    grade_list = new map<uint64_t, string>();
    sortedSet = new set<uint64_t>();
    loadMap = new map<string, Host *>();
}

Consistent::~Consistent() {
    delete grade_list;
    delete sortedSet;
    delete loadMap;
}

void Consistent::insert(string host)  {
    mtx.lock();



    mtx.unlock();
    /*

     	c.Lock()
	defer c.Unlock()

	h := c.hash(fmt.Sprintf("%s%d", host, 0))
	if _, ok := c.hosts[h]; ok {
		return
	}

	c.loadMap[host] = &Host{Name: host, Load: 0}
	for i := 0; i < replicationFactor; i++ {
		h := c.hash(fmt.Sprintf("%s%d", host, i))
		c.hosts[h] = host
		c.sortedSet = append(c.sortedSet, h)

	}
	// sort hashes ascendingly
	sort.Slice(c.sortedSet, func(i int, j int) bool {
		if c.sortedSet[i] < c.sortedSet[j] {
			return true
		}
		return false
	})

     */

}
